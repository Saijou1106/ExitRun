#pragma once
#include "../Library/GameObject.h"

class GameOver : public GameObject {
public:
	GameOver();
	~GameOver();
	void Update()override;
	void Draw()override;
	float timer;//�\�������Ԃ̎���
	int GameOverImage;
	int NextImage;
	int score;
};

