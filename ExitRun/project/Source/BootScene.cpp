#include "BootScene.h"
#include "../Library/SceneManager.h"
#include "GameOver.h"
<<<<<<< HEAD
#include "GameManager.h"
=======
>>>>>>> origin/konno

BootScene::BootScene()
{
	GameOver* go = new GameOver();
<<<<<<< HEAD
	GameManager* gm = new GameManager();
=======
>>>>>>> origin/konno
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
