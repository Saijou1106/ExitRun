#pragma once
#include "../Library/GameObject.h"
#include "Vector2.h"
#include "Shield.h" 

class Player : public GameObject
{

public:
	Player();
	~Player();
	VECTOR2 position;
	VECTOR2 startposition;
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
	int shieldImage;
	int EnemyIsDeadImage;

	int jumpSound;               //ジャンプサウンド

	int patternX;				//表示パターン(アニメーションの絵)の横の番号
	int patternY;				//表示パターンの縦の番号	

	int freamcounter;			

	bool onGround;              //地面にいる状態
	bool grounded;              //地面に接しているかどうか
	bool prevSpaceKeyState;     //前回スペースキーが押されているか

	bool isFollowingPlayer;  // 盾がプレイヤーに追従しているかのフラグ
	bool isActivePlayer;
	int hitSoundhandle;

	void SetHitSoundHandle(int handle) { hitSoundhandle = handle; }
	void SetjumpSound(int handle) { jumpSound = handle; }

	VECTOR2 centerPosition;
	VECTOR2 GetCenterPosition();
private:
	const char* JUMP_SOUND_PATH = "data/Sound/jump.mp3";
	const char* SHIELD_SOUND_PATH = "data/Sound/Shield.mp3";
};


