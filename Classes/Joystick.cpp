#include "Joystick.h"
using namespace cocos2d;

bool Joystick::init()
{
	bool ret = false;
	do 
	{
		CC_BREAK_IF(!Sprite::init());
		_pJoystickBg =  Sprite::create("ui/joystickBg.png"); //����
		_pJoystick = Sprite::create("ui/joystick.png"); //ҡ��
		this->addChild(_pJoystickBg, 0);
		this->addChild(_pJoystick, 1);
		this->showJoystick();
		_pJoystickR = _pJoystickBg->getContentSize().width / 2;
		_pJoystickr = _pJoystick->getContentSize().width / 2;
		// ע���µ�API
		auto listener = EventListenerTouchAllAtOnce::create();
		listener->onTouchesBegan = CC_CALLBACK_2(Joystick::onTouchesBegan, this);
		listener->onTouchesMoved = CC_CALLBACK_2(Joystick::onTouchesMoved, this);
		listener->onTouchesEnded = CC_CALLBACK_2(Joystick::onTouchesEnded, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
		ret = true;
	} while (0);
	return ret;
}
// ��ʾҡ��
void Joystick::showJoystick()
{
	_pJoystickBg->setVisible(true);
	_pJoystick->setVisible(true);
}
// ����ҡ��
void Joystick::hideJoystick()
{
	_pJoystickBg->setVisible(false);
	_pJoystick->setVisible(false);
}
// ����ҡ���¼��Ĵ���
void Joystick::onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)
{
	std::vector<Touch*>::const_iterator touchIter = touches.begin(); //����������
	Touch *touch = (Touch*)(*touchIter);
	if (_pJoystick->getBoundingBox().containsPoint(touch->getLocation()))
	{
		this->showJoystick();
		updateJoystick(touch);
		CCLOG("***************");
		CCLOG("update touch:%f %f",touch->getLocation().x, touch->getLocation().y);
		return;
	}
}
// �����ƶ��Ĵ���
void Joystick::onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event)
{
	std::vector<Touch*>::const_iterator touchIter = touches.begin(); 
	Touch *touch = (Touch*)(*touchIter);
	if (_pJoystick->isVisible())
	{
		updateJoystick(touch);
		return ;
	}
}
// ���������Ĵ���
void Joystick::onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event)
{
	std::vector<Touch*>::const_iterator touchIter = touches.begin();
	Touch *touch = (Touch*)(*touchIter);
	this->hideJoystick();
	_end = _start;
}
// ҡ�˸�������
void Joystick::setJoystick(Vec2 point)
{
	_start = point;
	_end = point;
	_pJoystickBg->setPosition(point);
	_pJoystick->setPosition(_pJoystickBg->getPosition());
}
// ����ҡ��״̬
void Joystick::updateJoystick(Touch *touch)
{
	Vec2 hit = touch->getLocation(); //�������
	_end = hit;
	float distance = _start.getDistance(hit); 
	Vec2 direction = (hit - _start).getNormalized(); //����ƶ�����
	
	// ��ֹҡ�˳�������
	if (distance < _pJoystickr/2)
	{
		_pJoystick->setPosition(_start + (direction*distance));
	}
	else if(distance > _pJoystickr)
	{
		 _pJoystick->setPosition(_start + (direction*_pJoystickr));
	}
	else
	{
		_pJoystick->setPosition(_start + (direction*_pJoystickr/2));
	}
	
}

float Joystick::getVelocity()
{
	return ccpDistance(_start, _end);
}

Vec2 Joystick::getDirection()
{
	return ccpNormalize(ccpSub(_end, _start));
}