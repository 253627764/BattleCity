#ifndef TANKSPRITE_H
#define TANKSPRITE_H

#include "cocos2d.h"
#include "MapLayer.h"
using namespace cocos2d;

// ����̹�˼���
enum TankLevel
{
	StarOne = 1,
	StarTwo,
	StarThree,
	StarFour
};

// ̹����Ϊ
enum TankAction
{
	UP = 1, // ��������
	LEFT,
	DOWN,
	RIGHT,
	STADY, // ֹͣ�ƶ�
	FIRE   // ����
};

// ̹����
class TankSprite: public Sprite
{
public:
	static const int CollisionMod = 10; // ��ײ����ֵ
	virtual bool init();
	static TankSprite* initwithDelegate(int life, TankLevel level, MapLayer *mLayer);
	CREATE_FUNC(TankSprite);
	bool collisionCheck(Vec2 point);
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();

	void fireAction();

	int _speed; // �ٶ�
	int _life;	// ��������
	TankLevel _level; //̹�˵ȼ�
	TankAction _action;	//̹�˵��ж�
	MapLayer *_maplayer;
private:

};

#endif