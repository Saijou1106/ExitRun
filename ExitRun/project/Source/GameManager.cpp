#include "GameManager.h"
#include "Player.h"

GameManager::GameManager()
{
	gameState = GAME_STATE::INTI;
	THREE_HANDLE = LoadGraph("data/game_start_3.png");
	TWO_HANDLE = LoadGraph("data/game_start_2.png");
	ONE_HANDLE = LoadGraph("data/game_start_1.png");
	START_HANDLE = LoadGraph("data/game_start_logo2 .png");
	playable = false;
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
			gameState = GAME_STATE::TWO_WAIT;
		}
		break;

		// 2 表示
	case GAME_STATE::TWO_WAIT:
		if (TWO_WAIT() == GAME_STATE::NEXT_STATE)
		{
			gameState = GAME_STATE::ONE_WAIT;
		}
		break;

		// 1 表示
	case GAME_STATE::ONE_WAIT:
		if (ONE_WAIT() == GAME_STATE::NEXT_STATE)
		{
			gameState = GAME_STATE::RUN_START;
		}
		break;

		// 走るのを始める
	case GAME_STATE::RUN_START:
		if (RUN_START() == GAME_STATE::NEXT_STATE)
		{
			playable = true;
			gameState = GAME_STATE::GAME_OVER;
		}
		break;

		// ゲームオーバー
	case GAME_STATE::GAME_OVER:
		switch (GAME_OVER())
		{
			gameState = GAME_STATE::RESULT;
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
}
		// 結果表示

void GameManager::Draw()
{
	switch (gameState)
	{
	case GAME_STATE::INTI:
		break;
	case GAME_STATE::GAME_START:
		break;
	case GAME_STATE::START_COUNT:
		DrawGraph(550, 100, THREE_HANDLE, TRUE);
		break;
	case GAME_STATE::TWO_WAIT:
		DrawGraph(550, 100, TWO_HANDLE, TRUE);
		break;
	case GAME_STATE::ONE_WAIT:
		DrawGraph(550, 100, ONE_HANDLE, TRUE);
		break;
	case GAME_STATE::RUN_START:
		DrawGraph(300, 100, START_HANDLE, TRUE);
		break;
	case GAME_STATE::GAME_OVER:
		break;
	case GAME_STATE::RESULT:
		break;
	case GAME_STATE::SCORE:
		break;
	case GAME_STATE::CONTINUE_STATE:
		break;
	case GAME_STATE::NEXT_STATE:
		break;
	case GAME_STATE::NEXT_EFFECT:
		break;
	case GAME_STATE::NEXT_END:
		break;
	default:
		break;
	}
}

// 各GameState処理

GAME_STATE GameManager::Init()
{
	GAME_STATE result = GAME_STATE::CONTINUE_STATE;
	result = GAME_STATE::NEXT_STATE;

	// 1秒間待つ
	WaitTimer(1000);
	return result;
}

GAME_STATE GameManager::GAME_START()
{
	GAME_STATE result = GAME_STATE::CONTINUE_STATE;
	result = GAME_STATE::NEXT_STATE;

	// 1秒間待つ
	WaitTimer(1000);
	return result;
}

GAME_STATE GameManager::START_COUNT()
{
	GAME_STATE result = GAME_STATE::CONTINUE_STATE;
	result = GAME_STATE::NEXT_STATE;

	// 1秒間待つ
	WaitTimer(1000);
	return result;
}

GAME_STATE GameManager::TWO_WAIT()
{
	GAME_STATE result = GAME_STATE::CONTINUE_STATE;
	result = GAME_STATE::NEXT_STATE;

	// 1秒間待つ
	WaitTimer(1000);
	return result;
}

GAME_STATE GameManager::ONE_WAIT()
{
	GAME_STATE result = GAME_STATE::CONTINUE_STATE;
	result = GAME_STATE::NEXT_STATE;

	// 1秒間待つ
	WaitTimer(1000);
	return result;
}

GAME_STATE GameManager::RUN_START()
{
	GAME_STATE result = GAME_STATE::CONTINUE_STATE;
	result = GAME_STATE::NEXT_STATE;

	// 1秒間待つ
	WaitTimer(1000);
	return result;
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
