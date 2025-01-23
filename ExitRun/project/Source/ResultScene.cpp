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
<<<<<<< HEAD



=======
>>>>>>> origin/konno
	hs->SetHighScore(go->score);
};

ResultScene::~ResultScene()
{
}

void ResultScene::Update()
{
<<<<<<< HEAD
=======

>>>>>>> origin/konno
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

<<<<<<< HEAD
	GameManager* gm = FindGameObject<GameManager>();

	int size = GetFontSize();
	SetFontSize(50);

	DrawGraph(0, 0, hImage, TRUE);

	DrawFormatString(240, 370, GetColor(25, 25, 25), "%6d m", go->score);

	DrawFormatString(750, 370, GetColor(25, 25, 25), "%6d m", hs->GetHighScore());
=======
	int size = GetFontSize();
	SetFontSize(50);

	//if (timer >= 1.0f) {
	//	
	//	//  �X�R�A�\���@�v���C���[������n�߂錴�_����̋����̕\��
	//	/*int score = ((pl->position.x - pl->startposition.x) - 1) / 64;*/
	//	DrawFormatString(250, 300, GetColor(255, 255, 255), "SCORE : %6d", go->score);
	//}
	DrawGraph(0, 0, hImage, TRUE);

	DrawFormatString(240, 370, GetColor(25, 25, 25), "%6d", go->score);

	DrawFormatString(750, 370, GetColor(25, 25, 25), "%6d", hs->GetHighScore());
>>>>>>> origin/konno
	SetFontSize(size);
}

void ResultScene::CheckHighScore()
{
<<<<<<< HEAD
	GameManager* gm = FindGameObject<GameManager>();
=======
>>>>>>> origin/konno
	GameOver* go = FindGameObject<GameOver>();
	HighScore* hs = FindGameObject<HighScore>();
	if (go->score > hs->GetHighScore())
	{
		hs->SetHighScore(go->score);
	}

}




