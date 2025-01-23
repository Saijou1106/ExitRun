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
	SceneManager::ChangeScene("TITLE"); // 起動が終わったらTitleを表示


}

void BootScene::Draw()
{
}
