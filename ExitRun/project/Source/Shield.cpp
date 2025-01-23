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
	isActiveShield = true; //������ԂŃA�N�e�B�u

	shieldCount = 0;
	shieldCountMax = 3;
	
	
	offsetX = 50.0f;  //�v���C���[���珂�̑��Έʒu�i�������j
	offsetY = 0.0f;  //�v���C���[���珂�̑��Έʒu�i�c�����j
	isFollowingPlayer = false; //������Ԃł̓v���C���[�ɒǏ]���Ȃ�
}

Shield::~Shield()
{
	DeleteGraph(shieldImage);
	DeleteGraph(barrierImage);

}

void Shield::Update()
{
	//�v���C���[�Ə��̏Փ˔���
	std::list<Player*> player = FindGameObjects<Player>();
	for (Player* pl : player) {

		if (isShield) {
			continue;
		}

		VECTOR2 player = pl->GetCenterPosition();//�v���C���[�̒��S���W
		Stage* s = FindGameObject<Stage>();

		VECTOR2 SHCenter;//���̒��S���W
		SHCenter.x = position.x + 32;
		SHCenter.y = position.y + 32;


		if (CircleHit(player, SHCenter, 32)) {
			isShield = true;          //�����v���C���[�Ɋl�������
			isFollowingPlayer = true; //�����v���C���[�ɒǏ]���n�߂�
			shieldCount++;
		}
	}

}

void Shield::Draw()
{
	Stage* s = FindGameObject<Stage>();

	if (!isActiveShield) {
		//�V�[���h�������Ȃ�`�悵�Ȃ�
		return;
	}

	if (!isFollowingPlayer) {
		DrawGraph(position.x - s->scroll, position.y, shieldImage, TRUE);
	}



	//���������v���C���[��Ǐ]���Ă���ꍇ�A�v���C���[�̈ʒu�Ɋ�Â��ďc�̈ʒu���X�V
	if (isFollowingPlayer) {
		std::list<Player*> player = FindGameObjects<Player>();
		for (Player* pl : player) {
			//�v���C���[�̈ʒu�Ɋ�Â��ď��̈ʒu���I�t�Z�b�g���g���čX�V
			position.x = pl->position.x + offsetX; //X�����̃I�t�Z�b�g
			position.y = pl->position.y + offsetY; //X�����̃I�t�Z�b�g
			DrawGraph(position.x - s->scroll, position.y, barrierImage, TRUE);

		}
	}

	//	debug
	int width, height;
	GetGraphSize(shieldImage , &width, &height);

	 VECTOR2 SHCenter;//���̒��S���W
	SHCenter.x = position.x + 32;
	SHCenter.y = position.y + 32;//�摜�̒��S���W,�v���C���[�̈ʒu���擾

}

//���̒Ǐ]��~���\�b�h
void Shield::stopFollowing()
{
	isFollowingPlayer = false;  // �v���C���[�ւ̒Ǐ]���~
	
}




