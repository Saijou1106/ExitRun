#include "GameOver.h"
#include "../Library/Time.h"
#include "Player.h"
#include "assert.h"

#include <math.h>
#include "DxLib.h"


GameOver::GameOver()
{
	GameOverImage = LoadGraph("data/logo_game_over2.png");
	NextImage = LoadGraph("data/next4.png");
	assert(GameOverImage > 0);
	timer = 0.0f;

	StayOnSceneChange();
}

GameOver::~GameOver()
{
	DeleteGraph(GameOverImage);
}


void GameOver::Update()
{
	timer += 0.19f;
}

void GameOver::Draw()
{
	Player* pl = FindGameObject<Player>();

	if (pl == nullptr) return;
	DrawGraph(200, 100, GameOverImage, TRUE);
	int size = GetFontSize();
	SetFontSize(50);

	if (timer >= 6.0f) {
		SetFontSize(25);
		//  スコア表示　プレイヤーが走り始める原点からの距離の表示
		score = ((pl->position.x - pl->startposition.x) - 1) / 64;
		DrawFormatString(200, 300, GetColor(15, 15, 255), "SCORE:%6d", score);
	/*	DrawGraph(200, 100, GameOverImage, TRUE);*/
		DrawGraph(760, 230, NextImage, TRUE);

	}

	SetFontSize(size);
}