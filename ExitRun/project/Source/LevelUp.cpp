#include "LevelUp.h"
#include "Stage.h"

LevelUp::LevelUp()
{
	hImage = LoadGraph("data/level.png");
	sound = LoadSoundMem("data/sound/LevelUp2.mp3");
	timer = 40;//�����ŕ\�����ԕύX
	scale = 0.5f;

}

LevelUp::~LevelUp()
{
	DeleteGraph(hImage);
}

void LevelUp::Update()
{
	Stage* s = FindGameObject<Stage>();
	
	if (s->betweenScene) {
		scale += 0.2f;
		if (scale >= 1.5f) {
			scale = 1.5f;
		}
		timer--;
		if (timer <= 0) {
			DestroyMe();
		}
	}
	
}

void LevelUp::Draw()
{
	if (timer % 15 < 8) {//15�t���[���̂���8�t���[���\���i�_�ŕ\���j
		Stage* s = FindGameObject<Stage>();
		if (s->betweenScene) {
			int  sz = (int)(scale * 32.0f);
			DrawGraph(360, 130, hImage, TRUE);
		}
	}
}
