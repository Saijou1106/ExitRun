#pragma once
#include "../Library/GameObject.h"
#include "VECTOR2.h"
#include "Enemy.h"
#include "Player.h"

class GroundEnemy2 : public Enemy
{
private:
	

	int timer;
	bool attacking;		//プレイヤーに突入
	bool isShield;      //盾の保持
	

	VECTOR2 centerPos;
	int scroll;

public:
	int hImage;

	bool dead;			//死んだらtrue
	int deadCounter;    //死んでる時間
	int deadImage;      //死んだときのイメージ

	GroundEnemy2();
	~GroundEnemy2();

	void Update();
	void Draw();
	void Dead(); // 死んだときの処理
	VECTOR2 speed;
	VECTOR2 position;
	VECTOR2 getPosition() const override;//GroundEnemy2固有Position
};


