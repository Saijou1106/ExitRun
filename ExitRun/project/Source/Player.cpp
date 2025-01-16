#include "Player.h"
#include "DxLib.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "Screen.h"
#include "Stage.h"
#include "../ImGui/imgui.h"
#include "Shield.h"
#include "Enemy.h"
#include "GroundEnemy1.h"
#include "GroundEnemy2.h"
#include "SkyEnemy1.h"
#include "SkyEnemy2.h"
#include "Stage.h"
#include "GameManager.h"
#include "GameOver.h"
#include "Object1.h"
#include "../ImGui/imstb_rectpack.h"



//�W�����v�Q�[�����Ƃ��֗�
const float Gravity = 0.5f;
const float JumpHeight = 64;
const float V0 = -sqrtf(2.0f * Gravity * JumpHeight);
          //V0�͏���


Player::Player()
{

	deadImage = LoadGraph("data/dead.png");
	hImage = LoadGraph("data/player1.png");
	jumpUpImage = LoadGraph("data/JumpUp.png");
	jumpDownImage = LoadGraph("data/JumpDown.png");

	position.x = 100;
	position.y = 500;
	startposition.x = 100;

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

	
	isJumpDown = false;
	isJumpUp = false;
	bool isWalk = false;


	int width, height;
	GetGraphSize(hImage, &width, &height);
	centerPosition = VECTOR2(width / 2, height / 2);

	timer = 0.0f;

}


Player::~Player()
{
	//DeleteGraph(hImage);
}



