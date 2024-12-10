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
	void stopFollowing(); //�Ǐ]��~���\�b�h
	
	int shieldImage;
	int barrierImage;
	VECTOR2 speed;	   //���̑��x
	VECTOR2 position;  //���̈ʒu
	bool isShield;     //�v���C���[������ێ�
	int shieldCount;  //���̏����J�E���g
	int shieldCountMax; //���̍ő及����
	bool isActiveShield;   


private:
	

	//���̈ʒu���v���C���[�ɒǏ]�����邽�߂̑��ΓI�ȃI�t�Z�b�g
	float offsetX;
	float offsetY;
	bool isFollowingPlayer;  // �����v���C���[�ɒǏ]���Ă��邩�̃t���O
	

	




};