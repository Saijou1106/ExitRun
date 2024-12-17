#include "ResultScene.h"

ResultScene::ResultScene()
{
}

ResultScene::~ResultScene()
{
}

void ResultScene::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		SceneManager::ChangeScene("TITLE");
			//SceneManager::ChangeScene("");
	}
}

void ResultScene::Draw()
{
	DrawString(0, 0, "ReslutScene", GetColor(255, 255, 255));
}
