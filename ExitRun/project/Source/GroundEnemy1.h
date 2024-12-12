#pragma once
#include "../Library/GameObject.h"
#include "VECTOR2.h"

class GroundEnemy1: public GameObject
{
private:
	int hImage;
	
	int timer;
	bool attacking;		//ƒvƒŒƒCƒ„[‚É“Ë“ü
	bool dead;			//€‚ñ‚¾‚çtrue
	int deadCounter;    //€‚ñ‚Å‚éŠÔ
	bool fadeStarted;

public:
	GroundEnemy1();
	~GroundEnemy1();

	void Update();
	void Draw();
	VECTOR2 speed;
	VECTOR2 position;

	
};

