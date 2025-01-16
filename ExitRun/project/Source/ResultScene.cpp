#include "PlayScene.h"
#include <DxLib.h>
#include "GameManager.h"
#include "ResultScene.h"
#include "GameOver.h"


ResultScene::ResultScene()
{
	HighScore = 0;
}

ResultScene::~ResultScene()
{
}

void ResultScene::Update()
{
	GameOver* go = FindGameObject<GameOver>();
	if (CheckHitKey(KEY_INPUT_N)) {
		SceneManager::ChangeScene("TITLE");
			//SceneManager::ChangeScene("");
	}
}

void ResultScene::Draw()
{
	GameOver* go = FindGameObject <GameOver>();

	int size = GetFontSize();
	SetFontSize(50);

	SetFontSize(25);
	//  スコア表示　プレイヤーが走り始める原点からの距離の表示
	DrawFormatString(200, 300, GetColor(255, 255, 255), "SCORE:%6d",go->score);

	DrawString(200, 500, "PUSU SPACE KEY", GetColor(15, 15, 255));

	SetFontSize(size);

	DrawString(0, 0, "ReslutScene", GetColor(255, 255, 255));
}