void Player::Update()
{

	Stage* s = FindGameObject<Stage>();

	s->scroll += 2;

	GameManager* gm = FindGameObject<GameManager>();

	if (gm->playable) {
		s->scroll += 2;

		position.x += 1.0f;
		//Y���W�̍X�V�i�����ړ��j
		position.y -= velocityY;


		//�n�ʂɂ��Ȃ��������d�͂�K�p
		if (!grounded) {
			velocityY -= Gravity;//�d�͂ŉ��Ɉ�������
			if (velocityY > 0.0f) {
				//�㏸��
				isJumpUp = true;
				isJumpDown = false;
				isWalk = false;
			}
			else {
				isJumpUp = false;
				isJumpDown = true;
				isWalk = false;
			}


		}

		//�n�ʂɒ��n�������̏���
		if (position.y >= ground) {
			isWalk = true;
			position.y = ground;  //�n�ʂɒ��n
			velocityY = 0;        //Y�̑��x0�ɂ���
			grounded = true;      //�n�ʂɐڂ������
			jumpCount = 0;        //�W�����v�񐔂����Z�b�g
		}


		//�X�y�[�X�L�[�������ꂽ�u�Ԃ�������������
		bool currentSpaceKeyState = CheckHitKey(KEY_INPUT_SPACE);
		if (currentSpaceKeyState && !prevSpaceKeyState) {
			if (grounded || jumpCount < maxJump) {//�n�ʂɂ��邩�A�W�����v�񐔂��c���Ă����
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
		VECTOR2 playerPos = GetCenterPosition();//�摜�̒��S���W,�v���C���[�̈ʒu���擾

		std::list<Enemy*>enemis = FindGameObjects<Enemy>();//���ׂĂ̓G�I�u�W�F�N�g��Enemy*�Ƃ��Ċi�[�����
		std::list<Shield*> shield = FindGameObjects<Shield>();
		std::list<GroundEnemy1*>groundenemy1 = FindGameObjects< GroundEnemy1>();
		std::list<GroundEnemy2*>groundenemy2 = FindGameObjects< GroundEnemy2>();
		
		std::list<SkyEnemy2*>skyenemy2 = FindGameObjects< SkyEnemy2>();


		for (Enemy* enemy : enemis)
		{
			VECTOR2 enemyPos = enemy->getPosition();  // �e�G�̈ʒu���擾
			VECTOR2 playerPos = GetCenterPosition();//�摜�̒��S���W,�v���C���[�̈ʒu���擾

			if (CircleHit(playerPos, enemyPos, 48))//�v���C���[�ƓG������������
			{
				int count = 0;//�v���C���[�������ĂȂ����̐��̏�����

				for (Shield* sh : shield)
				{
					if (sh->isShield)//�v���C���[�������������Ă��鎞
					{
						//�G�𓥂񂾏ꍇ
						if (playerPos.y < enemyPos.y)
						{
							if (velocityY < 0.0f)
							{
								Jump();
								velocityY = jumpPower / 1.1; //�G�𓥂񂾎��̏�ɒ��˂鍂��
								grounded = false;
								isDead = false;
								enemy->DestroyMe();
								break;
							}
						}
						//�G�𓥂ވȊO(�s�ʂɓ���������)�œG�ɐG�ꂽ��V�[���h��������
						else {
				    		sh->DestroyMe();//������������(�V�[���h������)
							enemy->DestroyMe();
							break;
						}
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

					if (shield.size() == 0)
					{
						//�v���C���[�������������Ă��Ȃ��ꍇ
						isDead = true; //�v���C���[�����񂾂��Ƃ��L�^
						DestroyMe();  //�v���C���[�폜.���񂾊G�ɕς���v���C���[�̈ړ��ʂ͎��񂾂Ƃ���0�ɂ��ĂƂ܂�	
					}
				}

				if (playerPos.y < enemyPos.y) {
					if (velocityY < 0.0f)
					{
						jumpCount = 1;
						velocityY = jumpPower / 1.1; //�G�𓥂񂾎��̏�ɒ��˂鍂��
						grounded = false;
						isDead = false;
						enemy->DestroyMe();
						break;
					}
				}

			}
		}
	}
	
	if (isDead) {
		//�v���C���[�����񂾂�ړ����Ȃ�
		return;
	}
	
		
	if (isDead) {
		//timer += 0.15f;
		isWalk = false;
		isJumpUp = false;
		isJumpDown = false;
	}

		if (isWalk) {//�����Ă�Ƃ�
			freamcounter += 1;
			if (freamcounter % 10 == 0) {       //10�t���[���Ɉ��摜�o����
				patternX = (patternX + 1) % 4;  //patternX��0�C1�̌�A0�ɂ���
			}
			isJumpUp = false;
			isJumpDown = false;
		}

		std::list<Object1*>object = FindGameObjects< Object1>();

			//�Ƃ��̔���
			for (Object1* ob : object)
			{
				VECTOR2 playerPos = GetCenterPosition();
				VECTOR2 objectPos = ob->getObjectPosition();

				if (CircleHit(playerPos, objectPos, 48))
				{
					for (Shield* sh : shield)
					{
						sh->DestroyMe();
					}
					isDead = true; //�Ƃ��ɐG�ꂽ��V�[���h�������Ă��Ă����Ȃ��Ă��v���C���[�͎��S
					DestroyMe();
					break;
				}

			}
	}
}

void Player::Draw()
{
	if (isDead) {
		//���񂾂Ƃ��̉摜��`��
		DrawGraph(position.x, position.y, deadImage, TRUE);
		Instantiate<GameOver>();
	}
	if(isWalk) {
		//�����Ă��鎞�̉摜��`��
						  // x,   y , ����, ��
		DrawRectGraph(position.x , position.y, patternX*64, patternY*64, 64, 64, hImage, TRUE);
		//DrawRectGraph(position.x , position.y, 0, 0, 64, 64, hImage, TRUE);

	}

						  // x,   y , ����, ��
		DrawRectGraph(position.x , position.y, patternX*64, patternY*64, 64, 64, hImage, TRUE);
		//DrawRectGraph(position.x , position.y, 0, 0, 64, 64, hImage, TRUE);
	
	if (isJumpUp) {
		//�㏸���ɉ�ʐ؂�ւ�
		DrawGraph(position.x ,position.y, jumpUpImage, TRUE);
	}
	if (isJumpDown) {
		//���~���ɉ�ʐ؂�ւ�
		DrawGraph(position.x, position.y, jumpDownImage, TRUE);
	}

	

	 	
	//	debug
	int width, height;
	GetGraphSize(hImage, &width, &height);
	VECTOR2 playerPos = GetCenterPosition();//�摜�̒��S���W,�v���C���[�̈ʒu���擾
	//DrawCircle(playerPos.x , playerPos.y, 32, RGB(0, 0, 0), 0);//�����蔻������ザ��Ȃ��Ē��S����ɂ���
	
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
