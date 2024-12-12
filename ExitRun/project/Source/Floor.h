#pragma once
#include "../Library/GameObject.h"


class Floor : public GameObject
{
private:
	int hImage;
	int floorX;
	int floorY;

public:
	Floor();
	void Draw();
	void Update();

};