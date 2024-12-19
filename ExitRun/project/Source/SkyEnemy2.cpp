#include "SkyEnemy2.h"
#include "Player.h"
#include "../Library/GameObject.h"
#include "GameManager.h"

SkyEnemy2::SkyEnemy2()
{
	hImage = LoadGraph("data/same2.png");
	position.x = 1280;
	position.y = 370;
	speed.x = 0.0f;
	speed.y = 0.0f;
	dead = false;
	timer = 0;
}

SkyEnemy2::~SkyEnemy2()
{
	DeleteGraph(hImage);
}

void SkyEnemy2::Update()
{
	GameManager* gm = FindGameObject<GameManager>();
	if (gm->playable) {
		//上下移動の動き
		timer += 0.04f;
		position.y += 5 * sinf(timer);//幅×sin(角)

		position.x -= 2.0f;
	}
}

void SkyEnemy2::Draw()
{
	DrawGraph(position.x, position.y, hImage, true);
	//	debug
	int width, height;
	GetGraphSize(hImage, &width, &height);
	DrawCircle(position.x + width / 2, position.y + height / 2, width / 2, RGB(0, 0, 0), 0);//当たり判定を左上じゃなくて中心を基準にする
}

VECTOR2 SkyEnemy2::getPosition() const
{
	int width, height;
	GetGraphSize(hImage, &width, &height);
	VECTOR2 groundEnemyPos = { position.x + width / 2, position.y + height / 2 };
	return groundEnemyPos;
}
