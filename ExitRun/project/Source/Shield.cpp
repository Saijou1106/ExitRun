#include "Shield.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "Screen.h"
#include "Player.h"


Shild::Shild()
{
	hImage = LoadGraph("data/shild.png");
	position.x = 120;  
	position.y = 500;
}

Shild::~Shild()
{
	DeleteGraph(hImage);
}

void Shild::Updata()
{
	//if () {
	//	DestroyMe();
	//}

}

void Shild::Draw()
{
	DrawGraph(position.x, position.y, hImage, TRUE);

}
