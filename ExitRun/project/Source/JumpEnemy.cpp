
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

	//position.x -= 1.0f;

	//std::list<Player*> player = FindGameObjects<Player>();
	//std::list<Shield*> shielde = FindGameObjects<Shield>();

	//for (Player* pl : player) {
	//	for (Shield* sh : shielde) {
	//		VECTOR2 plCenter;
	//		plCenter.x = pl->position.x + 32;
	//		plCenter.y = pl->position.y + 32;

	//		VECTOR2 SECenter;
	//		SECenter.x = position.x + 32;
	//		SECenter.y = position.y + 32;

	//		if (CircleHit(plCenter, SECenter, 64))
	//		{
	//			if (isShield) {
	//				sh->DestroyMe();
	//			}
	//		}
	//	}


	//}
}

void JumpEnemy::Draw()
{
	Stage* s = FindGameObject<Stage>();
	DrawGraph(position.x - s->scroll, position.y, hImage, true);

	int width, height;
	GetGraphSize(hImage, &width, &height);
	DrawCircle(position.x + width / 2 - s->scroll, position.y + height / 2, width / 2, RGB(0, 0, 0), 0);
}

VECTOR2 JumpEnemy::getPosition() const
{
	return position;
}
