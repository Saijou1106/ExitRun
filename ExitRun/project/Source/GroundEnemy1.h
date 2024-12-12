#pragma once
#include "../Library/GameObject.h"
#include "VECTOR2.h"

class GroundEnemy1: public GameObject
{
private:
	int hImage;
	
	int timer;
	bool attacking;		//�v���C���[�ɓ˓�
	bool dead;			//���񂾂�true
	int deadCounter;    //����ł鎞��
	bool fadeStarted;

public:
	GroundEnemy1();
	~GroundEnemy1();

	void Update();
	void Draw();
	VECTOR2 speed;
	VECTOR2 position;

	
};

