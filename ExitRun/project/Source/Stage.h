#pragma once
#include "../Library/GameObject.h"
#include "Vector2.h"

//	dataフォルダにあるcsvを読み込む方法ならここで定義(HORIKOSHI Masahiro)
//const int WIDTH = 50;
//const int HEIGHT = 234;
const int WIDTH = 18;
const int HEIGHT = 12;
const int WORLD_WIDTH = WIDTH * 16;

class Stage : public GameObject
{

public:
	Stage();
	~Stage();
	void Draw();
	int IsWallUp(VECTOR2 pos);
	int IsWallDown(VECTOR2 pos);
	int IsWallRight(VECTOR2 pos);
	int IsWallLeft(VECTOR2 pos);

	int scroll;

	int backGroundImage;
	int backGroundX;
	int backGroundY;
#if false
	int map1;
	int map2;
	int map3;
	int map4;
	int map5;
	int map6;
	int map7;
	int map8;
	int map9;
	int map10;
	int map11;
	int map12;
	int map13;
	int map14;
	int map15;
	int map16;
#endif
	int floorImage;
	int floorX;
	int floorY;

	//	ブロック用画像ハンドル(HORIKOSHI Masahiro)
	int blockImage;
	//	背景chip用画像ハンドル(HORIKOSHI Masahiro)
	int backChipImage;

	//	dataフォルダにあるcsvを読み込む方法ならここで定義(HORIKOSHI Masahiro)
	int map[HEIGHT][WORLD_WIDTH];

	int map1[HEIGHT][WIDTH];
	int map2[HEIGHT][WIDTH];
	int map3[HEIGHT][WIDTH];
	int map4[HEIGHT][WIDTH];
	int map5[HEIGHT][WIDTH];
	int map6[HEIGHT][WIDTH];
	int map7[HEIGHT][WIDTH];
	int map8[HEIGHT][WIDTH];
	int map9[HEIGHT][WIDTH];
	int map10[HEIGHT][WIDTH];
	int map11[HEIGHT][WIDTH];
	int map12[HEIGHT][WIDTH];
	int map13[HEIGHT][WIDTH];
	int map14[HEIGHT][WIDTH];
	int map15[HEIGHT][WIDTH];
	int map16[HEIGHT][WIDTH];
};

