#pragma once
#include "../Library/GameObject.h"
#include "VECTOR2.h"
#include "Enemy.h"
#include "Player.h"

class GroundEnemy1: public Enemy
{
private:
	int hImage;
	
	int timer;
	bool attacking;		//�v���C���[�ɓ˓�
	bool dead;			//���񂾂�true
	bool isShield;       //�v���C���[������ێ�
	int deadCounter;    //����ł鎞��
	int hitSoundHandle; // �T�E���h�n���h��(hit)

public:
	GroundEnemy1();
	~GroundEnemy1();

	void Update();
	void Draw();
	VECTOR2 speed;
	VECTOR2 position;
	VECTOR2 getPosition() const override;
};

