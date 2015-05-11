#include "HelloWorldScene.h"
#include "GameScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// ��ʼ�˵��� ��һ���������ֱ���δ����͵��ʱ��ʾ��ͼƬ
	auto startItem = MenuItemImage::create("ui/game_start.png",
											"ui/game_start.png",
											CC_CALLBACK_1(HelloWorld::menuStartCallback, this));
	startItem->setPosition(Vec2(origin.x + visibleSize.width/4,
								origin.y + visibleSize.height/3 * 2));

    auto closeItem = MenuItemImage::create(
                                           "ui/game_exit.png",
                                           "ui/game_exit.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width/4,
                                origin.y + visibleSize.height/3 * 2 - startItem->getContentSize().height - 30));
	// 
    auto menu = Menu::create(closeItem, startItem, NULL);
    // ���˵����뵱ǰ��
	menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

	// ��ʼ����
    auto startBackground = Sprite::create("ui/start_background.png");

	// ���þ����������Ļ��λ�ã���������ϵ��
    startBackground->setPosition(Vec2(visibleSize.width/2 + origin.x, 0));

	// ����ê��
	startBackground->setAnchorPoint(Vec2(0.5, 0));
	// ���þ����Tag��֮�����ͨ����ǩ�ҵ�������飬�������������в���
	startBackground->setTag(START_BACKGROUD);
	// ������������ӵ����С����еڶ�������0�����ÿɼ�����Ȩ����ֵԽС����ȨԽС������������ľ��������Ȩ������ʱ�����ᱻ�ڵ�ס
    this->addChild(startBackground, 0);

    return true;
}
// ��ʼ��Ϸ
void HelloWorld::menuStartCallback(Ref* pSender)
{
	auto scene = GameScene::createScene();
	auto gameScene = TransitionFade::create(1.0f, scene);
	Director::getInstance()->replaceScene(gameScene);
}
// ������Ϸ
void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
