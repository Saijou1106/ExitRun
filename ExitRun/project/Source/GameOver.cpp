#include "GameOver.h"
#include "../Library/Time.h"

GameOver::GameOver()
{
	hImage = LoadGraph("data/logo_game_over2.png");
	timer = 0.0f;
}

GameOver::~GameOver()
{
}

int score = 1000;

void GameOver::Update()
{
	timer += 0.1f;
}

void GameOver::Draw()
{
	int size = GetFontSize();
	SetFontSize(50);
	
	if (timer >= 1.0f) {
		SetFontSize(25);
		DrawFormatString(200, 300, GetColor(255, 255, 255), "SCORE %06d", score);
	}
	if (timer >= 2.0f) {
		DrawString(200, 500, "PUSU SPACE KEY", GetColor(255, 255, 255));
	}

	SetFontSize(size);
}