#include "Player.h"
#include "DxLib.h"

int main() {

}
Player::Player() // : playerX(320), playerY(240), jumpCount(0), grounded(true), maxJump(2),jumpPower(-15), gravity(1)
{
	playerX = 320;
	playerY = 240;
	jumpCount = 0;
	grounded = true;
	maxJump = 2;
	jumpPower = -15;
	gravity = 1;

}



void Player::Update()
{
	//スペースキーでジャンプ
	if (CheckHitKey(KEY_INPUT_SPACE) && jumpCount < maxJump) {
		Jump();
	}

	//重力を適用
	velocityY += gravity;
	playerY = velocityY;

	//地面に着地した時の処理(仮にY座標400が地面だとして)
	if (playerY >= 400) {
		playerY = 400;
		velocityY = 0;
		onGround();
	}

	//地面にいないときはジャンプ回数を制御
	if (!isOnGround()) {
		grounded = false;
	}
}

void Player::Draw()
{
	//プレイヤーを矩形で表現（座標：　x, y, サイズ：32×32）
	DrawBox(playerX - 16, playerY - 16, playerX + 16, playerY + 16, GetColor(255, 255, 255), TRUE);
}

//ジャンプ処理
void Player::Jump()
{
	velocityY = jumpPower; //ジャンプ力を速度に反映
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
