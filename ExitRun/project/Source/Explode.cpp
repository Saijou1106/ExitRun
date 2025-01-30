#include "Explode.h"
#include "Stage.h"


Explode::Explode(VECTOR2 pos)
{
	position = pos;
	hImage = LoadGraph("data/enemyKill.png");
	hitSoundhandle = LoadSoundMem("data/Sound/stepon.mp3");
	timer = 20;
	scale = 0.5f;
}


Explode::~Explode()
{
	DeleteGraph(hImage);
}

void Explode::Update()
{
	scale += 0.2f;
	if (scale >= 1.5f) {
		scale = 1.5f;
	}
	timer--;
	if (timer <= 0) {
		DestroyMe();
	}

	destroyTimer += Time::DeltaTime();
	if (destroyTimer >= destroyTimeLimit)
	{
		if (!nowPlaySE)
		{
			PlaySoundMem(hitSoundhandle, DX_PLAYTYPE_BACK);
			nowPlaySE = true;
		}
		return;
	}
}

void Explode::Draw()
{
	int  sz = (int)(scale * 32.0f);
	Stage* st = FindGameObject<Stage>();
	DrawExtendGraph(position.x - sz - st->scroll, position.y - sz,
		position.x + sz - st->scroll, position.y + sz, hImage, TRUE);
}

