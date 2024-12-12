#pragma once
#include "../Library/GameObject.h"
#include "VECTOR2.h"

class GroundEnemy2 : public GameObject
{
private:
	int hImage;

	int timer;
	bool attacking;		//プレイヤーに突入
	bool dead;			//死んだらtrue
	int deadCounter;    //死んでる時間


public:
	GroundEnemy2();
	~GroundEnemy2();

	void Update();
	void Draw();
	VECTOR2 speed;
	VECTOR2 position;
};


