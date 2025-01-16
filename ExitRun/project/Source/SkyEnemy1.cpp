//#include "SkyEnemy1.h"
//#include "Player.h"
//#include "../Library/GameObject.h"
//#include "Stage.h"
//
//SkyEnemy1::SkyEnemy1()
//{
//	hImage = LoadGraph("data/covid.png");
//	position.x = 780;
//	position.y = 300;
//
//	dead = false;
//}
//
//SkyEnemy1::~SkyEnemy1()
//{
//}
//
//void SkyEnemy1::Update()
//{
//	/*Stage* s = FindGameObject<Stage>();
//	s->scroll += 2;*/
//	position.x -= 3.0f;
//	
//	
//}
//
//void SkyEnemy1::Draw()
//{
//	Stage* s = FindGameObject<Stage>();
//	DrawGraph(position.x, position.y, hImage, true);
//	//	debug
//	int width, height;
//	GetGraphSize(hImage, &width, &height);
//	//DrawCircle(position.x  + width / 2, position.y + height / 2, width / 2, RGB(0, 0, 0), 0);//ìñÇΩÇËîªíËÇç∂è„Ç∂Ç·Ç»Ç≠ÇƒíÜêSÇäÓèÄÇ…Ç∑ÇÈ
//}
//
//VECTOR2 SkyEnemy1::getPosition() const
//{
//	Stage* s = FindGameObject<Stage>();
//	int width, height;
//	GetGraphSize(hImage, &width, &height);
//	VECTOR2 groundEnemyPos = { position.x  + width / 2, position.y + height / 2 };
//	return groundEnemyPos;
//}
