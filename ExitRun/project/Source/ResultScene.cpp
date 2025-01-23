#include "PlayScene.h"
#include <DxLib.h>
#include "GameManager.h"
#include "ResultScene.h"
#include "GameOver.h"
#include "HighScore.h"


ResultScene::ResultScene()
{
	hImage = LoadGraph("data/result2.png");
	timer = 0.0f;

	HighScore* hs = FindGameObject<HighScore>();
	if(hs == NULL)
	{
		hs = Instantiate<HighScore>();
	}

	GameOver* go = FindGameObject <GameOver>();
	hs->SetHighScore(go->score);
};

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
	HighScore* hs = FindGameObject<HighScore>();

	GameOver* go = FindGameObject <GameOver>();

	Player* pl = FindGameObject<Player>();

	int size = GetFontSize();
	SetFontSize(50);

	//if (timer >= 1.0f) {
	//	
	//	//  スコア表示　プレイヤーが走り始める原点からの距離の表示
	//	/*int score = ((pl->position.x - pl->startposition.x) - 1) / 64;*/
	//	DrawFormatString(250, 300, GetColor(255, 255, 255), "SCORE : %6d", go->score);
	//}
	DrawGraph(0, 0, hImage, TRUE);

	DrawFormatString(240, 370, GetColor(25, 25, 25), "%6d", go->score);

	DrawFormatString(750, 370, GetColor(25, 25, 25), "%6d", hs->GetHighScore());
	SetFontSize(size);
}

void ResultScene::CheckHighScore()
{
	GameOver* go = FindGameObject<GameOver>();
	HighScore* hs = FindGameObject<HighScore>();
	if (go->score > hs->GetHighScore())
	{
		hs->SetHighScore(go->score);
	}

}




