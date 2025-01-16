#include "Stage.h"
#include "DxLib.h"
#include "stage1.h"
#include "Player.h"

Stage::Stage()
{

	backGroundImage = LoadGraph("data/background2.png");
	floorImage = LoadGraph("data/floor3.png");
	backGroundX = 0;
	backGroundY = 0;
	
	scroll = 2;
	//for (int j = 0; j < HEIGHT; j++) {
	//	for (int i = 0; i < WIDTH; i++) {
	//		if (map[j][i] == 9) {//9だったらプレイヤー
	//			Player* p = Instantiate<Player>();
	//			p->position.x = i * 64;
	//			p->position.y = j * 64;
	//		}
	//		
	//	}
	//}
	//scroll = 0;
}

Stage::~Stage()
{
}

void Stage::Draw()
{
	DrawGraph(backGroundX - scroll , backGroundY, backGroundImage , TRUE);

	for (int j = 0; j < HEIGHT; j++) {
		int y = j * 64 + 100;
		for (int i = 0; i < WIDTH; i++) {
			int x = i * 64 + 100;
			if (map[j][i] == 1) {//1だったら地面
				DrawGraph(x- scroll, y, floorImage, TRUE);
			}
		}
	}
	
}

//int Stage::IsWallRight(VECTOR2 pos)
//{
//	int i = (pos.x - 100) / 64;
//	int j = (pos.y - 100) / 64;
//	if (map[j][i] == 1) {
//		int push = ((int)pos.x - 100) % 64 + 1;
//		return push;
//	}
//	return 0;
//}
//
//int Stage::IsWallDown(VECTOR2 pos)
//{
//	int i = (pos.x - 100) / 64;
//	int j = (pos.y - 100) / 64;
//	if (map[j][i] == 1) {
//		int push = ((int)pos.y - 100) % 64 + 1;
//		return push;
//	}
//	return 0;
//}
//
//int Stage::IsWallLeft(VECTOR2 pos)
//{
//	int i = (pos.x - 100) / 64;
//	int j = (pos.y - 100) / 64;
//	if (map[j][i] == 1) {
//		int push = 64 - ((int)pos.x - 100) % 64;
//		return push;
//	}
//	return 0;
//}
//
//int Stage::IsWallUp(VECTOR2 pos)
//{
//	int i = (pos.x - 100) / 64;
//	int j = (pos.y - 100) / 64;
//	if (map[j][i] == 1) {
//		int push = 64 - ((int)pos.y - 100) % 64;
//		return push;
//	}
//	return 0;
//}


