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
	barrierImage = LoadGraph("data/barrier.png");
	position.x = 1280;  
	position.y = 575;

	speed.x = 0.0f;

	isShield = false;
	isActiveShield = true; //初期状態でアクティブ

	shieldCount = 0, 1, 2, 3;
	shieldCountMax = 3;
	
	
	offsetX = 50.0f;  //プレイヤーから盾の相対位置（横方向）
	offsetY = 0.0f;  //プレイヤーから盾の相対位置（縦方向）
	isFollowingPlayer = false; //初期状態ではプレイヤーに追従しない
}

Shield::~Shield()
{
	//DeleteGraph(hImage);
}

void Shield::Update()
{
	//shieldCount = 0;//盾のカウント最初は0にしておく
	
	position.x -= 3.5f;//盾の移動速度

	//if (position.x < -64) {//画面の左端
	//	position.x = 1280;//画面右端
	//	position.y = rand() % 450;//この数字はy座標○○までランダムで表示する

	//}
	
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
	//Stage* s = FindGameObject<Stage>();

	if (!isActiveShield) {
		//シールドが無効なら描画しない
		return;
	}

	if (!isFollowingPlayer) {
		DrawGraph(position.x , position.y, shieldImage, TRUE);
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

	//	debug
	int width, height;
	GetGraphSize(shieldImage, &width, &height);

	 VECTOR2 SHCenter;//盾の中心座標
	SHCenter.x = position.x + 32;
	SHCenter.y = position.y + 32;//画像の中心座標,プレイヤーの位置を取得

	DrawCircle(SHCenter.x, SHCenter.y, 32, RGB(0, 0, 0), 0);//当たり判定を左上じゃなくて中心を基準にす
}

//盾の追従停止メソッド
void Shield::stopFollowing()
{
	isFollowingPlayer = false;  // プレイヤーへの追従を停止
	
}




