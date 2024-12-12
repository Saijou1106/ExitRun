#include "GroundEnemy1.h"
#include "DxLib.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "Screen.h"
#include "Player.h"
#include "GroundEnemy2.h"



GroundEnemy2::GroundEnemy2()
{
	hImage = LoadGraph("data/dog.png");
	position.x = 1280;
	position.y = 490;
	speed.x = 0.0f;

	//isShield = false;
	dead = false;
}

GroundEnemy2::~GroundEnemy2()
{
	DeleteGraph(hImage);
}

void GroundEnemy2::Update()
{
	position.x -= 6.5f;
	
}

void GroundEnemy2::Draw()
{
	DrawGraph(position.x, position.y, hImage, true);
	//	debug
	int width, height;
	GetGraphSize(hImage, &width, &height);
	VECTOR2 groundEnemyPos = getPosition();
	DrawCircle(groundEnemyPos.x, groundEnemyPos.y, width / 2, RGB(0, 0, 0), 0);//ìñÇΩÇËîªíËÇç∂è„Ç∂Ç·Ç»Ç≠ÇƒíÜêSÇäÓèÄÇ…Ç∑ÇÈ

}

VECTOR2 GroundEnemy2::getPosition() const
{
	int width, height;
	GetGraphSize(hImage, &width, &height);
	VECTOR2 groundEnemyPos = { position.x + width / 2, position.y + height / 2 };
	return groundEnemyPos;
}
