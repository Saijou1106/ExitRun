#pragma once
#include "../Library/GameObject.h"
#include "VECTOR2.h"
#include "Enemy.h"
#include "Player.h"

class GroundEnemy2 : public Enemy
{
private:
	int hImage;
	int EnemyIsDeadImage;
	int timer;
	bool attacking;		//プレイヤーに突入
	bool isShield;      //盾の保持
	int deadCounter;    //死んでる時間

	VECTOR2 centerPos;
	int scroll;

public:
	GroundEnemy2();
	~GroundEnemy2();
	bool isDead;
	void Update();
	void Draw();
	VECTOR2 speed;
	VECTOR2 position;
	VECTOR2 getPosition() const override;//GroundEnemy2固有Position
};


