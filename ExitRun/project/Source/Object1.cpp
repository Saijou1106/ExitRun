#include "Object1.h"

Object1::Object1()
{
	hImage = LoadGraph("data/toge.png");
	position.x = 1280;
	position.y = 480;
	speed.x = 0.0f;
}
Object1::~Object1()
{

}

void Object1::Update()
{
	position.x -= 1.5f;
}

void Object1::Draw()
{
	DrawGraph(position.x, position.y, hImage, true);

	int width, height;
	GetGraphSize(hImage, &width, &height);
	//DrawCircle(position.x + width / 2, position.y + height / 2, width / 2, RGB(0, 0, 0), 0);
}

VECTOR2 Object1::getObjectPosition() const
{
	int width, height;
	GetGraphSize(hImage, &width, &height);
	VECTOR2 ObjectPos = { position.x + width / 2, position.y + height / 2 };
	return ObjectPos;
}