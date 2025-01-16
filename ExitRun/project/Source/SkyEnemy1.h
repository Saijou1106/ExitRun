#pragma once
#include "Vector2.h"
#include "../Library/GameObject.h"
#include "Enemy.h"

class SkyEnemy1 : public Enemy
{
public:
	SkyEnemy1();
	~SkyEnemy1();
	void Update() override;
	void Draw() override;

	int hImage;
	VECTOR2 position;
	VECTOR2 speed;
	VECTOR2 getPosition() const override;
	bool isShield;       //ƒvƒŒƒCƒ„[‚ª‚‚ğ•Û
	bool dead;
};