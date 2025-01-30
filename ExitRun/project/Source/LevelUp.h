#pragma once
#include "../Library/GameObject.h"
#include "Vector2.h"

class LevelUp : public GameObject {
public:
	LevelUp();
	~LevelUp();
	void Update() override;
	void Draw() override;
private:
	int hImage;
	VECTOR2 position;
	float scale;
	int timer;
}; 
