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

	score = ((pl->position.x - pl->startposition.x) - 1) / 64;

}