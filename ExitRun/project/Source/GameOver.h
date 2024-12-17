#pragma once
#include "../Library/GameObject.h"

class GameOver : public GameObject {
public:
	GameOver();
	~GameOver();
	void Update()override;
	void Draw()override;

	float timer; // 表示される間の時間
	int GameOverImage;
	int score; // スコア
};
