#include "Player.h"
#include "DxLib.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "Screen.h"
#include "../ImGui/imgui.h"
#include "Shield.h"
#include "Enemy.h"
#include "GroundEnemy1.h"
#include "GroundEnemy2.h"
#include "SkyEnemy1.h"
#include "SkyEnemy2.h"
#include "Stage.h"


//ジャンプゲーム作るとき便利
const float Gravity = 0.5f;
const float JumpHeight = 64;
const float V0 = -sqrtf(2.0f * Gravity * JumpHeight);
          //V0は初速


Player::Player()
{
	//aliveImage = LoadGraph("data/run1.png");
	deadImage = LoadGraph("data/dead.jpeg");
	hImage = LoadGraph("data/player.png");

	position.x = 120;
	position.y = 575;
	startposition = position;
	patternX = 0;
	patternY = 0;
	freamcounter = 0;

	jumpCount = 0;  //ジャンプ回数の初期化
	ground = 575;   //地面の位置
	grounded = true;//地面にいる状態
	maxJump = 2;   //最大ジャンプ回数
	jumpPower = 10;//ジャンプ力
	velocityY = 0; //Y方向の速度

	prevSpaceKeyState = false;  //最初はスペースキーが押されていない
	isActivePlayer = true;
	isDead = false;  //プレイヤーが死んだかどうか
	bool isWalk = true;

	int width, height;
	GetGraphSize(hImage, &width, &height);
	centerPosition = VECTOR2(width / 2, height / 2);
}

Player::~Player()
{
	//DeleteGraph(hImage);
}



void Player::Update()
{
	Stage* s = FindGameObject<Stage>();

	s->scroll += 2;
	position.x += 2.1f;
	int push = 0;
	push = s->IsWallRight(position + VECTOR2(63, 0));
	position.x -= push;
	push = s->IsWallRight(position + VECTOR2(63, 63));
	position.x -= push;

	//Y座標の更新（垂直移動）
	position.y -= velocityY;


	//地面にいない時だけ重力を適用
	if(!grounded){
		velocityY -= Gravity;//重力で下に引っ張る
	}

	
	//地面に着地した時の処理
	//if (position.y >= ground) {
	//	position.y = ground;  //地面に着地
	//	velocityY = 0;        //Yの速度0にする
	//	grounded = true;      //地面に接した状態
	//	jumpCount = 0;        //ジャンプ回数をリセット
	//	onGround = true;
	//}

	if (velocityY <= 0) {
		int push1 = s->IsWallDown(position + VECTOR2(0, 64));
		int push2 = s->IsWallDown(position + VECTOR2(63, 64));
		if (push1 > 0 || push2 > 0) {
			position.y -= max(push1, push2) - 1;
			velocityY = 0;        //Yの速度0にする
			grounded = true;      //地面に接した状態
			jumpCount = 0;        //ジャンプ回数をリセット
			onGround = true;
		} else {
			grounded = false;      //地面に接した状態
			onGround = false;
		}
	} else {
		int push1 = s->IsWallUp(position + VECTOR2(0, 0));
		int push2 = s->IsWallUp(position + VECTOR2(63, 0));
		if (push1 > 0 || push2 > 0) {
			position.y += max(push1, push2);
			velocityY = 0;        //Yの速度0にする
		}
	}

	//スペースキーが押された瞬間だけ反応させる
	bool currentSpaceKeyState = CheckHitKey(KEY_INPUT_SPACE);
	if (currentSpaceKeyState && !prevSpaceKeyState) {
		if (grounded  || jumpCount < maxJump) {//地面にいるか、ジャンプ回数が残っていれば
			Jump();
		}	
	}

	//前回のスペースキーの状態を更新
	prevSpaceKeyState = currentSpaceKeyState;


	std::list<Enemy*>enemis = FindGameObjects<Enemy>();//すべての敵オブジェクトがEnemy*として格納される
	std::list<Shield*> shield = FindGameObjects<Shield>();
	std::list<GroundEnemy1*>groundenemy1 = FindGameObjects< GroundEnemy1>();
	std::list<GroundEnemy2*>groundenemy2 = FindGameObjects< GroundEnemy2>();
	std::list<SkyEnemy1*>skyenemy1 = FindGameObjects< SkyEnemy1>();
	std::list<SkyEnemy2*>skyenemy2 = FindGameObjects< SkyEnemy2>();

	for (Enemy* enemy : enemis) 
	{
		VECTOR2 enemyPos = enemy->getPosition();  // 各敵の位置を取得
		//int width, height;
		//GetGraphSize(aliveImage, &width, &height);
		//VECTOR2 playerPos = { position.x + centerPosition.x, position.y + centerPosition.x };//画像の中心座標,プレイヤーの位置を取得
		VECTOR2 playerPos = GetCenterPosition();//画像の中心座標,プレイヤーの位置を取得

		if (CircleHit(playerPos, enemyPos, 48))//プレイヤーと敵が当たったら
		{
			{
  				int count = 0;//プレイヤーが持ってない盾の数の初期化

				 for (Shield* sh : shield)
				{
					if (sh->isShield)//プレイヤーが盾を所持している時
					{
						sh->DestroyMe();//盾だけ消える(シールド無効化)
						enemy->DestroyMe();
						break;
					}

					count++;

					//	ゲーム中に盾はあるがプレイヤーは持ってない
					if (count >= shield.size())
					{
						//プレイヤーが盾を所持していない場合
						isDead = true; //プレイヤーが死んだことを記録
						DestroyMe();  //プレイヤー削除.死んだ絵に変えるプレイヤーの移動量は死んだときに0にしてとまる	
						break;
					}
				}
				 if (shield.size() == 0)
				 {
					 //プレイヤーが盾を所持していない場合
					 isDead = true; //プレイヤーが死んだことを記録
					 DestroyMe();  //プレイヤー削除.死んだ絵に変えるプレイヤーの移動量は死んだときに0にしてとまる	
				 }
			}
		}
	}
	
	if (isDead) {
		//プレイヤーが死んだら移動しない
		return;
	}
	
	if (isWalk) {//歩いてるとき
		freamcounter += 1;
		if (freamcounter % 7 == 0) {       //10フレームに一回画像出せる
			patternX = (patternX + 1) % 2;  //patternXが0，1の後、0にする
		}
	}
}

