#include "PlayScene.h"
#include <DxLib.h>
#include "GameManager.h"
#include "ResultScene.h"
#include "GameOver.h"



ResultScene::ResultScene()
{
	hImage = LoadGraph("data/result2.png");
	timer = 0.0f;
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

	timer = 0.19f;

}

void ResultScene::Draw()
{

	GameOver* go = FindGameObject <GameOver>();

	Player* pl = FindGameObject<Player>();

	int size = GetFontSize();
	SetFontSize(50);

	DrawGraph(0, 0, hImage, TRUE);

     //  スコア表示　プレイヤーが走り始める原点からの距離の表示
	DrawFormatString(240, 370, GetColor(25, 25, 25), "%6d", go->score);

	SetFontSize(size);

	
}


