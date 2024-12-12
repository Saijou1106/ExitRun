#pragma once
#include "../Library/GameObject.h"
#include "Vector2.h"

class Player : public GameObject
{
private:
	
	float velocityY;	         //Y方向の速度(垂直方向)
	float ground;                //地面の座標
	     
	int maxJump;                 //最大ジャンプ回数（２回）
	int jumpCount;		         //現在のジャンプ回数
	int jumpPower;               //ジャンプ力

	int hImage;                   //画像

	bool grounded;                //地面に接しているかどうか
	bool prevSpaceKeyState;       //前回スペースキーが押されているか

public:
	Player();
	VECTOR2 position;
	void Update();
	void Jump();//ジャンプ処理
	void Draw();
	bool isOnGround()const;//地面にいるかどうかを確認

	float velocity;//速度
	
	
	
	


};


