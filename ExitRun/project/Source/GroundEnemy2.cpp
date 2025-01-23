#include "GroundEnemy1.h"
#include "DxLib.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "Screen.h"
#include "Player.h"
#include "GroundEnemy2.h"
#include "Stage.h"



GroundEnemy2::GroundEnemy2()
{
<<<<<<< HEAD
	hImage = LoadGraph("data/enemy1.png");
=======
	hImage = LoadGraph("data/dog.png");
>>>>>>> origin/konno
	/*position.x = 1280;
	position.y = 575;*/
	speed.x = 0.0f;

	dead = false;
}

GroundEnemy2::~GroundEnemy2()
{
	DeleteGraph(hImage);
}

void GroundEnemy2::Update()
{
	
	//position.x -= 4.5f;
	
}

void GroundEnemy2::Draw()
{
	Stage* s = FindGameObject<Stage>();
	DrawGraph(position.x - s->scroll, position.y, hImage, true);


	//	debug
	int width, height;
	GetGraphSize(hImage, &width, &height);
	centerPos.x = position.x - s->scroll + width / 2;
	centerPos.y = position.y + height / 2;
	//DrawCircle(position.x + width / 2 - s->scroll, position.y + height / 2, width / 2, RGB(0, 0, 0), 0);//当たり判定を左上じゃなくて中心を基準にする
<<<<<<< HEAD
	//DrawCircle(centerPos.x, centerPos.y, width / 2, RGB(0, 0, 0), 0);//当たり判定を左上じゃなくて中心を基準にする
=======
	DrawCircle(centerPos.x, centerPos.y, width / 2, RGB(0, 0, 0), 0);//当たり判定を左上じゃなくて中心を基準にする
>>>>>>> origin/konno
	scroll = s->scroll;

}

VECTOR2 GroundEnemy2::getPosition() const
{

	Stage* s = FindGameObject<Stage>();
	int width, height;
	GetGraphSize(hImage, &width, &height);
	VECTOR2 groundEnemyPos = { position.x  + width / 2  , position.y + height / 2 };
	return groundEnemyPos;
}
