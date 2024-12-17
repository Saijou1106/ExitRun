#include "GameManager.h"

GameManager::GameManager()
{
	gameState = GAME_STATE::INTI;
}

GameManager::~GameManager()
{
}

void GameManager::Update()
{
	switch (gameState)
	{
		// ゲームの初期設定
	case GAME_STATE::INTI:
		if (Init() == GAME_STATE::NEXT_STATE)
		{
			gameState = GAME_STATE::GAME_START;
		}
		break;

		// ゲーム開始
	case GAME_STATE::GAME_START:
		if (GAME_START() == GAME_STATE::NEXT_STATE)
		{
			gameState = GAME_STATE::START_COUNT;
		}
		break;

		// ゲーム開始カウント
	case GAME_STATE::START_COUNT:
		if (START_COUNT() == GAME_STATE::NEXT_STATE)
		{
			gameState = GAME_STATE::RUN_START;
		}
		break;

		// 走るのを始める
	case GAME_STATE::RUN_START:
		if (RUN_START() == GAME_STATE::NEXT_STATE)
		{
			gameState = GAME_STATE::GAME_OVER;
		}
		break;

		// ゲームオーバー
	case GAME_STATE::GAME_OVER:
		if (GAME_OVER() == GAME_STATE::NEXT_STATE)
		{
			gameState = GAME_STATE::RESULT;
		}
		break;

		// 結果表示
	case GAME_STATE::RESULT:
		if (RESULT() == GAME_STATE::NEXT_STATE)
		{
			gameState = GAME_STATE::SCORE;
		}
		break;

		// スコア表示
	case GAME_STATE::SCORE:
		if (SCORE() == GAME_STATE::NEXT_STATE)
		{
			SceneManager::ChangeScene("TitleScene");
		}
		break;
	}
}

void GameManager::Draw()
{
}

// 各GameState処理

GAME_STATE GameManager::Init()
{
	return GAME_STATE::NEXT_STATE;
}

GAME_STATE GameManager::GAME_START()
{
	return GAME_STATE::NEXT_STATE;
}

GAME_STATE GameManager::START_COUNT()
{
	return GAME_STATE::NEXT_STATE;
}

GAME_STATE GameManager::RUN_START()
{
	return GAME_STATE::NEXT_STATE;
}

GAME_STATE GameManager::GAME_OVER()
{
	return GAME_STATE::NEXT_STATE;
}

GAME_STATE GameManager::RESULT()
{
	return GAME_STATE::NEXT_STATE;
}

GAME_STATE GameManager::SCORE()
{
	return GAME_STATE::NEXT_STATE;
}
