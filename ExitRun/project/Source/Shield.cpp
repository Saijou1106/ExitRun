#include "Shield.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "Screen.h"
#include "Player.h"
#include "DxLib.h"
#include "Enemy.h"
#include "GameManager.h"

Shield::Shield()
{
	shieldImage = LoadGraph("data/shield.png");
	barrierImage = LoadGraph("data/barrier.png");
	position.x = 1280;  
	position.y = 500;
	speed.x = 0.0f;

	isShield = false;
	isActiveShield = true; //初期状態でアクティブ

	shieldCount = 0, 1, 2, 3;
	shieldCountMax = 3;
	
	
	offsetX = 50.0f;  //プレイヤーから盾の相対位置（横方向）
	offsetY = -30.0f;  //プレイヤーから盾の相対位置（縦方向）
	isFollowingPlayer = false; //初期状態ではプレイヤーに追従しない
}

Shield::~Shield()
{
	//DeleteGraph(hImage);
}

void Shield::Update()
{
	GameManager* gm = FindGameObject<GameManager>();
	if (gm->playable) {
		//shieldCount = 0;//盾のカウント最初は0にしておく

		position.x -= 3.5f;//盾の移動速度

		//プレイヤーと盾の衝突判定
		std::list<Player*> player = FindGameObjects<Player>();
		for (Player* pl : player) {

			if (isShield) {
				continue;
			}

			VECTOR2 player = pl->GetCenterPosition();//プレイヤーの中心座標


			VECTOR2 SHCenter;//盾の中心座標
			SHCenter.x = position.x;
			SHCenter.y = position.y;


			if (CircleHit(player, SHCenter, 64)) {

				isShield = true;          //盾がプレイヤーに獲得される
				isFollowingPlayer = true; //盾がプレイヤーに追従し始める
				shieldCount++;
			}
		}

		////もし盾がプレイヤーを追従している場合、プレイヤーの位置に基づいて縦の位置を更新
		//if (isFollowingPlayer) {
		//	std::list<Player*> player = FindGameObjects<Player>();
		//	for (Player* pl : player) {
		//		//プレイヤーの位置に基づいて盾の位置をオフセットを使って更新
		//		position.x = pl->position.x + offsetX; //X方向のオフセット
		//		position.y = pl->position.y + offsetY; //X方向のオフセット
		//		DrawGraph(position.x, position.y, barrierImage, TRUE);
		//	}
		//}

	}
}

void Shield::Draw()
{
	if (!isActiveShield) {
		//シールドが無効なら描画しない
		return;
	}

	if (!isFollowingPlayer) {
		DrawGraph(position.x, position.y, shieldImage, TRUE);
	}
	

	//盾の所持数に応じて左上に盾を並べて表示する処理
	if (shieldCount >= 1) {
		for (int i = 0; i < shieldCount; i++) {
			DrawGraph(10 + i *50, 10, shieldImage, TRUE);

		}
	}

	//もし盾がプレイヤーを追従している場合、プレイヤーの位置に基づいて縦の位置を更新
	if (isFollowingPlayer) {
		std::list<Player*> player = FindGameObjects<Player>();
		for (Player* pl : player) {
			//プレイヤーの位置に基づいて盾の位置をオフセットを使って更新
			position.x = pl->position.x + offsetX; //X方向のオフセット
			position.y = pl->position.y + offsetY; //X方向のオフセット
			DrawGraph(position.x, position.y, barrierImage, TRUE);
		}
	}


}

//盾の追従停止メソッド
void Shield::stopFollowing()
{
	isFollowingPlayer = false;  // プレイヤーへの追従を停止
	
}




