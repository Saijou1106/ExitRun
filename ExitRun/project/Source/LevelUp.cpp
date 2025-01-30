#include "LevelUp.h"
#include "Stage.h"

LevelUp::LevelUp()
{
	hImage = LoadGraph("data/levelup.png");
	timer = 35;//Ç±Ç±Ç≈ï\é¶éûä‘ïœçX
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
	if (timer % 10 < 3) {
		Stage* s = FindGameObject<Stage>();
		if (s->betweenScene) {
			int  sz = (int)(scale * 32.0f);
			DrawGraph(50, 130, hImage, TRUE);
		}
	}
}
