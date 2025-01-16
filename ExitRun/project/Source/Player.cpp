#include "Player.h"
#include "DxLib.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "Screen.h"
#include "../ImGui/imgui.h"
#include "Shield.h"
#include "Enemy.h"
#include "GroundEnemy1.h"
#include "GroundEnemy2.h"
#include "SkyEnemy1.h"
#include "SkyEnemy2.h"
#include "Stage.h"


//�W�����v�Q�[�����Ƃ��֗�
const float Gravity = 0.5f;
const float JumpHeight = 64;
const float V0 = -sqrtf(2.0f * Gravity * JumpHeight);
          //V0�͏���


Player::Player()
{
	//aliveImage = LoadGraph("data/run1.png");
	deadImage = LoadGraph("data/dead.jpeg");
	hImage = LoadGraph("data/player.png");

	position.x = 120;
	position.y = 575;
	startposition = position;
	patternX = 0;
	patternY = 0;
	freamcounter = 0;

	jumpCount = 0;  //�W�����v�񐔂̏�����
	ground = 575;   //�n�ʂ̈ʒu
	grounded = true;//�n�ʂɂ�����
	maxJump = 2;   //�ő�W�����v��
	jumpPower = 10;//�W�����v��
	velocityY = 0; //Y�����̑��x

	prevSpaceKeyState = false;  //�ŏ��̓X�y�[�X�L�[��������Ă��Ȃ�
	isActivePlayer = true;
	isDead = false;  //�v���C���[�����񂾂��ǂ���
	bool isWalk = true;

	int width, height;
	GetGraphSize(hImage, &width, &height);
	centerPosition = VECTOR2(width / 2, height / 2);
}

Player::~Player()
{
	//DeleteGraph(hImage);
}



void Player::Update()
{
	Stage* s = FindGameObject<Stage>();

	s->scroll += 2;
	position.x += 2.1f;
	int push = 0;
	push = s->IsWallRight(position + VECTOR2(63, 0));
	position.x -= push;
	push = s->IsWallRight(position + VECTOR2(63, 63));
	position.x -= push;

	//Y���W�̍X�V�i�����ړ��j
	position.y -= velocityY;


	//�n�ʂɂ��Ȃ��������d�͂�K�p
	if(!grounded){
		velocityY -= Gravity;//�d�͂ŉ��Ɉ�������
	}

	
	//�n�ʂɒ��n�������̏���
	//if (position.y >= ground) {
	//	position.y = ground;  //�n�ʂɒ��n
	//	velocityY = 0;        //Y�̑��x0�ɂ���
	//	grounded = true;      //�n�ʂɐڂ������
	//	jumpCount = 0;        //�W�����v�񐔂����Z�b�g
	//	onGround = true;
	//}

	if (velocityY <= 0) {
		int push1 = s->IsWallDown(position + VECTOR2(0, 64));
		int push2 = s->IsWallDown(position + VECTOR2(63, 64));
		if (push1 > 0 || push2 > 0) {
			position.y -= max(push1, push2) - 1;
			velocityY = 0;        //Y�̑��x0�ɂ���
			grounded = true;      //�n�ʂɐڂ������
			jumpCount = 0;        //�W�����v�񐔂����Z�b�g
			onGround = true;
		} else {
			grounded = false;      //�n�ʂɐڂ������
			onGround = false;
		}
	} else {
		int push1 = s->IsWallUp(position + VECTOR2(0, 0));
		int push2 = s->IsWallUp(position + VECTOR2(63, 0));
		if (push1 > 0 || push2 > 0) {
			position.y += max(push1, push2);
			velocityY = 0;        //Y�̑��x0�ɂ���
		}
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
	std::list<GroundEnemy1*>groundenemy1 = FindGameObjects< GroundEnemy1>();
	std::list<GroundEnemy2*>groundenemy2 = FindGameObjects< GroundEnemy2>();
	std::list<SkyEnemy1*>skyenemy1 = FindGameObjects< SkyEnemy1>();
	std::list<SkyEnemy2*>skyenemy2 = FindGameObjects< SkyEnemy2>();

	for (Enemy* enemy : enemis) 
	{
		VECTOR2 enemyPos = enemy->getPosition();  // �e�G�̈ʒu���擾
		//int width, height;
		//GetGraphSize(aliveImage, &width, &height);
		//VECTOR2 playerPos = { position.x + centerPosition.x, position.y + centerPosition.x };//�摜�̒��S���W,�v���C���[�̈ʒu���擾
		VECTOR2 playerPos = GetCenterPosition();//�摜�̒��S���W,�v���C���[�̈ʒu���擾

		if (CircleHit(playerPos, enemyPos, 48))//�v���C���[�ƓG������������
		{
			{
  				int count = 0;//�v���C���[�������ĂȂ����̐��̏�����

				 for (Shield* sh : shield)
				{
					if (sh->isShield)//�v���C���[�������������Ă��鎞
					{
						sh->DestroyMe();//������������(�V�[���h������)
						enemy->DestroyMe();
						break;
					}

					count++;

					//	�Q�[�����ɏ��͂��邪�v���C���[�͎����ĂȂ�
					if (count >= shield.size())
					{
						//�v���C���[�������������Ă��Ȃ��ꍇ
						isDead = true; //�v���C���[�����񂾂��Ƃ��L�^
						DestroyMe();  //�v���C���[�폜.���񂾊G�ɕς���v���C���[�̈ړ��ʂ͎��񂾂Ƃ���0�ɂ��ĂƂ܂�	
						break;
					}
				}
				 if (shield.size() == 0)
				 {
					 //�v���C���[�������������Ă��Ȃ��ꍇ
					 isDead = true; //�v���C���[�����񂾂��Ƃ��L�^
					 DestroyMe();  //�v���C���[�폜.���񂾊G�ɕς���v���C���[�̈ړ��ʂ͎��񂾂Ƃ���0�ɂ��ĂƂ܂�	
				 }
			}
		}
	}
	
	if (isDead) {
		//�v���C���[�����񂾂�ړ����Ȃ�
		return;
	}
	
	if (isWalk) {//�����Ă�Ƃ�
		freamcounter += 1;
		if (freamcounter % 7 == 0) {       //10�t���[���Ɉ��摜�o����
			patternX = (patternX + 1) % 2;  //patternX��0�C1�̌�A0�ɂ���
		}
	}
}

void Player::Draw()
{
	Stage* s = FindGameObject<Stage>();

	if (isDead) {
		//���񂾂Ƃ��̉摜��`��
		DrawGraph(position.x - s->scroll , position.y, deadImage, TRUE);
	}
	else {
		//�����Ă��鎞�̉摜��`��
	    //DrawGraph(position.x - s ->scroll, position.y, hImage, TRUE);
	
						  // x,   y , ����, ��
		DrawRectGraph(position.x - s->scroll, position.y, patternX*64, patternY*64, 64, 64, hImage, TRUE);
		//DrawRectGraph(position.x , position.y, 0, 0, 64, 64, hImage, TRUE);

	}

	 	
	//	debug
	int width, height;
	GetGraphSize(hImage, &width, &height);
	VECTOR2 playerPos = GetCenterPosition();//�摜�̒��S���W,�v���C���[�̈ʒu���擾
	DrawCircle(playerPos.x - s->scroll, playerPos.y, 32, RGB(0, 0, 0), 0);//�����蔻������ザ��Ȃ��Ē��S����ɂ���
	
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

VECTOR2 Player::GetCenterPosition()
{
	VECTOR2 playerPos = { position.x  + 32, position.y + 32 };//�摜�̒��S���W,�v���C���[�̈ʒu���擾
	return playerPos;
	
}
