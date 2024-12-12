#pragma once
#include "../Library/GameObject.h"
#include "Vector2.h"

class SkyEnemy2 : public GameObject {
public:
	SkyEnemy2();
	~SkyEnemy2();
	void Update() override;
	void Draw() override;

	int hImage;

	VECTOR2 position;
	VECTOR2 speed;

	int patternX;
	int patternY;
	int dead;

};