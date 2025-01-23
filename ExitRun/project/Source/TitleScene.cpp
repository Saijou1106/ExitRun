#include "TitleScene.h"
#include <DxLib.h>
#include "HighScore.h"

TitleScene::TitleScene()
{
	hImage = LoadGraph("data/title.png");
	spaceImage = LoadGraph("data/spaceKey.png");
	position.x = 0;
	position.y = 0;
	spaceKey.x = 349;
	spaceKey.y = 129;
	frameCount = 0;
	isVisible = true;
	bkinkInterval = 50;  //点滅間隔

	HighScore* hs = FindGameObject<HighScore>();
	if (hs == NULL)
	{
		hs = Instantiate<HighScore>();
	}
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

	frameCount++;
	if (frameCount >= bkinkInterval) {
		isVisible = !isVisible; //描画フラグ切り替え
		frameCount = 0;         //フレームカウントリセット
	}
}


void TitleScene::Draw()
{
	HighScore* hs = FindGameObject<HighScore>();

	DrawGraph(position.x, position.y,hImage, TRUE);
	if (isVisible) {
		DrawGraph(spaceKey.x, spaceKey.y, spaceImage, TRUE);
	}


	int size = GetFontSize();
	SetFontSize(50);
	DrawFormatString(190, 425, GetColor(255, 255, 255), "%6d m", hs->GetHighScore());
	SetFontSize(size);
}
