#include "Player.h"
#include "DxLib.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "Screen.h"
#include "../ImGui/imgui.h"

//�W�����v�Q�[�����Ƃ��֗�
const float Gravity = 0.4f;
const float JumpHeight = 64;
const float V0 = -sqrtf(2.0f * Gravity * JumpHeight);
          //V0�͏���


Player::Player() 
{
	hImage = LoadGraph("data/run1.png");
	position.x = 120;
	position.y = 500;
	jumpCount = 0;  //�W�����v�񐔂̏�����
	ground = 500;   //�n�ʂ̈ʒu
	grounded = true;//�n�ʂɂ�����
	maxJump = 2;   //�ő�W�����v��
	jumpPower = 8;//�W�����v��
	velocityY = 0; //Y�����̑��x

	prevSpaceKeyState = false;  //�ŏ��̓X�y�[�X�L�[��������Ă��Ȃ�
}



void Player::Update()
{

	//Y���W�̍X�V�i�����ړ��j
	position.y -= velocityY;


	//�n�ʂɂ��Ȃ��������d�͂�K�p
	if(!grounded){
		velocityY -= Gravity;//�d�͂ŉ��Ɉ�������
	}

	
	//�n�ʂɒ��n�������̏���
	if (position.y >= ground) {
		position.y = ground;  //�n�ʂɒ��n
		velocityY = 0;        //Y�̑��x0�ɂ���
		grounded = true;      //�n�ʂɐڂ������
		jumpCount = 0;        //�W�����v�񐔂����Z�b�g
	}


	//�X�y�[�X�L�[�������ꂽ�u�Ԃ�������������
	bool currentSpaceKeyState = CheckHitKey(KEY_INPUT_SPACE);
	if (currentSpaceKeyState && !prevSpaceKeyState) {
		if (grounded  || jumpCount < maxJump) {//�n�ʂɂ��邩�A�W�����v�񐔂��c���Ă����
			Jump();
		}	
	}

	//�O��̃X�y�[�X�L�[�̏�Ԃ��X�V
	prevSpaceKeyState = currentSpaceKeyState;
}

void Player::Draw()
{
	
	//DrawBox(playerX - 16, playerY - 16, playerX + 16, playerY + 16, GetColor(255, 255, 255), TRUE);
	DrawGraph(position.x, position.y, hImage, TRUE);
}

//�W�����v����
void Player::Jump()
{
	velocityY = jumpPower; //������ɗ͂�������
	jumpCount++;		   //�W�����v�񐔂𑝂₷
	grounded = false;      //�W�����v���͒n�ʂɂ��Ȃ��̂�false

}


//�v���C���[���n�ʂɂ��邩�̊m�F
bool Player::isOnGround() const
{
	return grounded;
}
