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

	//isShield = false;
	dead = false;
}

GroundEnemy2::~GroundEnemy2()
{
	DeleteGraph(hImage);
}

void GroundEnemy2::Update()
{
	position.x -= 8.5f;
	std::list<Player*> player = FindGameObjects<Player>();
	std::list<Shield*> shield = FindGameObjects<Shield>();

	
	for (Player* pl : player) {

		//プレイヤーの中心座標
		VECTOR2 plCenter;
		plCenter.x = pl->position.x;
		plCenter.y = pl->position.y;
		//敵の中心座標
		VECTOR2 GECenter;
		GECenter.x = position.x;
		GECenter.y = position.y;

		//盾持ってるときに自分を消す
		for (Shield* sh : shield) {
			if (sh->isShield) {
				if (CircleHit(plCenter, GECenter, 64)) {
					DestroyMe();
				}
			}
		}
	}
}

void GroundEnemy2::Draw()
{
	DrawGraph(position.x, position.y, hImage, true);
}

VECTOR2 GroundEnemy2::getPosition() const
{
	return position;
}
