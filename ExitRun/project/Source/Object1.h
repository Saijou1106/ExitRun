#pragma once
#include "../Library/GameObject.h"
#include "Vector2.h"
#include "Shield.h" 
#include "Enemy.h"
#include "Player.h"
#include "Object.h"

class Object1 : public Object
{
public:
	Object1();
	~Object1();
	void Update() override;
	void Draw() override;

	int hImage;
	VECTOR2 position;
	VECTOR2 speed;
	VECTOR2 getObjectPosition() const override;
	bool isShield;       //ƒvƒŒƒCƒ„[‚ª‚‚ğ•Û
};