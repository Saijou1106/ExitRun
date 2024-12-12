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
	position.y = 500;
	speed.x = 0.0f;


	dead = false;
}

GroundEnemy2::~GroundEnemy2()
{
	DeleteGraph(hImage);
}

void GroundEnemy2::Update()
{
	position.x -= 10.5f;
	std::list<Player*> player = FindGameObjects<Player>();
	for (Player* pl : player) {
		pl->position;
		position;

		VECTOR2 plCenter;//�v���C���[�̒��S���W
		plCenter.x = pl->position.x;
		plCenter.y = pl->position.y;

		VECTOR2 GECenter;//�G�̒��S���W
		GECenter.x = position.x;
		GECenter.y = position.y;

		if (CircleHit(plCenter, GECenter, 64)) {
			dead = true;
			pl->DestroyMe();
		}
	}
}

void GroundEnemy2::Draw()
{
	DrawGraph(position.x, position.y, hImage, true);
}
