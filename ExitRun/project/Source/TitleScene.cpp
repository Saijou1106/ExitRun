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
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		SceneManager::ChangeScene("PLAY");
	}

	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}
}


void TitleScene::Draw()
{
	DrawGraph(position.x, position.y,hImage, TRUE);
}
