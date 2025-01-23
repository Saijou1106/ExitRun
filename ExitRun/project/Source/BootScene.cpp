#include "BootScene.h"
#include "../Library/SceneManager.h"
#include "GameOver.h"
#include "GameManager.h"


BootScene::BootScene()
{
	GameOver* go = new GameOver();
	GameManager* gm = new GameManager();
}

BootScene::~BootScene()
{
}

void BootScene::Update()
{
	SceneManager::ChangeScene("TITLE"); // ‹N“®‚ªI‚í‚Á‚½‚çTitle‚ğ•\¦


}

void BootScene::Draw()
{
}
