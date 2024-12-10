#include "Shield.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "Screen.h"
#include "Player.h"
#include "DxLib.h"
#include "Enemy.h"

Shield::Shield()
{
	hImage = LoadGraph("data/shield.png");
	position.x = 1280;  
	position.y = 500;
	speed.x = 0.0f;

	isShield = false;
	isActiveShield = true; //������ԂŃA�N�e�B�u

	shieldCount = 0, 1, 2, 3;
	shieldCountMax = 3;
	
	
	offsetX = 50.0f;  //�v���C���[���珂�̑��Έʒu�i�������j
	offsetY = -30.0f;  //�v���C���[���珂�̑��Έʒu�i�c�����j
	isFollowingPlayer = false; //������Ԃł̓v���C���[�ɒǏ]���Ȃ�
}

Shield::~Shield()
{
	DeleteGraph(hImage);
}

void Shield::Update()
{
	shieldCount = 0;//���̃J�E���g�ŏ���0�ɂ��Ă���

	position.x -= 3.5f;//���̈ړ����x

	//�v���C���[�Ə��̏Փ˔���
	std::list<Player*> player = FindGameObjects<Player>();
	for (Player* pl : player) {

		VECTOR2 plCenter;//�v���C���[�̒��S���W
		plCenter.x = pl->position.x;
		plCenter.y = pl->position.y;


		VECTOR2 SHCenter;//���̒��S���W
		SHCenter.x = position.x;
		SHCenter.y = position.y;


		if (CircleHit(plCenter, SHCenter, 64)) {

			isShield = true;          //�����v���C���[�Ɋl�������
			isFollowingPlayer = true; //�����v���C���[�ɒǏ]���n�߂�
			shieldCount++;
		}
	}

	//���������v���C���[��Ǐ]���Ă���ꍇ�A�v���C���[�̈ʒu�Ɋ�Â��ďc�̈ʒu���X�V
	if (isFollowingPlayer) {
		std::list<Player*> player = FindGameObjects<Player>();
		for (Player* pl : player) {
			//�v���C���[�̈ʒu�Ɋ�Â��ď��̈ʒu���I�t�Z�b�g���g���čX�V
			position.x = pl->position.x + offsetX; //X�����̃I�t�Z�b�g
			position.y = pl->position.y + offsetY; //X�����̃I�t�Z�b�g
		}
	}


}

void Shield::Draw()
{
	if (!isActiveShield) {
		//�V�[���h�������Ȃ�`�悵�Ȃ�
		return;
	}

	DrawGraph(position.x, position.y, hImage, TRUE);

	//���̏������ɉ����č���ɏ�����ׂĕ\�����鏈��
	if (shieldCount >= 1) {
		for (int i = 0; i < shieldCount; i++) {
			DrawGraph(10 + i *50, 10, hImage, TRUE);

		}
	}

}

//���̒Ǐ]��~���\�b�h
void Shield::stopFollowing()
{
	isFollowingPlayer = false;  // �v���C���[�ւ̒Ǐ]���~
	
}




