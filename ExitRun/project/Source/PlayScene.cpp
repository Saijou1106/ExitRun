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
#include "Floor.h"
#include "GameManager.h"

PlayScene::PlayScene()
{
	Instantiate<Stage>();
	Instantiate<Floor>();
	Instantiate<Player>();
	Instantiate<GroundEnemy1>();
	Instantiate<GroundEnemy2>();
	Instantiate<SkyEnemy1>();
	Instantiate<SkyEnemy2>();
	Instantiate<Shield>();

	Instantiate<GameManager>();
	
	//groundEnemy1 = Instantiate<GroundEnemy1>();
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
	Player* pl = FindGameObject<Player>();

}
