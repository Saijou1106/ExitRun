#include "ResultScene.h"
#include "Player.h"
#include "DxLib.h";

ResultScene::ResultScene()
{
	hImage = LoadGraph("data/result2.png");
	timer = 0.0f;
}

ResultScene::~ResultScene()
{
}

void ResultScene::Update()
{
	if (CheckHitKey(KEY_INPUT_N)) {
		SceneManager::ChangeScene("TITLE");
		//SceneManager::ChangeScene("");
	}

	timer = 0.19f;
}

void ResultScene::Draw()
{
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

