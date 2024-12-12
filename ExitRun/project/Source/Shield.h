#pragma once
#include "Player.h"
#include "../Library/GameObject.h"
#include "VECTOR2.h"



class Shield : public GameObject
{
public:
	Shield();
	~Shield();
	void Update();
	void Draw()override;
	void stopFollowing(); //追従停止メソッド
	
	int shieldImage;
	int barrierImage;
	VECTOR2 speed;	   //盾の速度
	VECTOR2 position;  //盾の位置
	bool isShield;     //プレイヤーが盾を保持
	int shieldCount;  //盾の所持カウント
	int shieldCountMax; //盾の最大所持数
	bool isActiveShield;   


private:
	

	//盾の位置をプレイヤーに追従させるための相対的なオフセット
	float offsetX;
	float offsetY;
	bool isFollowingPlayer;  // 盾がプレイヤーに追従しているかのフラグ
	

	




};