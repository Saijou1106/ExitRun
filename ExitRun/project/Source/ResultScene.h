#pragma once
#include "../Library/SceneBase.h"

class ResultScene :public SceneBase
{
public:
	ResultScene();
  	~ResultScene();
	void Update()override;
	void Draw()override;
	int hImage;
	float timer;//表示される間の時間
};