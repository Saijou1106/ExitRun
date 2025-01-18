#include "TitleScene.h"
#include <DxLib.h>

TitleScene::TitleScene()
{
	hImage = LoadGraph("data/title.png");
	spaceImage = LoadGraph("data/spaceKey.png");
	position.x = 0;
	position.y = 0;
	spaceKey.x = 349;
	spaceKey.y = 129;
	frameCount = 0;
	isVisible = true;
	bkinkInterval = 50;  //�_�ŊԊu
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		SceneManager::ChangeScene("PLAY");
	}

	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}

	frameCount++;
	if (frameCount >= bkinkInterval) {
		isVisible = !isVisible; //�`��t���O�؂�ւ�
		frameCount = 0;         //�t���[���J�E���g���Z�b�g
	}
}


void TitleScene::Draw()
{
	DrawGraph(position.x, position.y,hImage, TRUE);
	if (isVisible) {
		DrawGraph(spaceKey.x, spaceKey.y, spaceImage, TRUE);
	}

}
