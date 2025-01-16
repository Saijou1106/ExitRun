#include "GameManager.h"
#include "Player.h"

GameManager::GameManager()
{
	gameState = GAME_STATE::INTI;
	THREE_HANDLE = LoadGraph("data/game_start_3.png");
	TWO_HANDLE = LoadGraph("data/game_start_2.png");
	ONE_HANDLE = LoadGraph("data/game_start_1.png");
	START_HANDLE = LoadGraph("data/game_start_logo1 .png");
	playable = false;
}

GameManager::~GameManager()
{
	DeleteGraph(THREE_HANDLE);
	DeleteGraph(TWO_HANDLE);
	DeleteGraph(ONE_HANDLE);
	DeleteGraph(START_HANDLE);
}

void GameManager::Update()
{
	Player* pl = FindGameObject<Player>();

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
			gameState = GAME_STATE::START_WAIT;
		}
		break;

		// strat 表示
	case GAME_STATE::START_WAIT:
		if (STRAT_WAIT() == GAME_STATE::NEXT_STATE)
		{
			gameState = GAME_STATE::RUN_START;
		}
		break;

		// 走るのを始める
	case GAME_STATE::RUN_START:
		if (RUN_START() == GAME_STATE::NEXT_STATE)
		{
			playable = true;
			gameState =  GAME_STATE::GAME_WAIT;
		}
		break;

		// ゲーム監視
	case GAME_STATE::GAME_WAIT:
		switch (GAME_WAIT())
		{
		 // ミス
		case GAME_STATE::NEXT_MISS:
				gameState = GAME_STATE::MISS;
				break;
		}
		break;

		// ミス処理
	case GAME_STATE::MISS:
		if (MISS() == GAME_STATE::MISS)
		{
			gameState = GAME_STATE::GAME_OVER;
		}

		// ゲームオーバー
	case GAME_STATE::GAME_OVER:
		if (GAME_OVER() == GAME_STATE::NEXT_STATE)
		{
				gameState = GAME_STATE::RESULT;
		}
		break;

	case GAME_STATE::RESULT:
		if (RESULT() == GAME_STATE::NEXT_STATE)
		{
			if (CheckHitKey(KEY_INPUT_SPACE))
			{
				SceneManager::ChangeScene("RESULT");
			}

			if (CheckHitKey(KEY_INPUT_T))
			{
				SceneManager::ChangeScene("TITLE");
			}
		}
		break;
	}
}
	// 結果表示

void GameManager::Draw()
{
	Player* pl = FindGameObject<Player>();

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
	case GAME_STATE::START_WAIT:
		DrawGraph(380, 100, START_HANDLE, TRUE);
		break;
	case GAME_STATE::RUN_START:
		break;
	case GAME_STATE::GAME_WAIT:
		break;
	case GAME_STATE::GAME_OVER:
		DrawString(0, 700, "gameover", GetColor(255, 255, 255));
		break;
	case GAME_STATE::RESULT:
		DrawString(0, 700, "reslut", GetColor(255, 255, 255));
		break;
	case GAME_STATE::CONTINUE_STATE:
		break;
	case GAME_STATE::NEXT_STATE:
		break;
	case GAME_STATE::NEXT_EFFECT:
		break;
	case GAME_STATE::NEXT_END:
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

GAME_STATE GameManager::STRAT_WAIT()
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

GAME_STATE GameManager::GAME_WAIT()
{
	Player* pl = FindGameObject<Player>();

	GAME_STATE result = GAME_STATE::GAME_WAIT;

	int size = GetFontSize();

	SetFontSize(45);
	int score = (pl->position.x - pl->startposition.x) /64 ;
	DrawFormatString(900, 10, GetColor(15, 15, 255), "SCORE:%6d", score);

	// プレイヤーが死んだ場合ミス処理へ
	if (pl->isDead)
	{
		result = GAME_STATE::NEXT_MISS;
	}

	SetFontSize(size);

	return result;
}

GAME_STATE GameManager::MISS()
{
	GAME_STATE result = GAME_STATE::NEXT_STATE;
	WaitTimer(1000);
	return result;
}


GAME_STATE GameManager::GAME_OVER()
{
	GAME_STATE result = GAME_STATE::GAME_OVER;

	playable = false;
		
	result = GAME_STATE::NEXT_STATE;
	return result;
}

GAME_STATE GameManager::RESULT()
{
	GAME_STATE result = GAME_STATE::NEXT_STATE;
	result = GAME_STATE::NEXT_STATE;

	return result;
}

