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
	float timer;//•\Ž¦‚³‚ê‚éŠÔ‚ÌŽžŠÔ
	
	void CheckHighScore();
};