#include "Stage.h"
#include "DxLib.h"
#include "Player.h"
#include "Shield.h"
#include "CsvReader.h"
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

//	�s�v�Ȃ̂ŃR�����g�A�E�g(HORIKOSHI Masahiro)
#if false
const int WIDTH = 17;
const int HEIGHT = 14;
class stage
{
public:
	Stage();
	~Stage();
	void Draw();
private:
	int map[HEIGHT][WIDTH];
	int backGroundImage;
	int floorImage;
	int backGroundX, backGroundY;
	int floorX, floorY;
	int scroll;
};
#endif

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
	// 0 = stage1 / 1 = stage2 / 3 = stage4 / 4 = stage5
	// stage1����stage2�ւ̉�ʐ؂�ւ��̃v���O�����K�{
	int mapNo = 0;
	CsvReader reader(mapFile[mapNo]);//	Map�ԍ��ɊY������map�t�@�C����ǂݍ���



#if false;
	// �X�e�[�W2�Ɉړ��imapNo��1�ɕύX�j
	int mapNo = 1;  
	CsvReader reader2(mapFile[mapNo]);  // �V�����}�b�v��ǂݍ���

	// �X�e�[�W3�Ɉړ��imapNo��2�ɕύX�j
	int mapNo = 2;
	CsvReader reader3(mapFile[mapNo]);

	// stage4�Ɉړ�
	int mapNo = 3;
	CsvReader reader4(mapFile[mapNo]);

	// stage5�Ɉړ�
	int mapNo = 4;
	CsvReader reader5(mapFile[mapNo]);
