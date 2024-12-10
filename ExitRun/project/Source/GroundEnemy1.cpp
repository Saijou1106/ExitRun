#include "GroundEnemy1.h"
#include "DxLib.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "Screen.h"
#include "Player.h"

//#include "Vector2.cpp"

GroundEnemy1::GroundEnemy1()
{
	hImage = LoadGraph("data/maguroRed.png");
	position.x = 1280;
	position.y = 500;
	speed.x = 0.0f;


	dead = false;
	
}

GroundEnemy1::~GroundEnemy1()
{
	DeleteGraph(hImage);
}

void GroundEnemy1::Update()
{
	position.x -= 3.0f;
	std::list<Player*> player = FindGameObjects<Player>();
	std::list<Shield*> shield = FindGameObjects<Shield>();

	
	for (Player* pl : player) {

		VECTOR2 plCenter;//�v���C���[�̒��S���W
		plCenter.x = pl->position.x;
		plCenter.y = pl->position.y;
	
		VECTOR2 GECenter;//�G�̒��S���W
		  GECenter.x = position.x;
          GECenter.y = position.y;
       
		  //�v���C���[���������Ă�Ƃ��Ɏ���������
		  for (Shield* sh : shield) {
			  if (sh->isShield){
				  if (CircleHit(plCenter, GECenter, 64)) {
					  DestroyMe();
				  }
			  }
		  }
		  
    }

	
	
}

void GroundEnemy1::Draw()
{
	DrawGraph(position.x, position.y, hImage, true);
}
VECTOR2 GroundEnemy1::getPosition() const
{
	return position;
}
