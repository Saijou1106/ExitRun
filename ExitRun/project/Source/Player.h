#pragma once
#include "../Library/GameObject.h"
#include "Vector2.h"
#include "Shield.h" 
#include <math.h>


class Player : public GameObject
{

public:
	Player();
	~Player();
	VECTOR2 position;

	void Update();
	void Jump();//�W�����v����
	void Draw();
	void DestroyMe();
	bool isOnGround()const;//�n�ʂɂ��邩�ǂ������m�F
	bool isDead;    //�v���C���[�����񂾂��ǂ���
	float velocity;//���x

	bool isJumpUp; //�㏸��
	bool isJumpDown;//���~��
	int jumpUpImage;
	int jumpDownImage;

	

	const float Gravity = 0.5f; //�d��
	float velocityY;	         //Y�����̑��x(��������)
	float ground;                //�n�ʂ̍��W

	int maxJump;                 //�ő�W�����v�񐔁i�Q��j
	int jumpCount;		         //���݂̃W�����v��
	int jumpPower;               //�W�����v��
	bool isWalk;

	int aliveImage;               //�����摜
	int deadImage;                //���S�摜
	int hImage;

	int patternX;				//�\���p�^�[��(�A�j���[�V�����̊G)�̉��̔ԍ�
	int patternY;				//�\���p�^�[���̏c�̔ԍ�	

	int freamcounter;			


	bool grounded;              //�n�ʂɐڂ��Ă��邩�ǂ���
	bool prevSpaceKeyState;     //�O��X�y�[�X�L�[��������Ă��邩

	bool isFollowingPlayer;  // �����v���C���[�ɒǏ]���Ă��邩�̃t���O
	bool isActivePlayer;


	float timer;
	//const float maxTimer = 3.0f;

	VECTOR2 centerPosition;
	VECTOR2 GetCenterPosition();
	VECTOR startposition; // startposition
};


