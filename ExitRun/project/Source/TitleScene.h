#pragma once
#include "../Library/SceneBase.h"
#include "Vector2.h"

/// <summary>
/// �^�C�g���V�[��
/// 
/// �^�C�g����\�����āA�L�[����������v���C�V�[���Ɉڍs����B
/// </summary>
class TitleScene : public SceneBase
{
private:
	int hImage;
	int spaceImage;
	int frameCount; //�t���[���J�E���^
	bool isVisible; //�摜��`�悷�邩�ǂ����̃t���O
	int bkinkInterval; //�_�ŊԊu
public:
	TitleScene();
	~TitleScene();
	void Update() override;
	void Draw() override;
	VECTOR2 position;
	VECTOR2 spaceKey;
};
