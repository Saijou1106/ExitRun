#pragma once
#include "Player.h"
#include "../Library/GameObject.h"
#include "VECTOR2.h"


class Shild : public GameObject
{
public:
	Shild();
	~Shild();
	void Updata();
	void Draw()override;


	int hImage;
	VECTOR2 position;
};