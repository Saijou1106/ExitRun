#include "SkyEnemy2.h"
#include "Player.h"
#include "../Library/GameObject.h"
#include "Stage.h"

SkyEnemy2::SkyEnemy2()
{
	hImage = LoadGraph("data/same2.png");
	position.x = 1280;
	position.y = 380;
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
	//ã‰ºˆÚ“®‚Ì“®‚«
	timer += 0.04f;
	position.y += 5* sinf(timer);//•~sin(Šp)

	position.x -= 2.0f;
	
	
}

void SkyEnemy2::Draw()
{
	Stage* s = FindGameObject<Stage>();
	DrawGraph(position.x - s->scroll, position.y, hImage, true);
	//	debug
	int width, height;
	GetGraphSize(hImage, &width, &height);
	DrawCircle(position.x + width / 2 - s->scroll, position.y + height / 2, width / 2, RGB(0, 0, 0), 0);//“–‚½‚è”»’è‚ğ¶ã‚¶‚á‚È‚­‚Ä’†S‚ğŠî€‚É‚·‚é
}

VECTOR2 SkyEnemy2::getPosition() const
{
	Stage* s = FindGameObject<Stage>();
	int width, height;
	GetGraphSize(hImage, &width, &height);
	VECTOR2 groundEnemyPos = { position.x  + width / 2 - s->scroll, position.y + height / 2 };
	return groundEnemyPos;
}
