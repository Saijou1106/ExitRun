#pragma once
#include "../Library/GameObject.h"

class Player : public GameObject
{
private:
	int playerX;		//�v���C���[��X���W
	int playerY;		//�v���C���[��Y���W
	float velocityY;	//Y�����̑��x(��������)
	bool grounded;      //�n�ʂɂ��邩�ǂ���	
	int maxJump;        //�ő�W�����v�񐔁i�Q��j
	int jumpCount;		//���݂̃W�����v��
	int jumpPower;      //�W�����v��
	int gravity;		//�d��

public:
	Player();

	void Update();
	void Draw();
	void Jump();//�W�����v����
	void onGround();//�n�ʂɂ��邱�Ƃ��Z�b�g
	bool isOnGround()const;//�n�ʂɂ��邩�ǂ������m�F


};


