#include "GameOver.h"
#include "../Library/Time.h"

GameOver::GameOver()
{
	timer = 0.0f;
}

GameOver::~GameOver()
{
}

int score = 1000;

void GameOver::Update()
{
	timer += Time::DeltaTime();
}

void GameOver::Draw()
{
	int size = GetFontSize();
	SetFontSize(50);
	DrawString(200, 200, "GAMEOVER", GetColor(25, 155, 0));
	if (timer >= 1.0f) {
		SetFontSize(25);
		DrawFormatString(200, 300, GetColor(25, 155, 0), "SCORE %06d", score);
	}
	if (timer >= 2.0f) {
		DrawString(200, 500, "PUSU SPACE KEY", GetColor(255, 255, 255));
	}

	SetFontSize(size);
}