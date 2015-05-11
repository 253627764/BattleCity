#include "cocos2d.h"
//#include "TankSprite.h"
class  Joystick : public cocos2d::Sprite
{
public:
	virtual bool init();
	virtual void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event);
	virtual void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event);
	virtual void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event);
	void setJoystick(cocos2d::Vec2 point);
	CREATE_FUNC(Joystick);
	float getVelocity();  
	cocos2d::Vec2 getDirection();
private:
	void showJoystick();
	void hideJoystick();
	void updateJoystick(cocos2d::Touch *touch);
	int _pJoystickr;  
	int _pJoystickR;	// ҡ�˰뾶
	cocos2d::Sprite *_pJoystick;	//ҡ��
	cocos2d::Sprite *_pJoystickBg; //ҡ�˱���
	cocos2d::Vec2 _start; // ҡ������λ��
	cocos2d::Vec2 _end; //ҡ�˵�ǰλ��
};

