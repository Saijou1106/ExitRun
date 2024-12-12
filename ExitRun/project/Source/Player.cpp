#include "Player.h"
#include "DxLib.h"
#include "TitleScene.h"
#include "PlayScene.h"


Player::Player() 
{
	hImage = LoadGraph("data/run1.png");
	playerX = 120;
	playerY = 200;
	jumpCount = 0;
	ground = 200;
	grounded = true;
	maxJump = 2;   //最大ジャンプ回数
	jumpPower = 5;//ジャンプ力
	gravity = 1;   //重力
	velocityY = 0; //Y方向の速度

}



void Player::Update()
{

	//Y座標の更新（上に動かすために減算）
	playerY -= velocityY;


	//初期状態では重力を適用しない
	//if (grounded) {
		//velocityY = 0; //地面にいる時は速度を0に設定
	//}
	

	//地面にいない時だけ重力を適用
	if(!grounded){
		velocityY -= gravity;
	}

	
	//地面に着地した時の処理
	if (playerY >= ground) {
		playerY = ground;
		velocityY = 0; //Yの速度0にする
		onGround();
	}

	//スペースキーでジャンプ
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		//地面にいるか、ジャンプ回数が１回のとき
		if (grounded || (jumpCount <= maxJump)) {
			Jump();//ジャンプ処理
		}
		
	}
//ジャンプ2回したらそれ以上ジャンプできないようにする
	if (jumpCount >= maxJump) {
		jumpCount = maxJump;
	}



	
	//地面にいないとき（ジャンプ中）にジャンプカウントが1だったらもう一度ジャンプできる
	
}

void Player::Draw()
{
	//プレイヤーを矩形で表現（座標：　x, y, サイズ：32×32）
	//DrawBox(playerX - 16, playerY - 16, playerX + 16, playerY + 16, GetColor(255, 255, 255), TRUE);
	DrawGraph(playerX, playerY, hImage, TRUE);
}

//ジャンプ処理
void Player::Jump()
{
	velocityY = jumpPower; //上方向に力を加える
	jumpCount++;		   //ジャンプ回数を増やす
	grounded = false;      //ジャンプ中は地面にいないのでfalse

}

//地面にいることをセット
void Player::onGround()
{
	grounded = true;
	jumpCount = 0; //地面にいたらジャンプ回数リセット
}

//プレイヤーが地面にいるかの確認
bool Player::isOnGround() const
{
	return grounded;
}
