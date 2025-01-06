#pragma once
#include "../Library/GameObject.h"
#include "Vector2.h"
#include "Shield.h" 

class Player : public GameObject
{
private:
	
	
	const float Gravity = 0.5f; //重力
	float velocityY;	         //Y方向の速度(垂直方向)
	float ground;                //地面の座標
	     
	int maxJump;                 //最大ジャンプ回数（２回）
	int jumpCount;		         //現在のジャンプ回数
	int jumpPower;               //ジャンプ力

	int aliveImage;               //生存画像
	int deadImage;                //死亡画像

	bool grounded;                //地面に接しているかどうか
	bool prevSpaceKeyState;       //前回スペースキーが押されているか
	       
	bool isFollowingPlayer;  // 盾がプレイヤーに追従しているかのフラグ
	bool isActivePlayer; 

	VECTOR2 centerPosition;

public:
	Player();
	VECTOR2 position;
	void Update();
	void Jump();//ジャンプ処理
	void Draw();
	void DestroyMe();
	bool isOnGround()const;//地面にいるかどうかを確認
	bool isDead;    //プレイヤーが死んだかどうか
	float velocity;//速度
	
	VECTOR2 startposition;
	
	VECTOR2 GetCenterPosition() { 
		VECTOR2 playerPos = { position.x + centerPosition.x, position.y + centerPosition.x };//画像の中心座標,プレイヤーの位置を取得
		return playerPos;
	};

};


