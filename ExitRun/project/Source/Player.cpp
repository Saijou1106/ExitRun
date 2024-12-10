#include "Player.h"
#include "DxLib.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "Screen.h"
#include "../ImGui/imgui.h"
#include "Shield.h"
#include "Enemy.h"


//�W�����v�Q�[�����Ƃ��֗�
const float Gravity = 0.5f;
const float JumpHeight = 64;
const float V0 = -sqrtf(2.0f * Gravity * JumpHeight);
          //V0�͏���


Player::Player()
{
	aliveImage = LoadGraph("data/run1.png");
	deadImage = LoadGraph("data/playerDead.png");
	position.x = 120;
	position.y = 500;
	jumpCount = 0;  //�W�����v�񐔂̏�����
	ground = 500;   //�n�ʂ̈ʒu
	grounded = true;//�n�ʂɂ�����
	maxJump = 2;   //�ő�W�����v��
	jumpPower = 10;//�W�����v��
	velocityY = 0; //Y�����̑��x

	prevSpaceKeyState = false;  //�ŏ��̓X�y�[�X�L�[��������Ă��Ȃ�
	isActivePlayer = true;
	isDead = false;  //�v���C���[�����񂾂��ǂ���

}



void Player::Update()
{
	//ImGui::Begin("hennsuu");
	//ImGui::InputFloat("Timer", &timer);
	//ImGui::End;���l�����

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


	std::list<Enemy*>enemis = FindGameObjects<Enemy>();//���ׂĂ̓G�I�u�W�F�N�g��Enemy*�Ƃ��Ċi�[�����
	std::list<Shield*> shield = FindGameObjects<Shield>();


	for (Enemy* enemy : enemis) 
	{
		VECTOR2 enemyPos = enemy->getPosition();  // �e�G�̈ʒu���擾
		VECTOR2 playerPos = position;            //�v���C���[�̈ʒu���擾

		if (CircleHit(playerPos, enemyPos, 64))//�v���C���[�ƓG������������
		{
			if (shield.size() == 0)//�v���C���[�������������Ă��Ȃ��ꍇ
			{
				DestroyMe();  //�v���C���[�폜
				break;
			}
			else
			{
				int count = 0;//�v���C���[�������ĂȂ����̐��̏�����

				for (Shield* sh : shield)
				{
					if (sh->isShield)//�v���C���[�������������Ă��鎞
					{
						sh->DestroyMe();//������������(�V�[���h������)
						break;
					}
					count++;
				}
				//	�Q�[�����ɏ��͂��邪�v���C���[�͎����ĂȂ�
				if (count >= shield.size())
				{
					//�v���C���[�������������Ă��Ȃ��ꍇ
					isDead = true; //�v���C���[�����񂾂��Ƃ��L�^
					DestroyMe();  //�v���C���[�폜.���񂾊G�ɕς���v���C���[�̈ړ��ʂ͎��񂾂Ƃ���0�ɂ��ĂƂ܂�	
					break;
				}
			}
		}
	}

	if (isDead) {
		//�v���C���[�����񂾂�ړ����Ȃ�
		return;
	}


	
}

void Player::Draw()
{

	if (isDead) {
		//���񂾂Ƃ��̉摜��`��
		DrawGraph(position.x, position.y, deadImage, TRUE);
	}
	else {
		//�����Ă��鎞�̉摜��`��
		DrawGraph(position.x, position.y, aliveImage, TRUE);

	}
	

}

void Player::DestroyMe()
{
	isActivePlayer = false;
	//�v���C���[�̃��X�g����폜
	//delete this;//�����������
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
