#include "Stage.h"
#include "DxLib.h"
#include "Player.h"
#include "Shield.h"
#include "CsvReader.h"
#include "Screen.h"
#include "../ImGui/imgui.h"

//	dataフォルダにあるcsvを読み込む方法ならこれらは不要(HORIKOSHI Masahiro)
#if false
#include "stage1.h"
#include "stage2.h"
#include "stage3.h"
#include "stage4.h"
#include "stage5.h"
#endif

//	敵を生成するために追加(HORIKOSHI Masahiro)
#include "GroundEnemy1.h"
#include "GroundEnemy2.h"
#include "SkyEnemy1.h"
#include "SkyEnemy2.h"
#include "Object1.h"
#include "JumpEnemy.h"


//	チップ１つの大きさ
const int CHIP_SIZE = 64;

//	各マップcsvファイル名を定義(HORIKOSHI Masahiro)
//	下記ファイル名はサンプルなので、適宜変更してください。
const std::string mapFile[5] =
	{
		"data/Stage1.csv",
		"data/Stage2.csv",   
		"data/Stage3.csv",
		"data/Stage4.csv",
		"data/Stage5.csv",
	};

Stage::Stage()
{

	backGroundImage = LoadGraph("data/background2.png");
	// 床用の画像読み込み
	floorImage = LoadGraph("data/floor3.png");
	////	ブロック用画像読み込み(HORIKOSHI Masahiro)
	//blockImage = LoadGraph("data/floor1.png");
	//	背景chip用画像読み込み(HORIKOSHI Masahiro)
	backChipImage = LoadGraph("data/backchip.png");
	LevelUpImage = LoadGraph("data/LevelUpImage.png");

	mapNo = 0;
	nextMapNo = -1;
	scroll = 2;
	CreateStage(mapNo);
	created = false;

}

Stage::~Stage()
{
}

void Stage::Update()
{
	int sc = (scroll / CHIP_SIZE) % WORLD_WIDTH;
	if (sc > WIDTH * 16 - 1) {
		if (nextMapNo >= 0 && created == false) {
			mapNo = nextMapNo;
			nextMapNo = -1;
			CreateStage(mapNo);
			created = true;
		}
	}
	else {
		created = false;
	}
	
	if (nextMapNo < 0) {
		nextMapNo = mapNo+1;
		if (nextMapNo > 4)
			nextMapNo = 4;
	}
	

}

void Stage::Draw()
{
	int drawScroll = scroll % (WORLD_WIDTH*CHIP_SIZE);

	for (int i = 0; i < WORLD_WIDTH; i++)
	{
		int x = ((i+WORLD_WIDTH+1) * CHIP_SIZE-drawScroll) % (WORLD_WIDTH*CHIP_SIZE) - CHIP_SIZE;
		if (x>Screen::WIDTH) {
			continue;
		}
		for (int j = 0; j < HEIGHT; j++) {
			int y = j * CHIP_SIZE;

			//	if分でもできるが、複数の設定を行う場合はswitch分のほうがお勧め(HORIKOSHI Masahiro)
			switch (map[j][i])
			{
				//	床
				case 1:
					DrawRectGraph(x,y, 0, 0, CHIP_SIZE, CHIP_SIZE, floorImage, TRUE);
					break;

					// GroundEnemy2＝踏める敵
				case 2:
				{
					DrawRectGraph(x, y, 0, 0, CHIP_SIZE, CHIP_SIZE, backChipImage, TRUE);
					//GroundEnemy2* enemy2 = Instantiate<GroundEnemy2>();
					//enemy2->position.x = i * CHIP_SIZE;
					//enemy2->position.y = j * CHIP_SIZE;
				}
				break;

				// Object1＝とげ
				case 3:
				{
					DrawRectGraph(x, y, 0, 0, CHIP_SIZE, CHIP_SIZE, backChipImage, TRUE);
					//Object1* object1 = Instantiate<Object1>();
					//object1->position.x = i * CHIP_SIZE;
					//object1->position.y = j * CHIP_SIZE;
				}
				break;

				// JumpEnemy = 跳ねる敵（カンフー）
				case 4:
				{
					DrawRectGraph(x, y, 0, 0, CHIP_SIZE, CHIP_SIZE, backChipImage, TRUE);
					//JumpEnemy* jumpEnemy = Instantiate<JumpEnemy>();
					//jumpEnemy->position.x = i * CHIP_SIZE;
					//jumpEnemy->position.y = j * CHIP_SIZE;
				}
				break;

				// SkyEnemey2 = 上下移動の敵
				case 5:
				{
					DrawRectGraph(x, y, 0, 0, CHIP_SIZE, CHIP_SIZE, backChipImage, TRUE);
					//SkyEnemy2* enemy2 = Instantiate<SkyEnemy2>();
					//enemy2->position.x = i * CHIP_SIZE;
					//enemy2->position.y = j * CHIP_SIZE;
				}
				break;
				// Shield = 盾
				case 9:
				{
					DrawRectGraph(x, y, 0, 0, CHIP_SIZE, CHIP_SIZE, backChipImage, TRUE);
					//SkyEnemy2* enemy2 = Instantiate<SkyEnemy2>();
					//enemy2->position.x = i * CHIP_SIZE;
					//enemy2->position.y = j * CHIP_SIZE;
				}
				break;
				default:
					DrawRectGraph(x,y, 0, 0, CHIP_SIZE, CHIP_SIZE, backChipImage, TRUE);
					break;
			}
		}
	}

	/*if (betweenScene) {
		DrawGraph(400, 120,LevelUpImage, TRUE);
	}*/
}

