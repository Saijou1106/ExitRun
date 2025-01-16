#include "Player.h"
#include "DxLib.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "Screen.h"
#include "Stage.h"
#include "../ImGui/imgui.h"
#include "Shield.h"
#include "Enemy.h"
#include "GroundEnemy1.h"
#include "GroundEnemy2.h"
#include "SkyEnemy1.h"
#include "SkyEnemy2.h"
#include "Stage.h"
#include "GameManager.h"
#include "GameOver.h"
#include "Object1.h"
#include "../ImGui/imstb_rectpack.h"



//ジャンプゲーム作るとき便利
const float Gravity = 0.5f;
const float JumpHeight = 64;
const float V0 = -sqrtf(2.0f * Gravity * JumpHeight);
          //V0は初速


Player::Player()
{

	deadImage = LoadGraph("data/dead.png");
	hImage = LoadGraph("data/player1.png");
	jumpUpImage = LoadGraph("data/JumpUp.png");
	jumpDownImage = LoadGraph("data/JumpDown.png");

	position.x = 100;
	position.y = 500;
	startposition.x = 100;

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

	
	isJumpDown = false;
	isJumpUp = false;
	bool isWalk = false;


	int width, height;
	GetGraphSize(hImage, &width, &height);
	centerPosition = VECTOR2(width / 2, height / 2);

	timer = 0.0f;

}


Player::~Player()
{
	//DeleteGraph(hImage);
}



void Player::Update()
{

	Stage* s = FindGameObject<Stage>();

	s->scroll += 2;

	GameManager* gm = FindGameObject<GameManager>();

	if (gm->playable) {
		s->scroll += 2;

		position.x += 1.0f;
		//Y座標の更新（垂直移動）
		position.y -= velocityY;


		//地面にいない時だけ重力を適用
		if (!grounded) {
			velocityY -= Gravity;//重力で下に引っ張る
			if (velocityY > 0.0f) {
				//上昇中
				isJumpUp = true;
				isJumpDown = false;
				isWalk = false;
			}
			else {
				isJumpUp = false;
				isJumpDown = true;
				isWalk = false;
			}


		}

		//地面に着地した時の処理
		if (position.y >= ground) {
			isWalk = true;
			position.y = ground;  //地面に着地
			velocityY = 0;        //Yの速度0にする
			grounded = true;      //地面に接した状態
			jumpCount = 0;        //ジャンプ回数をリセット
		}


		//スペースキーが押された瞬間だけ反応させる
		bool currentSpaceKeyState = CheckHitKey(KEY_INPUT_SPACE);
		if (currentSpaceKeyState && !prevSpaceKeyState) {
			if (grounded || jumpCount < maxJump) {//地面にいるか、ジャンプ回数が残っていれば
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
		VECTOR2 playerPos = GetCenterPosition();//画像の中心座標,プレイヤーの位置を取得

		std::list<Enemy*>enemis = FindGameObjects<Enemy>();//すべての敵オブジェクトがEnemy*として格納される
		std::list<Shield*> shield = FindGameObjects<Shield>();
		std::list<GroundEnemy1*>groundenemy1 = FindGameObjects< GroundEnemy1>();
		std::list<GroundEnemy2*>groundenemy2 = FindGameObjects< GroundEnemy2>();
		
		std::list<SkyEnemy2*>skyenemy2 = FindGameObjects< SkyEnemy2>();


		for (Enemy* enemy : enemis)
		{
			VECTOR2 enemyPos = enemy->getPosition();  // 各敵の位置を取得
			VECTOR2 playerPos = GetCenterPosition();//画像の中心座標,プレイヤーの位置を取得

			if (CircleHit(playerPos, enemyPos, 48))//プレイヤーと敵が当たったら
			{
				int count = 0;//プレイヤーが持ってない盾の数の初期化

				for (Shield* sh : shield)
				{
					if (sh->isShield)//プレイヤーが盾を所持している時
					{
						//敵を踏んだ場合
						if (playerPos.y < enemyPos.y)
						{
							if (velocityY < 0.0f)
							{
								Jump();
								velocityY = jumpPower / 1.1; //敵を踏んだ時の上に跳ねる高さ
								grounded = false;
								isDead = false;
								enemy->DestroyMe();
								break;
							}
						}
						//敵を踏む以外(不通に当たったら)で敵に触れたらシールドが消える
						else {
				    		sh->DestroyMe();//盾だけ消える(シールド無効化)
							enemy->DestroyMe();
							break;
						}
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

					if (shield.size() == 0)
					{
						//プレイヤーが盾を所持していない場合
						isDead = true; //プレイヤーが死んだことを記録
						DestroyMe();  //プレイヤー削除.死んだ絵に変えるプレイヤーの移動量は死んだときに0にしてとまる	
					}
				}

				if (playerPos.y < enemyPos.y) {
					if (velocityY < 0.0f)
					{
						jumpCount = 1;
						velocityY = jumpPower / 1.1; //敵を踏んだ時の上に跳ねる高さ
						grounded = false;
						isDead = false;
						enemy->DestroyMe();
						break;
					}
				}

			}
		}
	}
	
	if (isDead) {
		//プレイヤーが死んだら移動しない
		return;
	}
	
		
	if (isDead) {
		//timer += 0.15f;
		isWalk = false;
		isJumpUp = false;
		isJumpDown = false;
	}

		if (isWalk) {//歩いてるとき
			freamcounter += 1;
			if (freamcounter % 10 == 0) {       //10フレームに一回画像出せる
				patternX = (patternX + 1) % 4;  //patternXが0，1の後、0にする
			}
			isJumpUp = false;
			isJumpDown = false;
		}

		std::list<Object1*>object = FindGameObjects< Object1>();

			//とげの判定
			for (Object1* ob : object)
			{
				VECTOR2 playerPos = GetCenterPosition();
				VECTOR2 objectPos = ob->getObjectPosition();

				if (CircleHit(playerPos, objectPos, 48))
				{
					for (Shield* sh : shield)
					{
						sh->DestroyMe();
					}
					isDead = true; //とげに触れたらシールドを持っていてもいなくてもプレイヤーは死亡
					DestroyMe();
					break;
				}

			}
	}
}

void Player::Draw()
{
	if (isDead) {
		//死んだときの画像を描画
		DrawGraph(position.x, position.y, deadImage, TRUE);
		Instantiate<GameOver>();
	}
	if(isWalk) {
		//生きている時の画像を描画
						  // x,   y , 高さ, 幅
		DrawRectGraph(position.x , position.y, patternX*64, patternY*64, 64, 64, hImage, TRUE);
		//DrawRectGraph(position.x , position.y, 0, 0, 64, 64, hImage, TRUE);

	}

						  // x,   y , 高さ, 幅
		DrawRectGraph(position.x , position.y, patternX*64, patternY*64, 64, 64, hImage, TRUE);
		//DrawRectGraph(position.x , position.y, 0, 0, 64, 64, hImage, TRUE);
	
	if (isJumpUp) {
		//上昇中に画面切り替え
		DrawGraph(position.x ,position.y, jumpUpImage, TRUE);
	}
	if (isJumpDown) {
		//下降中に画面切り替え
		DrawGraph(position.x, position.y, jumpDownImage, TRUE);
	}

	

	 	
	//	debug
	int width, height;
	GetGraphSize(hImage, &width, &height);
	VECTOR2 playerPos = GetCenterPosition();//画像の中心座標,プレイヤーの位置を取得
	//DrawCircle(playerPos.x , playerPos.y, 32, RGB(0, 0, 0), 0);//当たり判定を左上じゃなくて中心を基準にする
	
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
