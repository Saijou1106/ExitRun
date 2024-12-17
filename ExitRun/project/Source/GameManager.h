#pragma once
#include "../Library/GameObject.h"

enum class GAME_STATE
{
	INTI = 0, // �Q�[���̏����ݒ�
	GAME_START, // �Q�[���J�n
	START_COUNT, // �Q�[���J�n�J�E���g
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
public:
	GameManager();
	~GameManager();
	void Update() override;
	void Draw() override;

private:
	GAME_STATE gameState;

	GAME_STATE Init(); // �Q�[���̏����ݒ�
	GAME_STATE GAME_START(); // �Q�[���J�n
	GAME_STATE START_COUNT(); // �Q�[���J�n�J�E���g
	GAME_STATE RUN_START(); // ����̂��n�߂�
	GAME_STATE GAME_OVER(); // �Q�[���I�[�o�[
	GAME_STATE RESULT(); // ���ʕ\��
	GAME_STATE SCORE(); // �X�R�A�\��
};