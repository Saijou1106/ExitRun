#pragma once
#include "../Library/GameObject.h"

class Stage : public GameObject
{
private:
	
	int hImage;
	int backGroundX;
	int backGroundY;

public:
	Stage();
	
	void Draw();
};

