#pragma once
#include "../Library/GameObject.h"
#include "Vector2.h"

class Enemy : public GameObject {
public:
    virtual ~Enemy() {}
    virtual void Update() = 0;  // �e�G�ňقȂ铮�����`���邽�߉��z�֐���
    virtual VECTOR2 getPosition() const = 0;  // �e�G�̈ʒu���擾����
   
};
