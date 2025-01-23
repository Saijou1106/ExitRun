
#include "JumpEnemy.h"
#include "Player.h"
#include "../Library/GameObject.h"
#include "Stage.h"

JumpEnemy::JumpEnemy()
{
	hImage = LoadGraph("data/kanfu.png");
	/*position.x = 1080;
	position.y = 575;*/
	basePosition = position;
	dead = false;
	timer = 0;
}

JumpEnemy::~JumpEnemy()
{
	DeleteGraph(hImage);
}

void JumpEnemy::Update()
{
	timer += 0.05f;
	position.y = basePosition.y - abs(sinf(timer)) * 100; //abs ê‚ëŒílÇÇ∆ÇÈä÷êî

}

void JumpEnemy::Draw()
{
	Stage* s = FindGameObject<Stage>();
	DrawGraph(position.x - s->scroll, position.y, hImage, true);

	int width, height;
	GetGraphSize(hImage, &width, &height);
<<<<<<< HEAD
	//DrawCircle(position.x + width / 2 - s->scroll, position.y + height / 2, width / 2, RGB(0, 0, 0), 0);
=======
	DrawCircle(position.x + width / 2 - s->scroll, position.y + height / 2, width / 2, RGB(0, 0, 0), 0);
>>>>>>> origin/konno
}

VECTOR2 JumpEnemy::getPosition() const
{
	Stage* s = FindGameObject<Stage>();
	int width, height;
	GetGraphSize(hImage, &width, &height);
	VECTOR2 JumpPos = { position.x + width / 2, position.y + height / 2 };
	return JumpPos;
}
