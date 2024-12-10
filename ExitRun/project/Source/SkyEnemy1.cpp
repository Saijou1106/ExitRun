#include "SkyEnemy1.h"
#include "Player.h"
#include "../Library/GameObject.h"

SkyEnemy1::SkyEnemy1()
{
	hImage = LoadGraph("data/same.png");
	position.x = 1280;
	position.y = 300;

	dead = false;
}

SkyEnemy1::~SkyEnemy1()
{
}

void SkyEnemy1::Update()
{
	position.x -= 1.0f;
	std::list<Player*> player = FindGameObjects<Player>();
	std::list<Shield*> shield = FindGameObjects<Shield>();

	for (Player* pl : player) {
		
			VECTOR2 plCenter;
			plCenter.x = pl->position.x + 32;
			plCenter.y = pl->position.y + 32;

			VECTOR2 SECenter;
			SECenter.x = position.x + 32;
			SECenter.y = position.y + 32;

			//‚Ž‚Á‚Ä‚é‚Æ‚«‚ÉŽ©•ª‚ðÁ‚·
			for (Shield* sh : shield) {
				if (sh->isShield) {
					if (CircleHit(plCenter, SECenter, 64)) {
						DestroyMe();
					}
				}
			}
	}
}

void SkyEnemy1::Draw()
{
	DrawGraph(position.x, position.y, hImage, true);
}

VECTOR2 SkyEnemy1::getPosition() const
{
	return position;
}
