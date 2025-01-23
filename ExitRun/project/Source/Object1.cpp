#include "Object1.h"
#include "Stage.h"

Object1::Object1()
{
	hImage = LoadGraph("data/toge.png");
	/*position.x = 1280;
	position.y = 480;*/
	speed.x = 0.0f;
}
Object1::~Object1()
{

}

void Object1::Update()
{
	//position.x -= 1.5f;
}

void Object1::Draw()
{
	Stage* s = FindGameObject<Stage>();
	DrawGraph(position.x - s->scroll, position.y, hImage, true);

	int width, height;
	GetGraphSize(hImage, &width, &height);
//	DrawCircle(position.x + width / 2 - s->scroll, position.y + height / 2, width / 2, RGB(0, 0, 0), 0);
}

VECTOR2 Object1::getObjectPosition() const
{
	Stage* s = FindGameObject<Stage>();
	int width, height;
	GetGraphSize(hImage, &width, &height);
	VECTOR2 ObjectPos = { position.x + width / 2, position.y + height / 2 };
	return ObjectPos;
}