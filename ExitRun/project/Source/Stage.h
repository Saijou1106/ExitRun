#pragma once
#include "../Library/GameObject.h"
#include "Vector2.h"

class Stage : public GameObject
{

public:
	Stage();
	~Stage();
	void Draw();
	int IsWallRight(VECTOR2 pos);
	int IsWallDown(VECTOR2 pos);
	int IsWallLeft(VECTOR2 pos);
	int IsWallUp(VECTOR2 pos);
	int scroll;

	int backGroundImage;
	int backGroundX;
	int backGroundY;

	int floorImage;
	int floorX;
	int floorY;
};

