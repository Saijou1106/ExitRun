#include "TitleScene.h"
#include <DxLib.h>

TitleScene::TitleScene()
{
	hImage = LoadGraph("data/title.png");
	position.x = 0;
	position.y = 0;
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	if (CheckHitKey(KEY_INPUT_P)) {
		SceneManager::ChangeScene("PLAY");
		//SceneManager::ChangeScene("");
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}
}


void TitleScene::Draw()
{
	DrawGraph(position.x, position.y,hImage, TRUE);
	DrawString(0, 0, "TITLE SCENE", GetColor(255,255,255));
	DrawString(100, 400, "Push [P]Key To Play", GetColor(255, 255, 255));
}
