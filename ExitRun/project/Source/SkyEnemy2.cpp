#include "SkyEnemy2.h"
#include "Player.h"
#include "../Library/GameObject.h"

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
	//�㉺�ړ��̓���
	timer += 0.04f;
	position.y += 5* sinf(timer);//���~sin(�p)

	position.x -= 2.0f;
	std::list<Player*> player = FindGameObjects<Player>();
	std::list<Shield*> shield = FindGameObjects<Shield>();

	for (Player* pl : player) {

		//�v���C���[�̒��S���W
		VECTOR2 plMid;
		plMid.x = pl->position.x + 32;
		plMid.y = pl->position.y + 32;
		//�G�̒��S���W
		VECTOR2 seMid;
		seMid.x = position.x + 32;
		seMid.y = position.y + 32;

		//�������Ă�Ƃ��Ɏ���������
		for (Shield* sh : shield) {
			if (sh->isShield) {
				if (CircleHit(plMid, seMid, 64)) {
					DestroyMe();
				}
			}
		}
	}
}

void SkyEnemy2::Draw()
{
	DrawGraph(position.x, position.y, hImage, true);
}

VECTOR2 SkyEnemy2::getPosition() const
{
	return position;
}
