#pragma once
#include "../Library/GameObject.h"

enum class GAME_STATE
{
	INTI = 0, // ゲームの初期設定
	GAME_START, // ゲーム開始
	START_COUNT, // ゲーム開始カウント
	RUN_START, // 走るのを始める
	GAME_OVER, // ゲームオーバー
	RESULT, // 結果表示
	SCORE, // スコア表示

	CONTINUE_STATE = 10,    //  State継続 
	NEXT_STATE,             //  次ステートへ 
	NEXT_EFFECT,   // 消し演出へ 
	NEXT_END,    // ゲーム終了へ
};
class GameManager : public GameObject
{
public:
	GameManager();
	~GameManager();
	void Update() override;
	void Draw() override;

private:
	GAME_STATE gameState;

	GAME_STATE Init(); // ゲームの初期設定
	GAME_STATE GAME_START(); // ゲーム開始
	GAME_STATE START_COUNT(); // ゲーム開始カウント
	GAME_STATE RUN_START(); // 走るのを始める
	GAME_STATE GAME_OVER(); // ゲームオーバー
	GAME_STATE RESULT(); // 結果表示
	GAME_STATE SCORE(); // スコア表示
};