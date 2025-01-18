#pragma once
#include "../Library/SceneBase.h"
#include "Vector2.h"

/// <summary>
/// タイトルシーン
/// 
/// タイトルを表示して、キーを押したらプレイシーンに移行する。
/// </summary>
class TitleScene : public SceneBase
{
private:
	int hImage;
	int spaceImage;
	int frameCount; //フレームカウンタ
	bool isVisible; //画像を描画するかどうかのフラグ
	int bkinkInterval; //点滅間隔
public:
	TitleScene();
	~TitleScene();
	void Update() override;
	void Draw() override;
	VECTOR2 position;
	VECTOR2 spaceKey;
};
