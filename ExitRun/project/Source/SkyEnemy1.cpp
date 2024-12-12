#include "SkyEnemy1.h"
#include "Player.h"
#include "../Library/GameObject.h"

SkyEnemy1::SkyEnemy1()
{
	hImage = LoadGraph("data/same.png");
	position.x = 1280;
	position.y = 500;


	//dead = false;
	isAlive = true;
}

SkyEnemy1::~SkyEnemy1()
{
}

void SkyEnemy1::Update()
{
	position.x -= 1.0f;
}

void SkyEnemy1::Draw()
{
	DrawGraph(position.x, position.y, hImage, true);
}

int SkyEnemy1::isHead(VECTOR2 pos)
{
	return 0;
}

int SkyEnemy1::isRight(VECTOR2 pos)
{
	return 0;
}

int SkyEnemy1::isLeft(VECTOR2 pos)
{
	return 0;
}

int SkyEnemy1::isFoot(VECTOR2 pos)
{
	return 0;
}

