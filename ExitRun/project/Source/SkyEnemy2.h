#pragma once
#include "../Library/GameObject.h"
#include "Vector2.h"
#include "Enemy.h"

class SkyEnemy2 : public Enemy {
public:
	SkyEnemy2();
	~SkyEnemy2();
	void Update() override;
	void Draw() override;

	int hImage;

	VECTOR2 position;
	VECTOR2 speed;
	VECTOR2 getPosition() const override;

	int patternX;
	int patternY;
	int dead;
	float timer;
	bool exploded ; // 爆発処理が行われたかどうかを管理
	bool isDead;

};