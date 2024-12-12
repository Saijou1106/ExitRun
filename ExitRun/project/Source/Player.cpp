#include "Player.h"
#include "DxLib.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "Screen.h"
#include "../ImGui/imgui.h"

//ジャンプゲーム作るとき便利
const float Gravity = 0.4f;
const float JumpHeight = 64;
const float V0 = -sqrtf(2.0f * Gravity * JumpHeight);
          //V0は初速


Player::Player() 
{
	hImage = LoadGraph("data/run1.png");
	position.x = 120;
	position.y = 500;
	jumpCount = 0;  //ジャンプ回数の初期化
	ground = 500;   //地面の位置
	grounded = true;//地面にいる状態
	maxJump = 2;   //最大ジャンプ回数
	jumpPower = 8;//ジャンプ力
	velocityY = 0; //Y方向の速度

	prevSpaceKeyState = false;  //最初はスペースキーが押されていない
}



void Player::Update()
{

	//Y座標の更新（垂直移動）
	position.y -= velocityY;


	//地面にいない時だけ重力を適用
	if(!grounded){
		velocityY -= Gravity;//重力で下に引っ張る
	}

	
	//地面に着地した時の処理
	if (position.y >= ground) {
		position.y = ground;  //地面に着地
		velocityY = 0;        //Yの速度0にする
		grounded = true;      //地面に接した状態
		jumpCount = 0;        //ジャンプ回数をリセット
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
}

void Player::Draw()
{
	
	//DrawBox(playerX - 16, playerY - 16, playerX + 16, playerY + 16, GetColor(255, 255, 255), TRUE);
	DrawGraph(position.x, position.y, hImage, TRUE);
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
