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
<<<<<<< HEAD

=======
>>>>>>> origin/konno
	float timer;//�\�������Ԃ̎���
	
	void CheckHighScore();
};