int Stage::IsWallUp(VECTOR2 pos)
{
	int i = ((int)pos.x / CHIP_SIZE) % WORLD_WIDTH;
	int j = pos.y / CHIP_SIZE;
	if (i < 0 || j < 0 || j >= HEIGHT)
		return 0;
	if (map[j][i] == 1)
	{
		int push = 64 - (int)pos.y % CHIP_SIZE;
		return push;
	}
	return 0;
}

int Stage::IsWallDown(VECTOR2 pos)
{
	int i = ((int)pos.x / CHIP_SIZE) % WORLD_WIDTH;
	int j = pos.y / CHIP_SIZE;
	if (i < 0 || j < 0 || j >= HEIGHT)
		return 0;
	if (map[j][i] == 1 )
	{
		int push = (int)pos.y % CHIP_SIZE + 1;
		return push;
	}
	return 0;
}

int Stage::IsWallRight(VECTOR2 pos)
{
	int i = ((int)pos.x / CHIP_SIZE) % WORLD_WIDTH;
	int j = pos.y / CHIP_SIZE;
	if (i < 0 || j < 0 || j >= HEIGHT)
		return 0;
	if (map[j][i] == 1 )
	{
		int push = (int)pos.x % CHIP_SIZE + 1;
		return push;
	}
	return 0;
}

int Stage::IsWallLeft(VECTOR2 pos)
{
	int i = ((int)pos.x / CHIP_SIZE) % WORLD_WIDTH;
	int j = pos.y / CHIP_SIZE;
	if (i < 0 || j < 0 || j >= HEIGHT)
		return 0;
	if (map[j][i] == 1 )
	{
		int push = 64 - (int)pos.x % CHIP_SIZE;
		return push;
	}
	return 0;
}

