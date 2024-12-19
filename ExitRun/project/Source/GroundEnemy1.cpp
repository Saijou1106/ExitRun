#include "GroundEnemy1.h"
#include "DxLib.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "Screen.h"
#include "Player.h"
#include "GameManager.h"

//#include "Vector2.cpp"

GroundEnemy1::GroundEnemy1()
{
	hImage = LoadGraph("data/maguroRed.png");
	position.x = 1280;
	position.y = 450;
	speed.x = 0.0f;


	dead = false;
	
}

GroundEnemy1::~GroundEnemy1()
{
	DeleteGraph(hImage);
}

void GroundEnemy1::Update()
{
	GameManager* gm = FindGameObject<GameManager>();
	if (gm->playable) {
	position.x -= 3.0f;
}
}

void GroundEnemy1::Draw()
{
	DrawGraph(position.x, position.y, hImage, true);

	//	debug
	int width, height;
	GetGraphSize(hImage, &width, &height);
	DrawCircle(position.x + width / 2, position.y + height / 2, width / 2, RGB(0, 0, 0), 0);//ìñÇΩÇËîªíËÇç∂è„Ç∂Ç·Ç»Ç≠ÇƒíÜêSÇäÓèÄÇ…Ç∑ÇÈ

}

VECTOR2 GroundEnemy1::getPosition() const
{
	int width, height;
	GetGraphSize(hImage, &width, &height);
	VECTOR2 groundEnemyPos = { position.x + width / 2, position.y + height / 2 };
	return groundEnemyPos;
}
