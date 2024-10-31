#pragma once
#include "../Library/GameObject.h"

class Player : public GameObject
{
private:
	int playerX;		//プレイヤーのX座標
	int playerY;		//プレイヤーのY座標
	float velocityY;	//Y方向の速度(垂直方向)
	int ground;         //地面の座標
	bool grounded;      //地面にいるかどうか
	int maxJump;        //最大ジャンプ回数（２回）
	int jumpCount;		//現在のジャンプ回数
	int jumpPower;      //ジャンプ力
	int gravity;		//重力

	int hImage;//画像

public:
	Player();

	void Update();
	void Draw();
	void Jump();//ジャンプ処理
	void onGround();//地面にいることをセット
	bool isOnGround()const;//地面にいるかどうかを確認


};


