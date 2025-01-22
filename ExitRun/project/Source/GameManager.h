#pragma once
#include "../Library/GameObject.h"
#include "Player.h"

enum class GAME_STATE
{
	INTI = 0, // ゲームの初期設定
	GAME_START, // ゲーム開始
	START_COUNT, // ゲーム開始カウント
	TWO_WAIT, // 2 表示
	ONE_WAIT, // 1 表示
	START_WAIT,  // START 表示
	RUN_START, // 走るのを始める
	GAME_WAIT,  // ゲーム監視
	MISS,  // ミス
	GAME_OVER, // ゲームオーバー
	RESULT, // 結果表示

	CONTINUE_STATE = 20,    //  State継続 
	NEXT_STATE,             //  次ステートへ 
	NEXT_MISS, // ミス処理へ 
	NEXT_EFFECT,   // 消し演出へ 
	NEXT_END,    // ゲーム終了へ
};
class GameManager : public GameObject
{
private:
	int THREE_HANDLE;
	int TWO_HANDLE;
	int ONE_HANDLE;
	int START_HANDLE;
	int operationImage;

	Player* player;

public:
	GameManager();
	~GameManager();
	void Update() override;
	void Draw() override;

public:
	GAME_STATE gameState;

	bool playable;

	GAME_STATE Init(); // ゲームの初期設定
	GAME_STATE GAME_START(); // ゲーム開始
	GAME_STATE START_COUNT(); // ゲーム開始カウント 3
	GAME_STATE TWO_WAIT(); // 2 表示
	GAME_STATE ONE_WAIT(); // 1 表示
	GAME_STATE STRAT_WAIT(); // STRAT 表示
	GAME_STATE RUN_START(); // 走るのを始める
	GAME_STATE GAME_WAIT(); //ゲーム監視
	GAME_STATE MISS(); // ミス処理
	GAME_STATE GAME_OVER(); // ゲームオーバー
	GAME_STATE RESULT();
};