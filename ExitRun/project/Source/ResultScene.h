#pragma once
#include "../Library/SceneBase.h"

class ResultScene : public SceneBase
{
public:
	ResultScene();
	~ResultScene();
	void Update() override;
	void Draw() override;

	float timer; // �\�������Ԃ̎���

	int HighScore; // �n�C�X�R�A
};