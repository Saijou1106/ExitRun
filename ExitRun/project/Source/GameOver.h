#pragma once
#include "../Library/GameObject.h"

class GameOver : public GameObject {
public:
	GameOver();
	~GameOver();
	void Update()override;
	void Draw()override;
	float timer;//•\Ž¦‚³‚ê‚éŠÔ‚ÌŽžŠÔ
	int GameOverImage;
	int NextImage;
	int score;
};

