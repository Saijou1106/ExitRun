#include "Player.h"
#include "DxLib.h"

int main() {

}
Player::Player() // : playerX(320), playerY(240), jumpCount(0), grounded(true), maxJump(2),jumpPower(-15), gravity(1)
{
	playerX = 320;
	playerY = 240;
	jumpCount = 0;
	grounded = true;
	maxJump = 2;
	jumpPower = -15;
	gravity = 1;

}



void Player::Update()
{
	//�X�y�[�X�L�[�ŃW�����v
	if (CheckHitKey(KEY_INPUT_SPACE) && jumpCount < maxJump) {
		Jump();
	}

	//�d�͂�K�p
	velocityY += gravity;
	playerY = velocityY;

	//�n�ʂɒ��n�������̏���(����Y���W400���n�ʂ��Ƃ���)
	if (playerY >= 400) {
		playerY = 400;
		velocityY = 0;
		onGround();
	}

	//�n�ʂɂ��Ȃ��Ƃ��̓W�����v�񐔂𐧌�
	if (!isOnGround()) {
		grounded = false;
	}
}

void Player::Draw()
{
	//�v���C���[����`�ŕ\���i���W�F�@x, y, �T�C�Y�F32�~32�j
	DrawBox(playerX - 16, playerY - 16, playerX + 16, playerY + 16, GetColor(255, 255, 255), TRUE);
}

//�W�����v����
void Player::Jump()
{
	velocityY = jumpPower; //�W�����v�͂𑬓x�ɔ��f
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
