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

		VECTOR2 plCenter;//プレイヤーの中心座標
		plCenter.x = pl->position.x;
		plCenter.y = pl->position.y;
	
		VECTOR2 GECenter;//敵の中心座標
		  GECenter.x = position.x;
          GECenter.y = position.y;
       
		  //プレイヤーが盾持ってるときに自分を消す
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
