#pragma once
#include "../Library/GameObject.h"
#include "Vector2.h"
#include "Enemy.h"

class JumpEnemy : public Enemy
{
public:
	int hImage;
	VECTOR2 position;
	VECTOR2 basePosition;
	VECTOR2 speed;
	VECTOR2 getPosition() const override;
	bool isShield;       //ƒvƒŒƒCƒ„[‚ª‚‚ğ•Û
	bool dead;
	float timer;

	JumpEnemy();
	~JumpEnemy();

	void Update();
	void Draw();
};