#endif

	backGroundImage = LoadGraph("data/background2.png");
	// ���p�̉摜�ǂݍ���
	floorImage = LoadGraph("data/floor2.png");
	
	//	�u���b�N�p�摜�ǂݍ���(HORIKOSHI Masahiro)
	blockImage = LoadGraph("data/floor1.png");
	//	�w�ichip�p�摜�ǂݍ���(HORIKOSHI Masahiro)
	backChipImage = LoadGraph("data/backchip.png");

	int a = reader.GetLines();
	for (int y = 0; y < reader.GetLines(); y++) {

		if (y < 12)
		{
			for (int x = 0; x < reader.GetColumns(y); x++) {
				map1[y][x] = reader.GetInt(y, x);
			}
		}
		if ((y >= 15 ) && (y < 27))
		{
			for (int x = 0; x < reader.GetColumns(y); x++) {
				map2[y-15][x] = reader.GetInt(y, x);
			}
		}
		if ((y >= 30) && (y < 42))
		{
			for (int x = 0; x < reader.GetColumns(y); x++) {
				map3[y-30][x] = reader.GetInt(y, x);
			}
		}
		if ((y >= 45) && (y < 57))
		{
			for (int x = 0; x < reader.GetColumns(y); x++) {
				map4[y-45][x] = reader.GetInt(y, x);
			}
		}
		if ((y >= 60) && (y < 72))
		{
			for (int x = 0; x < reader.GetColumns(y); x++) {
				map5[y-60][x] = reader.GetInt(y, x);
			}
		}
		if ((y >= 75) && (y < 87))
		{
			for (int x = 0; x < reader.GetColumns(y); x++) {
				map6[y-75][x] = reader.GetInt(y, x);
			}
		}
		if ((y >= 90) && (y < 102))
		{
			for (int x = 0; x < reader.GetColumns(y); x++) {
				map7[y-90][x] = reader.GetInt(y, x);
			}
		}
		if ((y >= 105) && (y < 117))
		{
			for (int x = 0; x < reader.GetColumns(y); x++) {
				map8[y-105][x] = reader.GetInt(y, x);
			}
		}
		if ((y >= 120) && (y < 132))
		{
			for (int x = 0; x < reader.GetColumns(y); x++) {
				map9[y-120][x] = reader.GetInt(y, x);
			}
		}
		if ((y >= 135) && (y < 147))
		{
			for (int x = 0; x < reader.GetColumns(y); x++) {
				map10[y-135][x] = reader.GetInt(y, x);
			}
		}
		if ((y >= 150) && (y < 162))
		{
			for (int x = 0; x < reader.GetColumns(y); x++) {
				map11[y-150][x] = reader.GetInt(y, x);
			}
		}
		if ((y >= 165) && (y < 177))
		{
			for (int x = 0; x < reader.GetColumns(y); x++) {
				map12[y-165][x] = reader.GetInt(y, x);
			}
		}
		if ((y >= 180) && (y < 192))
		{
			for (int x = 0; x < reader.GetColumns(y); x++) {
				map13[y-180][x] = reader.GetInt(y, x);
			}
		}
		if ((y >= 195) && (y < 207))
		{
			for (int x = 0; x < reader.GetColumns(y); x++) {
				map14[y-195][x] = reader.GetInt(y, x);
			}
		}
		if ((y >= 210) && (y < 222))
		{
			for (int x = 0; x < reader.GetColumns(y); x++) {
				map15[y-210][x] = reader.GetInt(y, x);
			}
		}
		if ((y >= 225) && (y < 237))
		{
			for (int x = 0; x < reader.GetColumns(y); x++) {
				map16[y-225][x] = reader.GetInt(y, x);
			}
		}
#if false
		for (int x = 0; x < reader.GetColumns(y); x++) {
			map[y][x] = reader.GetInt(y, x);
		}
#endif
	}

	//	map1�`map16���Amap�ɃR�s�[����(�������A���Ȃ���)
	for (int i = 0; i < 16; i++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			for (int x = 0; x < WIDTH; x++)
			{
				switch (i)
				{
					case 0:
						map[y][x] = map1[y][x];
						break;
					case 1:
						map[y][x+(WIDTH * i)] = map2[y][x];
						break;
					case 2:
						map[y][x + (WIDTH * i)] = map3[y][x];
						break;
					case 3:
						map[y][x + (WIDTH * i)] = map4[y][x];
						break;
					case 4:
						map[y][x + (WIDTH * i)] = map5[y][x];
						break;
					case 5:
						map[y][x + (WIDTH * i)] = map6[y][x];
						break;
					case 6:
						map[y][x + (WIDTH * i)] = map7[y][x];
						break;
					case 7:
						map[y][x + (WIDTH * i)] = map8[y][x];
						break;
					case 8:
						map[y][x + (WIDTH * i)] = map9[y][x];
						break;
					case 9:
						map[y][x + (WIDTH * i)] = map10[y][x];
						break;
					case 10:
						map[y][x + (WIDTH * i)] = map11[y][x];
						break;
					case 11:
						map[y][x + (WIDTH * i)] = map12[y][x];
						break;
					case 12:
						map[y][x + (WIDTH * i)] = map13[y][x];
						break;
					case 13:
						map[y][x + (WIDTH * i)] = map14[y][x];
						break;
					case 14:
						map[y][x + (WIDTH * i)] = map15[y][x];
						break;
					case 15:
						map[y][x + (WIDTH * i)] = map16[y][x];
						break;
				}
			}
		}
	}

	for (int j = 0; j < HEIGHT; j++)
	{
		for (int i = 0; i < WIDTH; i++)
		{
#if false
			if (map[j][i] == 9)
			{
				Player* p = Instantiate<Player>();
				p->position.x = 100 + i * 40;
				p->position.y = 100 + j * 40;
			}
#endif
			//	if���ł��ł��邪�A�����̐ݒ���s���ꍇ��switch���̂ق���������(HORIKOSHI Masahiro)
			switch (map[j][i])
			{
				// GroundEnemy1
				case 3:
				{
					GroundEnemy1* enemy1 = Instantiate<GroundEnemy1>();
					enemy1->position.x = i * CHIP_SIZE;
					enemy1->position.y = j * CHIP_SIZE;
				}
				break;

				// GroundEnemy2
				case 4:
				{
					GroundEnemy2* enemy2 = Instantiate<GroundEnemy2>();
					enemy2->position.x = i * CHIP_SIZE;
					enemy2->position.y = j * CHIP_SIZE;
				}
				break;

				// SkyEnemey1
				case 5:
				{
					SkyEnemy1* enemy1 = Instantiate<SkyEnemy1>();
					enemy1->position.x = i * CHIP_SIZE;
					enemy1->position.y = j * CHIP_SIZE;
				}
				break;

				// SkyEnemey2
				case 6:
				{
					SkyEnemy2* enemy2 = Instantiate<SkyEnemy2>();
					enemy2->position.x = i * CHIP_SIZE;
					enemy2->position.y = i * CHIP_SIZE;
				}
				break;

				//	�v���C���[
				case 9:
					{
						Player* p = Instantiate<Player>();
						p->position.x = 100 + i * CHIP_SIZE;	//	�Ȃ�100�����Ă���H(HORIKOSHI Masahiro)
						p->position.y =  100 + j * CHIP_SIZE;	//	�Ȃ�100�����Ă���H(HORIKOSHI Masahiro)
					}
					break;
				//	�����_���G(����7�Ƃ��Ă���)
				case 7:
					{
						int rand = GetRand(3);		//	0-3�̗���
						//	�����̌��ʂœG�̏o����ς���
						switch (rand)
						{
							case 0:
								{
									GroundEnemy1* enemy1 = Instantiate<GroundEnemy1>();
									enemy1->position.x = i * CHIP_SIZE;
									enemy1->position.y = j * CHIP_SIZE;
								}
								break;
							case 1:
								{
									GroundEnemy2* enemy2 = Instantiate<GroundEnemy2>();
									enemy2->position.x = i * CHIP_SIZE;
									enemy2->position.y = j * CHIP_SIZE;
								}
								break;
							case 2:
								{
									SkyEnemy1* enemy3 = Instantiate<SkyEnemy1>();
									enemy3->position.x = i * CHIP_SIZE;
									enemy3->position.y = j * CHIP_SIZE;
								}
								break;
							case 3:
								{
									SkyEnemy2* enemy4 = Instantiate<SkyEnemy2>();
									enemy4->position.x = i * CHIP_SIZE;
									enemy4->position.y = j * CHIP_SIZE;
								}
								break;
						}
					}
					break;
			}
		}
	}
	backGroundX = 0;
	backGroundY = 0;
	floorX = 300;
	floorY = 520;

	backGroundImage = LoadGraph("data/background2.png");
	floorImage = LoadGraph("data/floor3.png");
	backGroundX = 0;
	backGroundY = 0;

	
	scroll = 2;
	//for (int j = 0; j < HEIGHT; j++) {
	//	for (int i = 0; i < WIDTH; i++) {
	//		if (map[j][i] == 9) {//9��������v���C���[
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

	/*for (int j = 0; j < HEIGHT; j++) {

	}*/
	// �u���b�N = 2
	for (int j = 0; j < HEIGHT; j++)
	{
		int y = j * CHIP_SIZE;
		//for (int i = 0; i < WIDTH; i++)
		for (int i = 0; i < WORLD_WIDTH; i++)
		{
			int x = i * CHIP_SIZE;
#if false
			if (map[j][i] == 1)
				DrawRectGraph(x - scroll,y, 0, 0, 40, 40, floorImage, TRUE);
#endif
			//	if���ł��ł��邪�A�����̐ݒ���s���ꍇ��switch���̂ق���������(HORIKOSHI Masahiro)
			switch (map[j][i])
			{
				//	��
				case 1:
					DrawRectGraph(x - scroll,y, 0, 0, CHIP_SIZE, CHIP_SIZE, floorImage, TRUE);
					break;
				//	�u���b�N
				case 2:
					DrawRectGraph(x - scroll,y, 0, 0, CHIP_SIZE, CHIP_SIZE, floorImage, TRUE);
					break;
				//	�w�iChip(�G�z�u�����Ƃ���ɂ��w�i�`�b�v��u���悤�ɕύX...HORIKOSHI Masahiro)
				default:
					DrawRectGraph(x - scroll,y, 0, 0, CHIP_SIZE, CHIP_SIZE, backChipImage, TRUE);
					break;
			}
		}
	}
#if false
	DrawGraph(backGroundX - scroll , backGroundY, backGroundImage , TRUE);

	DrawGraph(floorX - scroll , floorY, floorImage, TRUE);
#endif
}

int Stage::IsWallUp(VECTOR2 pos)
{
	int i = (pos.x - 100) / 40;
	int j = (pos.y - 100) / 40;
	if (map[j][i] == 1)
	{
		int push = ((int)pos.x - 100) % 40 + 1;
		return push;
	}
	return 0;
}

	//DrawGraph(backGroundX - scroll , backGroundY, backGroundImage , TRUE);

	//for(int j = 0; j < HEIGHT; j++) {
	//	int y = j * 64 + 100;
	//	for (int i = 0; i < WIDTH; i++) {
	//		int x = i * 64 + 100;
	//		if (map[j][i] == 1) {//1��������n��
	//			DrawGraph(x- scroll, y, floorImage, TRUE);
	//		}
	//	}
	//}
	
//}

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


