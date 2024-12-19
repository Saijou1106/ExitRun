#include "SkyEnemy1.h"
#include "Player.h"
#include "../Library/GameObject.h"
#include "GameManager.h"

SkyEnemy1::SkyEnemy1()
{
	hImage = LoadGraph("data/same.png");
	position.x = 780;
	position.y = 300;

	dead = false;
}

SkyEnemy1::~SkyEnemy1()
{
}

void SkyEnemy1::Update()
{
	GameManager* gm = FindGameObject<GameManager>();
	if (gm->playable) {
		position.x -= 3.0f;
	}
}

void SkyEnemy1::Draw()
{
	DrawGraph(position.x, position.y, hImage, true);
	//	debug
	int width, height;
	GetGraphSize(hImage, &width, &height);
	DrawCircle(position.x + width / 2, position.y + height / 2, width / 2, RGB(0, 0, 0), 0);//“–‚½‚è”»’è‚ğ¶ã‚¶‚á‚È‚­‚Ä’†S‚ğŠî€‚É‚·‚é
}

VECTOR2 SkyEnemy1::getPosition() const
{
	int width, height;
	GetGraphSize(hImage, &width, &height);
	VECTOR2 groundEnemyPos = { position.x + width / 2, position.y + height / 2 };
	return groundEnemyPos;
}
