#include "SkyEnemy2.h"
#include "Player.h"
#include "../Library/GameObject.h"
#include "Stage.h"

SkyEnemy2::SkyEnemy2()
{
	hImage = LoadGraph("data/brid.png");
	speed.x = 0.0f;
	speed.y = 0.0f;
	timer = 0;
}

SkyEnemy2::~SkyEnemy2()
{
	DeleteGraph(hImage);
}

void SkyEnemy2::Update()
{
	//�㉺�ړ��̓���
	timer += 0.04f;
	position.y += 2* sinf(timer);//���~sin(�p)

	//position.x -= 2.0f;
	
	
}

void SkyEnemy2::Draw()
{
	Stage* s = FindGameObject<Stage>();
	DrawGraph(position.x - s->scroll, position.y, hImage, true);
	//	debug
	int width, height;
	GetGraphSize(hImage, &width, &height);
}

VECTOR2 SkyEnemy2::getPosition() const
{
	Stage* s = FindGameObject<Stage>();
	int width, height;
	GetGraphSize(hImage, &width, &height);
	VECTOR2 groundEnemyPos = { position.x  + width / 2 , position.y + height / 2 };
	return groundEnemyPos;
}
