#include "Stage.h"
#include "DxLib.h"
#include "Player.h"
#include "Shield.h"
#include "CsvReader.h"
#include "Screen.h"
#include "../ImGui/imgui.h"

//	data�t�H���_�ɂ���csv��ǂݍ��ޕ��@�Ȃ炱���͕s�v(HORIKOSHI Masahiro)
#if false
#include "stage1.h"
#include "stage2.h"
#include "stage3.h"
#include "stage4.h"
#include "stage5.h"
#endif

//	�G�𐶐����邽�߂ɒǉ�(HORIKOSHI Masahiro)
#include "GroundEnemy1.h"
#include "GroundEnemy2.h"
#include "SkyEnemy1.h"
#include "SkyEnemy2.h"
#include "Object1.h"
#include "JumpEnemy.h"


//	�`�b�v�P�̑傫��
const int CHIP_SIZE = 64;

//	�e�}�b�vcsv�t�@�C�������`(HORIKOSHI Masahiro)
//	���L�t�@�C�����̓T���v���Ȃ̂ŁA�K�X�ύX���Ă��������B
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
	// ���p�̉摜�ǂݍ���
	floorImage = LoadGraph("data/floor3.png");
	////	�u���b�N�p�摜�ǂݍ���(HORIKOSHI Masahiro)
	//blockImage = LoadGraph("data/floor1.png");
	//	�w�ichip�p�摜�ǂݍ���(HORIKOSHI Masahiro)
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

			//	if���ł��ł��邪�A�����̐ݒ���s���ꍇ��switch���̂ق���������(HORIKOSHI Masahiro)
			switch (map[j][i])
			{
				//	��
				case 1:
					DrawRectGraph(x,y, 0, 0, CHIP_SIZE, CHIP_SIZE, floorImage, TRUE);
					break;

					// GroundEnemy2�����߂�G
				case 2:
				{
					DrawRectGraph(x, y, 0, 0, CHIP_SIZE, CHIP_SIZE, backChipImage, TRUE);
					//GroundEnemy2* enemy2 = Instantiate<GroundEnemy2>();
					//enemy2->position.x = i * CHIP_SIZE;
					//enemy2->position.y = j * CHIP_SIZE;
				}
				break;

				// Object1���Ƃ�
				case 3:
				{
					DrawRectGraph(x, y, 0, 0, CHIP_SIZE, CHIP_SIZE, backChipImage, TRUE);
					//Object1* object1 = Instantiate<Object1>();
					//object1->position.x = i * CHIP_SIZE;
					//object1->position.y = j * CHIP_SIZE;
				}
				break;

				// JumpEnemy = ���˂�G�i�J���t�[�j
				case 4:
				{
					DrawRectGraph(x, y, 0, 0, CHIP_SIZE, CHIP_SIZE, backChipImage, TRUE);
					//JumpEnemy* jumpEnemy = Instantiate<JumpEnemy>();
					//jumpEnemy->position.x = i * CHIP_SIZE;
					//jumpEnemy->position.y = j * CHIP_SIZE;
				}
				break;

				// SkyEnemey2 = �㉺�ړ��̓G
				case 5:
				{
					DrawRectGraph(x, y, 0, 0, CHIP_SIZE, CHIP_SIZE, backChipImage, TRUE);
					//SkyEnemy2* enemy2 = Instantiate<SkyEnemy2>();
					//enemy2->position.x = i * CHIP_SIZE;
					//enemy2->position.y = j * CHIP_SIZE;
				}
				break;
				// Shield = ��
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

	//�Ȃ��߁H

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

	//CsvReader reader("data/��.csv");
	CsvReader reader(mapFile[st]);		//	Map�ԍ��ɊY������map�t�@�C����ǂݍ���
	//�@stage1����stage2�ւ̉�ʐ؂�ւ������Ȃ��Ⴂ���Ȃ�
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

			//	if���ł��ł��邪�A�����̐ݒ���s���ꍇ��switch���̂ق���������(HORIKOSHI Masahiro)
			switch (map[j][i])
			{
				// GroundEnemy2�����߂�G
			case 2:
			{
				GroundEnemy2* enemy2 = Instantiate<GroundEnemy2>();
				enemy2->position.x = x * CHIP_SIZE;
				enemy2->position.y = j * CHIP_SIZE;
			}
			break;

			// Object1���Ƃ�
			case 3:
			{
				Object1* object1 = Instantiate<Object1>();
				object1->position.x = x * CHIP_SIZE;
				object1->position.y = j * CHIP_SIZE;
			}
			break;

			// JumpEnemy = ���˂�G�i�J���t�[�j
			case 4:
			{
				JumpEnemy* jumpEnemy = Instantiate<JumpEnemy>();
				jumpEnemy->position.x = x * CHIP_SIZE;
				jumpEnemy->position.y = j * CHIP_SIZE;
				jumpEnemy->basePosition = jumpEnemy->position;
			}
			break;

			// SkyEnemey2 = �㉺�ړ��̓G
			case 5:
			{
				SkyEnemy2* enemy2 = Instantiate<SkyEnemy2>();
				enemy2->position.x = x * CHIP_SIZE;
				enemy2->position.y = j * CHIP_SIZE;
			}
			break;
			// Shield = ��
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
			//	�v���C���[
			//case 9:
			//{
			//	Player* p = Instantiate<Player>();
			//	p->position.x = i * CHIP_SIZE;	//	�Ȃ�100�����Ă���H(HORIKOSHI Masahiro)
			//	p->position.y = j * CHIP_SIZE;	//	�Ȃ�100�����Ă���H(HORIKOSHI Masahiro)
			//}
			//break;

			//	�����_���G(����7�Ƃ��Ă���)
			//case 7:
		 //   {
			//	int rand = GetRand(3);		//	0-3�̗���
			//	//	�����̌��ʂœG�̏o����ς���
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


