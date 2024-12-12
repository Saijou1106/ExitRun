#pragma once
#include "Vector2.h"
#include "../Library/GameObject.h"

class SkyEnemy1 : public GameObject
{
public:
	SkyEnemy1();
	~SkyEnemy1();
	void Update() override;
	void Draw() override;

	int hImage;
	VECTOR2 position;
	VECTOR2 speed;

	int movement;
	int timer;

	int isHead(VECTOR2 pos); // ���̔���
	int isRight(VECTOR2 pos);  //�E�̔���
	int isLeft(VECTOR2 pos); // ���̔���
	int isFoot(VECTOR2 pos); // �����̔���

	bool dead;
	bool isAlive; // �G�̐���
};