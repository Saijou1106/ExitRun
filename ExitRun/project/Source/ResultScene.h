#pragma once
#include "../Library/SceneBase.h"

class ResultScene : public SceneBase
{
public:
	ResultScene();
	~ResultScene();
	void Update() override;
	void Draw() override;

	float timer; // 表示される間の時間

	int HighScore; // ハイスコア
};