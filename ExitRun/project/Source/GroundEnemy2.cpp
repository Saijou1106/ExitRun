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
	hImage = LoadGraph("data/dog.png");
	deadImage = LoadGraph("data/same.png");
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
	if (dead) {
		deadCounter++;
		if (deadCounter >= 30) {
			DestroyMe();   // 30フレーム経ったら消える
		}
		return;   // 敵の動きとかをやらないようにする
	}
	//position.x -= 4.5f;
	
}

void GroundEnemy2::Draw()
{
	Stage* s = FindGameObject<Stage>();
	
	if (dead) {
		DrawGraph(position.x - s->scroll, position.y, deadImage, true);
	}
	else {
		DrawGraph(position.x - s->scroll, position.y, hImage, true);
	}

	//	debug
	int width, height;
	GetGraphSize(hImage, &width, &height);
	centerPos.x = position.x - s->scroll + width / 2;
	centerPos.y = position.y + height / 2;
	//DrawCircle(position.x + width / 2 - s->scroll, position.y + height / 2, width / 2, RGB(0, 0, 0), 0);//当たり判定を左上じゃなくて中心を基準にする
	DrawCircle(centerPos.x, centerPos.y, width / 2, RGB(0, 0, 0), 0);//当たり判定を左上じゃなくて中心を基準にする
	scroll = s->scroll;

}

void GroundEnemy2::Dead()
{
	dead = true;
	deadCounter = 0;
}

VECTOR2 GroundEnemy2::getPosition() const
{

	Stage* s = FindGameObject<Stage>();
	int width, height;
	GetGraphSize(hImage, &width, &height);
	VECTOR2 groundEnemyPos = { position.x  + width / 2  , position.y + height / 2 };
	return groundEnemyPos;
}
