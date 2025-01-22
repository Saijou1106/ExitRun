#pragma once
#include "../Library/GameObject.h"
#include "Player.h"

enum class GAME_STATE
{
	INTI = 0, // �Q�[���̏����ݒ�
	GAME_START, // �Q�[���J�n
	START_COUNT, // �Q�[���J�n�J�E���g
	TWO_WAIT, // 2 �\��
	ONE_WAIT, // 1 �\��
	START_WAIT,  // START �\��
	RUN_START, // ����̂��n�߂�
	GAME_WAIT,  // �Q�[���Ď�
	MISS,  // �~�X
	GAME_OVER, // �Q�[���I�[�o�[
	RESULT, // ���ʕ\��

	CONTINUE_STATE = 20,    //  State�p�� 
	NEXT_STATE,             //  ���X�e�[�g�� 
	NEXT_MISS, // �~�X������ 
	NEXT_EFFECT,   // �������o�� 
	NEXT_END,    // �Q�[���I����
};
class GameManager : public GameObject
{
private:
	int THREE_HANDLE;
	int TWO_HANDLE;
	int ONE_HANDLE;
	int START_HANDLE;
	int operationImage;

	Player* player;

public:
	GameManager();
	~GameManager();
	void Update() override;
	void Draw() override;

public:
	GAME_STATE gameState;

	bool playable;

	GAME_STATE Init(); // �Q�[���̏����ݒ�
	GAME_STATE GAME_START(); // �Q�[���J�n
	GAME_STATE START_COUNT(); // �Q�[���J�n�J�E���g 3
	GAME_STATE TWO_WAIT(); // 2 �\��
	GAME_STATE ONE_WAIT(); // 1 �\��
	GAME_STATE STRAT_WAIT(); // STRAT �\��
	GAME_STATE RUN_START(); // ����̂��n�߂�
	GAME_STATE GAME_WAIT(); //�Q�[���Ď�
	GAME_STATE MISS(); // �~�X����
	GAME_STATE GAME_OVER(); // �Q�[���I�[�o�[
	GAME_STATE RESULT();
};