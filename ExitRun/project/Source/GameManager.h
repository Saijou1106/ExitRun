#pragma once
#include "../Library/GameObject.h"

enum class GAME_STATE
{
	INTI = 0, // �Q�[���̏����ݒ�
	GAME_START, // �Q�[���J�n
	START_COUNT, // �Q�[���J�n�J�E���g
	TWO_WAIT, // 2 �\��
	ONE_WAIT, // 1 �\��
	RUN_START, // ����̂��n�߂�
	GAME_OVER, // �Q�[���I�[�o�[
	RESULT, // ���ʕ\��
	SCORE, // �X�R�A�\��

	CONTINUE_STATE = 10,    //  State�p�� 
	NEXT_STATE,             //  ���X�e�[�g�� 
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
	GAME_STATE RUN_START(); // ����̂��n�߂�
	GAME_STATE GAME_OVER(); // �Q�[���I�[�o�[
	GAME_STATE RESULT(); // ���ʕ\��
	GAME_STATE SCORE(); // �X�R�A�\��
};