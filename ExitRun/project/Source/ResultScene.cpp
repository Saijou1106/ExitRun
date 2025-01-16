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

	
	/*SetFontSize(50);*/


	/*DrawString(200, 500, "PUSU SPACE KEY", GetColor(15, 15, 255));

	SetFontSize(size);

	DrawString(0, 0, "ReslutScene", GetColor(255, 255, 255));*/


	Player* pl = FindGameObject<Player>();

	int size = GetFontSize();
	SetFontSize(100);

	if (timer >= 1.0f) {
		
		//  スコア表示　プレイヤーが走り始める原点からの距離の表示
		int score = ((pl->position.x - pl->startposition.x) - 1) / 64;
		DrawFormatString(300, 300, GetColor(0, 120, 0), "%6d", score);
	}
	SetFontSize(size);

	DrawGraph(0, 0, hImage, TRUE);
}


