#pragma once
#include "../Library/GameObject.h"
#include "Vector2.h"

class Enemy : public GameObject {
public:
    virtual ~Enemy() {}
    virtual void Update() = 0;  // 各敵で異なる動きを定義するため仮想関数に
    virtual VECTOR2 getPosition() const = 0;  // 各敵の位置を取得する
   
};
