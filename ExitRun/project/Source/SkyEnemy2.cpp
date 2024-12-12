#include "SkyEnemy2.h"
#include "Player.h"
#include "../Library/GameObject.h"

SkyEnemy2::SkyEnemy2()
{
	hImage = LoadGraph("data/same2.png");
	position.x = 1280;
	position.y = 300;
	speed.x = 0.0f;
	speed.y = 0.0f;
	dead = false;
}

SkyEnemy2::~SkyEnemy2()
{
	DeleteGraph(hImage);
}

void SkyEnemy2::Update()
{

	position.x -= 5.0f;
	std::list<Player*> player = FindGameObjects<Player>();
	for (Player* pl : player) {
		VECTOR2 plMid;
		plMid.x = pl->position.x + 32;
		plMid.y = pl->position.y + 32;
		VECTOR2 seMid;
		seMid.x = position.x + 32;
		seMid.y = position.y + 32;

		if (CircleHit(seMid, plMid, 56)) {
			dead = true;
			pl->DestroyMe();
		}
	}


}

void SkyEnemy2::Draw()
{
	DrawGraph(position.x, position.y, hImage, true);
}
