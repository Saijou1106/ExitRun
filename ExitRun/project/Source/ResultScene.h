#pragma once
#include "../Library/SceneBase.h"
#include "HighScore.h"

class ResultScene :public SceneBase
{
public:
	ResultScene();
  	~ResultScene();
	void Update()override;
	void Draw()override;
	int hImage;
	int sound;
	int sound2;
	float timer;//�\�������Ԃ̎���
	
	void CheckHighScore();
};