void Player::Draw()
{
	Stage* s = FindGameObject<Stage>();

	if (isDead) {
		//死んだときの画像を描画
		DrawGraph(position.x - s->scroll , position.y, deadImage, TRUE);
	}
	else {
		//生きている時の画像を描画
	    //DrawGraph(position.x - s ->scroll, position.y, hImage, TRUE);
	
						  // x,   y , 高さ, 幅
		DrawRectGraph(position.x - s->scroll, position.y, patternX*64, patternY*64, 64, 64, hImage, TRUE);
		//DrawRectGraph(position.x , position.y, 0, 0, 64, 64, hImage, TRUE);

	}

	 	
	//	debug
	int width, height;
	GetGraphSize(hImage, &width, &height);
	VECTOR2 playerPos = GetCenterPosition();//画像の中心座標,プレイヤーの位置を取得
	DrawCircle(playerPos.x - s->scroll, playerPos.y, 32, RGB(0, 0, 0), 0);//当たり判定を左上じゃなくて中心を基準にする
	
}

void Player::DestroyMe()
{
	isActivePlayer = false;
	//プレイヤーのリストから削除
	//delete this;//メモリを解放
}


//ジャンプ処理
void Player::Jump()
{
	velocityY = jumpPower; //上方向に力を加える
	jumpCount++;		   //ジャンプ回数を増やす
	grounded = false;      //ジャンプ中は地面にいないのでfalse

}


//プレイヤーが地面にいるかの確認
bool Player::isOnGround() const
{
	return grounded;
}

VECTOR2 Player::GetCenterPosition()
{
	VECTOR2 playerPos = { position.x  + 32, position.y + 32 };//画像の中心座標,プレイヤーの位置を取得
	return playerPos;
	
}
