#include "Stage.h"
#include "DxLib.h"

Stage::Stage()
{
	hImage = LoadGraph("data/background.png");
	backgroundX = 0;
	backgroundY = 0;


}

void Stage::Update()
{
}

void Stage::Draw()
{
	DrawGraph(backgroundX, backgroundY, hImage, TRUE);
}