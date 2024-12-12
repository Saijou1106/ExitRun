#include "PlayScene.h"
#include <DxLib.h>
#include "Player.h"
#include "Stage.h"
#include "GroundEnemy1.h"
#include "Screen.h"
#include "SkyEnemy1.h"
#include "SkyEnemy2.h"
#include "GroundEnemy2.h"
#include "GameOver.h"

PlayScene::PlayScene()
{
	Instantiate<Stage>();
	Instantiate<Player>();
	Instantiate<GroundEnemy1>();
	Instantiate<GroundEnemy2>();
	Instantiate<SkyEnemy1>();
	Instantiate<SkyEnemy2>();
	
	//groundEnemy1 = Instantiate<GroundEnemy1>();

	Instantiate<Fader>();
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TITLE");
	}
}

void PlayScene::Draw()
{
	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}
