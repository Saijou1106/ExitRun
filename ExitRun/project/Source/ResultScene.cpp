#include "PlayScene.h"
#include <DxLib.h>
#include "GameManager.h"
#include "ResultScene.h"
#include "GameOver.h"
#include "HighScore.h"


ResultScene::ResultScene()
{
	hImage = LoadGraph("data/result1.png");
	sound = LoadSoundMem("data/Sound/ResultScene.mp3");
	sound2 = LoadSoundMem("data/Sound/buttom2.mp3");
	timer = 0.0f;

	HighScore* hs = FindGameObject<HighScore>();
	if(hs == NULL)
	{
		hs = Instantiate<HighScore>();
	}

	GameOver* go = FindGameObject <GameOver>();
	hs->SetHighScore(go->score);

	PlaySoundMem(sound, DX_PLAYTYPE_BACK);
};

ResultScene::~ResultScene()
{
}

void ResultScene::Update()
{
	

	GameOver* go = FindGameObject<GameOver>();
	if (CheckHitKey(KEY_INPUT_N)) {
		PlaySoundMem(sound2, DX_PLAYTYPE_BACK);
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

	GameManager* gm = FindGameObject<GameManager>();

	int size = GetFontSize();
	SetFontSize(50);

	DrawGraph(0, 0, hImage, TRUE);

	DrawFormatString(240, 370, GetColor(0, 65, 0), "%6d m", go->score);

	DrawFormatString(750, 370, GetColor(0, 65, 0), "%6d m", hs->GetHighScore());

	SetFontSize(size);
}

void ResultScene::CheckHighScore()
{
	GameManager* gm = FindGameObject<GameManager>();
	GameOver* go = FindGameObject<GameOver>();
	HighScore* hs = FindGameObject<HighScore>();
	if (go->score > hs->GetHighScore())
	{
		hs->SetHighScore(go->score);
	}
}




