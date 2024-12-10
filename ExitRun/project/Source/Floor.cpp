#include "Floor.h"
#include "DxLib.h"

Floor::Floor()
{
	hImage = LoadGraph("data/floor1.png");
	floorX = 0;
	floorY = 500 + 64;
}

void Floor::Draw()
{
	//�����̏��摜�����ɕ��ׂ�
	for (int i = 0; i < 6; i++) {

	     DrawGraph(floorX + i * 64, floorY, hImage, TRUE);
	}
}

void Floor::Update()
{
	
}
