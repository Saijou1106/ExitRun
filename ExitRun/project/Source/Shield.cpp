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
	isActiveShield = true; //������ԂŃA�N�e�B�u

	shieldCount = 0, 1, 2, 3;
	shieldCountMax = 3;
	
	
	offsetX = 50.0f;  //�v���C���[���珂�̑��Έʒu�i�������j
	offsetY = 0.0f;  //�v���C���[���珂�̑��Έʒu�i�c�����j
	isFollowingPlayer = false; //������Ԃł̓v���C���[�ɒǏ]���Ȃ�
}

Shield::~Shield()
{
	//DeleteGraph(hImage);
}

void Shield::Update()
{
	//shieldCount = 0;//���̃J�E���g�ŏ���0�ɂ��Ă���
	
	position.x -= 3.5f;//���̈ړ����x

	//if (position.x < -64) {//��ʂ̍��[
	//	position.x = 1280;//��ʉE�[
	//	position.y = rand() % 450;//���̐�����y���W�����܂Ń����_���ŕ\������

	//}
	
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
	//Stage* s = FindGameObject<Stage>();

	if (!isActiveShield) {
		//�V�[���h�������Ȃ�`�悵�Ȃ�
		return;
	}

	if (!isFollowingPlayer) {
		DrawGraph(position.x , position.y, shieldImage, TRUE);
	}
	

	//���̏������ɉ����č���ɏ�����ׂĕ\�����鏈��
	if (shieldCount >= 1) {
		for (int i = 0; i < shieldCount; i++) {
			DrawGraph(10 + i *50, 10, shieldImage, TRUE);

		}
	}

	//���������v���C���[��Ǐ]���Ă���ꍇ�A�v���C���[�̈ʒu�Ɋ�Â��ďc�̈ʒu���X�V
	if (isFollowingPlayer) {
		std::list<Player*> player = FindGameObjects<Player>();
		for (Player* pl : player) {
			//�v���C���[�̈ʒu�Ɋ�Â��ď��̈ʒu���I�t�Z�b�g���g���čX�V
			position.x = pl->position.x + offsetX; //X�����̃I�t�Z�b�g
			position.y = pl->position.y + offsetY; //X�����̃I�t�Z�b�g
			DrawGraph(position.x, position.y, barrierImage, TRUE);
		}
	}

	//	debug
	int width, height;
	GetGraphSize(shieldImage, &width, &height);

	 VECTOR2 SHCenter;//���̒��S���W
	SHCenter.x = position.x + 32;
	SHCenter.y = position.y + 32;//�摜�̒��S���W,�v���C���[�̈ʒu���擾

	DrawCircle(SHCenter.x, SHCenter.y, 32, RGB(0, 0, 0), 0);//�����蔻������ザ��Ȃ��Ē��S����ɂ�
}

//���̒Ǐ]��~���\�b�h
void Shield::stopFollowing()
{
	isFollowingPlayer = false;  // �v���C���[�ւ̒Ǐ]���~
	
}




