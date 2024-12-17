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
		// �Q�[���̏����ݒ�
	case GAME_STATE::INTI:
		if (Init() == GAME_STATE::NEXT_STATE)
		{
			gameState = GAME_STATE::GAME_START;
		}
		break;

		// �Q�[���J�n
	case GAME_STATE::GAME_START:
		if (GAME_START() == GAME_STATE::NEXT_STATE)
		{
			gameState = GAME_STATE::START_COUNT;
		}
		break;

		// �Q�[���J�n�J�E���g
	case GAME_STATE::START_COUNT:
		if (START_COUNT() == GAME_STATE::NEXT_STATE)
		{
			gameState = GAME_STATE::RUN_START;
		}
		break;

		// ����̂��n�߂�
	case GAME_STATE::RUN_START:
		if (RUN_START() == GAME_STATE::NEXT_STATE)
		{
			gameState = GAME_STATE::GAME_OVER;
		}
		break;

		// �Q�[���I�[�o�[
	case GAME_STATE::GAME_OVER:
		if (GAME_OVER() == GAME_STATE::NEXT_STATE)
		{
			gameState = GAME_STATE::RESULT;
		}
		break;

		// ���ʕ\��
	case GAME_STATE::RESULT:
		if (RESULT() == GAME_STATE::NEXT_STATE)
		{
			gameState = GAME_STATE::SCORE;
		}
		break;

		// �X�R�A�\��
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

// �eGameState����

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
