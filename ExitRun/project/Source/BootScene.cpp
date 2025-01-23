#include "BootScene.h"
#include "../Library/SceneManager.h"
#include "GameOver.h"

BootScene::BootScene()
{
	GameOver* go = new GameOver();
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
