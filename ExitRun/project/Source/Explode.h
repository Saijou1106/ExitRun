#pragma once
#include "../Library/GameObject.h"
#include "Vector2.h"

class Explode : public GameObject {
public:
	Explode(VECTOR2 pos);
	~Explode();
	void Update() override;
	void Draw() override;
private:
	int hImage;
	VECTOR2 position;
	float scale;
	int timer;

	int hitSoundhandle;
	void SetHitSoundHandle(int handle) { hitSoundhandle = handle; }
	bool nowPlaySE = false;

	void destroyCountDownTimer();

	float destroyTimer;
	float destroyTimeLimit;
};