#pragma once
#include "../Library/GameObject.h"
#include "VECTOR2.h"
#include "Enemy.h"
#include "Player.h"

class GroundEnemy2 : public Enemy
{
private:
	

	int timer;
	bool attacking;		//�v���C���[�ɓ˓�
	bool isShield;      //���̕ێ�
	

	VECTOR2 centerPos;
	int scroll;

public:
	int hImage;

	bool dead;			//���񂾂�true
	int deadCounter;    //����ł鎞��
	int deadImage;      //���񂾂Ƃ��̃C���[�W

	GroundEnemy2();
	~GroundEnemy2();

	void Update();
	void Draw();
	void Dead(); // ���񂾂Ƃ��̏���
	VECTOR2 speed;
	VECTOR2 position;
	VECTOR2 getPosition() const override;//GroundEnemy2�ŗLPosition
};


