#pragma once
#include "../Library/GameObject.h"

class Stage : public GameObject
{
private:
	int hImage;
	int backgroundX;
	int backgroundY;
public:
	Stage();
	void Update();
	void Draw();
};