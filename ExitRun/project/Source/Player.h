#pragma once
#include "../Library/GameObject.h"
#include "Vector2.h"
#include "Shield.h" 
#include <math.h>


class Player : public GameObject
{

public:
	Player();
	~Player();
	VECTOR2 position;

	void Update();
	void Jump();//ジャンプ処理
	void Draw();
	void DestroyMe();
	bool isOnGround()const;//地面にいるかどうかを確認
	bool isDead;    //プレイヤーが死んだかどうか
	float velocity;//速度

	bool isJumpUp; //上昇中
	bool isJumpDown;//下降中
	int jumpUpImage;
	int jumpDownImage;

	

	const float Gravity = 0.5f; //重力
	float velocityY;	         //Y方向の速度(垂直方向)
	float ground;                //地面の座標

	int maxJump;                 //最大ジャンプ回数（２回）
	int jumpCount;		         //現在のジャンプ回数
	int jumpPower;               //ジャンプ力
	bool isWalk;

	int aliveImage;               //生存画像
	int deadImage;                //死亡画像
	int hImage;

	int patternX;				//表示パターン(アニメーションの絵)の横の番号
	int patternY;				//表示パターンの縦の番号	

	int freamcounter;			


	bool grounded;              //地面に接しているかどうか
	bool prevSpaceKeyState;     //前回スペースキーが押されているか

	bool isFollowingPlayer;  // 盾がプレイヤーに追従しているかのフラグ
	bool isActivePlayer;


	float timer;
	//const float maxTimer = 3.0f;

	VECTOR2 centerPosition;
	VECTOR2 GetCenterPosition();
	VECTOR startposition; // startposition
};


