#pragma once

#include "../Library/GameObject.h"

class HighScore : public GameObject
{
private:
	static const int DEFAULT_HGIH_SCORE = 0; // �N�����̍ō����_

private:
	int highScore;

public:
	HighScore();
	~HighScore();

	int GetHighScore() { return highScore; }
	void SetHighScore(int score){highScore = highScore < score ? score : highScore;}
};