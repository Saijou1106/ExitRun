#pragma once
#include "../Library/GameObject.h"
#include "Vector2.h"

class Player : public GameObject
{
private:
	
	float velocityY;	         //Y�����̑��x(��������)
	float ground;                //�n�ʂ̍��W
	     
	int maxJump;                 //�ő�W�����v�񐔁i�Q��j
	int jumpCount;		         //���݂̃W�����v��
	int jumpPower;               //�W�����v��

	int hImage;                   //�摜

	bool grounded;                //�n�ʂɐڂ��Ă��邩�ǂ���
	bool prevSpaceKeyState;       //�O��X�y�[�X�L�[��������Ă��邩

public:
	Player();
	VECTOR2 position;
	void Update();
	void Jump();//�W�����v����
	void Draw();
	bool isOnGround()const;//�n�ʂɂ��邩�ǂ������m�F

	float velocity;//���x
	
	
	
	


};


