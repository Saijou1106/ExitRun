#include "Shield.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "Screen.h"
#include "Player.h"
#include "DxLib.h"
#include "Enemy.h"
#include "Stage.h"

Shield::Shield()
{
	shieldImage = LoadGraph("data/shield.png");
	barrierImage = LoadGraph("data/shield3.png");
	//position.x = 250;  
	//position.y = 375;

	speed.x = 0.0f;

	isShield = false;
	isActiveShield = true; //初期状態でアクティブ

	shieldCount = 0;
	shieldCountMax = 3;
	
	
	offsetX = 50.0f;  //プレイヤーから盾の相対位置（横方向）
	offsetY = 0.0f;  //プレイヤーから盾の相対位置（縦方向）
	isFollowingPlayer = false; //初期状態ではプレイヤーに追従しない
}

Shield::~Shield()
{
	DeleteGraph(shieldImage);
	DeleteGraph(barrierImage);

}

void Shield::Update()
{
	//プレイヤーと盾の衝突判定
	std::list<Player*> player = FindGameObjects<Player>();
	for (Player* pl : player) {

		if (isShield) {
			continue;
		}

		VECTOR2 player = pl->GetCenterPosition();//プレイヤーの中心座標
		Stage* s = FindGameObject<Stage>();

		VECTOR2 SHCenter;//盾の中心座標
		SHCenter.x = position.x + 32;
		SHCenter.y = position.y + 32;


		if (CircleHit(player, SHCenter, 32)) {
			isShield = true;          //盾がプレイヤーに獲得される
			isFollowingPlayer = true; //盾がプレイヤーに追従し始める
			shieldCount++;
		}
	}

}

void Shield::Draw()
{
	Stage* s = FindGameObject<Stage>();

	if (!isActiveShield) {
		//シールドが無効なら描画しない
		return;
	}

	if (!isFollowingPlayer) {
		DrawGraph(position.x - s->scroll, position.y, shieldImage, TRUE);
	}



	//もし盾がプレイヤーを追従している場合、プレイヤーの位置に基づいて縦の位置を更新
	if (isFollowingPlayer) {
		std::list<Player*> player = FindGameObjects<Player>();
		for (Player* pl : player) {
			//プレイヤーの位置に基づいて盾の位置をオフセットを使って更新
			position.x = pl->position.x + offsetX; //X方向のオフセット
			position.y = pl->position.y + offsetY; //X方向のオフセット
			DrawGraph(position.x - s->scroll, position.y, barrierImage, TRUE);

		}
	}

	//	debug
	int width, height;
	GetGraphSize(shieldImage , &width, &height);

	 VECTOR2 SHCenter;//盾の中心座標
	SHCenter.x = position.x + 32;
	SHCenter.y = position.y + 32;//画像の中心座標,プレイヤーの位置を取得

}

//盾の追従停止メソッド
void Shield::stopFollowing()
{
	isFollowingPlayer = false;  // プレイヤーへの追従を停止
	
}




