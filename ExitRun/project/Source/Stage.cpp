#include "Stage.h"
#include "DxLib.h"
#include "stage1.h"
#include "Player.h"

Stage::Stage()
{

	hImage = LoadGraph("data/background2.png");
	backGroundX = 0;
	backGroundY = 0;

	//for (int j = 0; j < HEIGHT; j++) {
	//	for (int i = 0; i < WIDTH; i++) {
	//		if (map[j][i] == 9) {//9‚¾‚Á‚½‚çƒvƒŒƒCƒ„[
	//			Player* p = Instantiate<Player>();
	//			p->position.x = i * 64;
	//			p->position.y = j * 64;
	//		}
	//	}
	//}
}

void Stage::Draw()
{
	
		DrawGraph(backGroundX , backGroundY, hImage , TRUE);
		
	

}
