#pragma once
#include "../Library/GameObject.h"
#include "Vector2.h"

class Object :public GameObject {
public:
	virtual ~Object() {}
	virtual VECTOR2 getObjectPosition() const = 0;  // �e�G�̈ʒu���擾����
};