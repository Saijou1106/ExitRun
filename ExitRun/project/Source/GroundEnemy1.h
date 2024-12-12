#pragma once
#include "../Library/GameObject.h"
#include "VECTOR2.h"
#include "Enemy.h"
#include "Player.h"

class GroundEnemy1: public Enemy
{
private:
	int hImage;
	
	int timer;
	bool attacking;		//プレイヤーに突入
	bool dead;			//死んだらtrue
	bool isShield;       //プレイヤーが盾を保持
	int deadCounter;    //死んでる時間


public:
	GroundEnemy1();
	~GroundEnemy1();

	void Update();
	void Draw();
	VECTOR2 speed;
	VECTOR2 position;
	VECTOR2 getPosition() const override;
};

