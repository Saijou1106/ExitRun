#include "Floor.h"
#include "DxLib.h"

Floor::Floor()
{
	hImage = LoadGraph("data/floor2.png");
	floorX = 0;
	floorY = 520;
}

void Floor::Draw()
{
	//�����̏��摜�����ɕ��ׂ�
	for (int i = 0; i < 10; i++) {

	     DrawGraph(floorX + i * 200, floorY, hImage, TRUE);
	}
}

void Floor::Update()
{
	
}
