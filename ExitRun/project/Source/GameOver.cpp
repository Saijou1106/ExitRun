#include "GameOver.h"
#include "../Library/Time.h"
#include "Player.h"
#include "assert.h"
#include <math.h>

GameOver::GameOver()
{

	GameOverImage = LoadGraph("data/logo_game_over2.png");
	assert(GameOverImage > 0);
	timer = 0.0f;
}

GameOver::~GameOver()
{
}


void GameOver::Update()
{
	timer += 0.19f;
}

void GameOver::Draw()
{
	Player* pl = FindGameObject<Player>();

	DrawGraph(200, 100, GameOverImage, TRUE);
	
	int size = GetFontSize();
	SetFontSize(50);
	
	if (timer >= 1.0f) {
		SetFontSize(25);
		//  スコア表示　プレイヤーが走り始める原点からの距離の表示
		int score = ((pl->position.x - pl->startposition.x) - 1) / 64;
		DrawFormatString(200, 300, GetColor(15, 15, 255), "SCORE:%6d", score);
	}
	if (timer >= 2.0f) {
		DrawString(200, 500, "PUSU SPACE KEY", GetColor(15, 15, 255));
	}

	SetFontSize(size);
}