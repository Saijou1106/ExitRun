#include "Player.h"
#include "DxLib.h"
#include "TitleScene.h"
#include "PlayScene.h"


Player::Player() 
{
	hImage = LoadGraph("data/run1.png");
	playerX = 120;
	playerY = 200;
	jumpCount = 0;
	ground = 200;
	grounded = true;
	maxJump = 2;   //�ő�W�����v��
	jumpPower = 5;//�W�����v��
	gravity = 1;   //�d��
	velocityY = 0; //Y�����̑��x

}



void Player::Update()
{

	//Y���W�̍X�V�i��ɓ��������߂Ɍ��Z�j
	playerY -= velocityY;


	//������Ԃł͏d�͂�K�p���Ȃ�
	//if (grounded) {
		//velocityY = 0; //�n�ʂɂ��鎞�͑��x��0�ɐݒ�
	//}
	

	//�n�ʂɂ��Ȃ��������d�͂�K�p
	if(!grounded){
		velocityY -= gravity;
	}

	
	//�n�ʂɒ��n�������̏���
	if (playerY >= ground) {
		playerY = ground;
		velocityY = 0; //Y�̑��x0�ɂ���
		onGround();
	}

	//�X�y�[�X�L�[�ŃW�����v
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		//�n�ʂɂ��邩�A�W�����v�񐔂��P��̂Ƃ�
		if (grounded || (jumpCount <= maxJump)) {
			Jump();//�W�����v����
		}
		
	}
//�W�����v2�񂵂��炻��ȏ�W�����v�ł��Ȃ��悤�ɂ���
	if (jumpCount >= maxJump) {
		jumpCount = maxJump;
	}



	
	//�n�ʂɂ��Ȃ��Ƃ��i�W�����v���j�ɃW�����v�J�E���g��1�������������x�W�����v�ł���
	
}

void Player::Draw()
{
	//�v���C���[����`�ŕ\���i���W�F�@x, y, �T�C�Y�F32�~32�j
	//DrawBox(playerX - 16, playerY - 16, playerX + 16, playerY + 16, GetColor(255, 255, 255), TRUE);
	DrawGraph(playerX, playerY, hImage, TRUE);
}

//�W�����v����
void Player::Jump()
{
	velocityY = jumpPower; //������ɗ͂�������
	jumpCount++;		   //�W�����v�񐔂𑝂₷
	grounded = false;      //�W�����v���͒n�ʂɂ��Ȃ��̂�false

}

//�n�ʂɂ��邱�Ƃ��Z�b�g
void Player::onGround()
{
	grounded = true;
	jumpCount = 0; //�n�ʂɂ�����W�����v�񐔃��Z�b�g
}

//�v���C���[���n�ʂɂ��邩�̊m�F
bool Player::isOnGround() const
{
	return grounded;
}