void Stage::CreateStage(int st)
{

	std::list<Enemy*> enemies = FindGameObjects<Enemy>();
	for (Enemy* e : enemies) {
		e->DestroyMe();
	}
	std::list<Shield*> shields = FindGameObjects<Shield>();
	for (Shield* s : shields) {
		s->DestroyMe();
	}
	std::list<Object*> objects = FindGameObjects<Object>();
	for (Object* ob : objects) {
		ob->DestroyMe();
	}

	//つなぎめ？

	for (int i = 0; i < WORLD_WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			map[j][i] = 0;
			map[0][i] = 1;
			map[HEIGHT - 1][i] = 1;

			betweenScene = true;
		}
	}

	//CsvReader reader("data/仮.csv");
	CsvReader reader(mapFile[st]);		//	Map番号に該当するmapファイルを読み込む
	//　stage1からstage2への画面切り替えを作らなきゃいけない
	int a = reader.GetLines();
	for (int page = 0; page < 16; page++) {
		for (int y = 0; y < HEIGHT; y++) {
			for (int x = 0; x < WIDTH; x++) {
				map[y][page * WIDTH + x] = reader.GetInt(page * 15 + y, x);
			}
		}
	}
	for (int j = 0; j < HEIGHT; j++)
	{
		for (int i = 0; i < WORLD_WIDTH; i++)
		{
			int x = i + ((scroll/CHIP_SIZE+20)/WORLD_WIDTH)*WORLD_WIDTH;

			//	if分でもできるが、複数の設定を行う場合はswitch分のほうがお勧め(HORIKOSHI Masahiro)
			switch (map[j][i])
			{
				// GroundEnemy2＝踏める敵
			case 2:
			{
				GroundEnemy2* enemy2 = Instantiate<GroundEnemy2>();
				enemy2->position.x = x * CHIP_SIZE;
				enemy2->position.y = j * CHIP_SIZE;
			}
			break;

			// Object1＝とげ
			case 3:
			{
				Object1* object1 = Instantiate<Object1>();
				object1->position.x = x * CHIP_SIZE;
				object1->position.y = j * CHIP_SIZE;
			}
			break;

			// JumpEnemy = 跳ねる敵（カンフー）
			case 4:
			{
				JumpEnemy* jumpEnemy = Instantiate<JumpEnemy>();
				jumpEnemy->position.x = x * CHIP_SIZE;
				jumpEnemy->position.y = j * CHIP_SIZE;
				jumpEnemy->basePosition = jumpEnemy->position;
			}
			break;

			// SkyEnemey2 = 上下移動の敵
			case 5:
			{
				SkyEnemy2* enemy2 = Instantiate<SkyEnemy2>();
				enemy2->position.x = x * CHIP_SIZE;
				enemy2->position.y = j * CHIP_SIZE;
			}
			break;
			// Shield = 盾
			case 9:
			{
				Shield* shield = Instantiate<Shield>();
				shield->position.x = x * CHIP_SIZE;
				shield->position.y = j * CHIP_SIZE;
			}
			break;
			}
		}
	}
}
			//	プレイヤー
			//case 9:
			//{
			//	Player* p = Instantiate<Player>();
			//	p->position.x = i * CHIP_SIZE;	//	なぜ100足している？(HORIKOSHI Masahiro)
			//	p->position.y = j * CHIP_SIZE;	//	なぜ100足している？(HORIKOSHI Masahiro)
			//}
			//break;

			//	ランダム敵(仮に7としている)
			//case 7:
		 //   {
			//	int rand = GetRand(3);		//	0-3の乱数
			//	//	乱数の結果で敵の出現を変える
			//	switch (rand)
			//	{
			//	case 0:
			//	{
			//		GroundEnemy1* enemy1 = Instantiate<GroundEnemy1>();
			//		enemy1->position.x = i * CHIP_SIZE;
			//		enemy1->position.y = j * CHIP_SIZE;
			//    }
			//	break;
			//	case 1:
			//	{
			//		GroundEnemy2* enemy2 = Instantiate<GroundEnemy2>();
			//		enemy2->position.x = i * CHIP_SIZE;
			//		enemy2->position.y = j * CHIP_SIZE;
			//	}
			//	break;
			//	case 2:
			//	{
			//		SkyEnemy1* enemy3 = Instantiate<SkyEnemy1>();
			//		enemy3->position.x = i * CHIP_SIZE;
			//		enemy3->position.y = j * CHIP_SIZE;
			//	}
			//	break;
			//	case 3:
			//	{
			//		SkyEnemy2* enemy4 = Instantiate<SkyEnemy2>();
			//		enemy4->position.x = i * CHIP_SIZE;
			//		enemy4->position.y = j * CHIP_SIZE;
			//	}
			//	break;
		 //       }
	        

	

	/*backGroundX = 0;
	backGroundY = 0;
	floorX = 300;
	floorY = 520;*/


