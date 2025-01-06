#pragma once
#include "../Library/GameObject.h"
#include "Vector2.h"
#include "Shield.h" 

class Player : public GameObject
{
private:
	
	
	const float Gravity = 0.5f; //�d��
	float velocityY;	         //Y�����̑��x(��������)
	float ground;                //�n�ʂ̍��W
	     
	int maxJump;                 //�ő�W�����v�񐔁i�Q��j
	int jumpCount;		         //���݂̃W�����v��
	int jumpPower;               //�W�����v��

	int aliveImage;               //�����摜
	int deadImage;                //���S�摜

	bool grounded;                //�n�ʂɐڂ��Ă��邩�ǂ���
	bool prevSpaceKeyState;       //�O��X�y�[�X�L�[��������Ă��邩
	       
	bool isFollowingPlayer;  // �����v���C���[�ɒǏ]���Ă��邩�̃t���O
	bool isActivePlayer; 

	VECTOR2 centerPosition;

public:
	Player();
	VECTOR2 position;
	void Update();
	void Jump();//�W�����v����
	void Draw();
	void DestroyMe();
	bool isOnGround()const;//�n�ʂɂ��邩�ǂ������m�F
	bool isDead;    //�v���C���[�����񂾂��ǂ���
	float velocity;//���x
	
	VECTOR2 startposition;
	
	VECTOR2 GetCenterPosition() { 
		VECTOR2 playerPos = { position.x + centerPosition.x, position.y + centerPosition.x };//�摜�̒��S���W,�v���C���[�̈ʒu���擾
		return playerPos;
	};

};


