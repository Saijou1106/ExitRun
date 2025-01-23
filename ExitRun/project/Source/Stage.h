#pragma once
#include "../Library/GameObject.h"
#include "Vector2.h"

//	dataフォルダにあるcsvを読み込む方法ならここで定義(HORIKOSHI Masahiro)
//const int WIDTH = 50;
//const int HEIGHT = 234;
const int WIDTH = 18;
const int HEIGHT = 12;
const int WORLD_WIDTH = WIDTH * 16+20;

class Stage : public GameObject
{

public:
	Stage();
	~Stage();
	void Update() override;
	void Draw();
	int IsWallUp(VECTOR2 pos);
	int IsWallDown(VECTOR2 pos);
	int IsWallRight(VECTOR2 pos);
	int IsWallLeft(VECTOR2 pos);

	int scroll;

	int backGroundImage;
	int backGroundX;
	int backGroundY;
	int floorImage;
	int LevelUpImage;
	int floorX;
	int floorY;

	bool betweenScene;

	//	ブロック用画像ハンドル(HORIKOSHI Masahiro)
	int blockImage;
	//	背景chip用画像ハンドル(HORIKOSHI Masahiro)
	int backChipImage;

	//	dataフォルダにあるcsvを読み込む方法ならここで定義(HORIKOSHI Masahiro)
	int map[HEIGHT][WORLD_WIDTH];
	int mapNo;
	int nextMapNo;
private:
	void CreateStage(int st);
<<<<<<< HEAD
	bool created;
=======
>>>>>>> origin/konno
};

