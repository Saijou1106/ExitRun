#include "PlayScene.h"
#include <DxLib.h>
#include "Player.h"
#include "Stage.h"
#include "GroundEnemy1.h"
#include "Screen.h"
#include "SkyEnemy1.h"
#include "SkyEnemy2.h"
#include "GroundEnemy2.h"
#include "Shield.h" 
#include "JumpEnemy.h"

#include "GameManager.h"
#include "Object1.h"


PlayScene::PlayScene()
{
	Instantiate<Stage>();
	Instantiate<Player>();
	Instantiate<GroundEnemy2>();
	Instantiate<SkyEnemy2>();
	Instantiate<Shield>();
	Instantiate<JumpEnemy>();

	Instantiate<GameManager>();
	Instantiate<Object1>();

}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TITLE");
	}
	SceneBase::Update();
}

void PlayScene::Draw()
{
	SceneBase::Draw();

	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}
