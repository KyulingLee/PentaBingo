#include "HelloWorldScene.h"
#include "GameSelectScene.h"
#include "GameOptionScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    CCLog("visible size - x: %f, y: %f",visibleSize.width, visibleSize.height);
    CCLog("origin - x: %f, y: %f", origin.x, origin.y);
    
    //KYULING: 게임 메뉴로 출력할 메뉴 아이템 생성
    CCMenuItemLabel *startLabel = CCMenuItemLabel::create(CCLabelTTF::create("Game start", "Arial", 18), this, menu_selector(HelloWorld::gameStartMenuTapped));
    CCMenuItemLabel *optionLabel = CCMenuItemLabel::create(CCLabelTTF::create("Game Option", "Arial", 18), this, menu_selector(HelloWorld::gameOptionMenuTapped));
    
    //게임 메뉴 생성
    CCMenu *gameMenu = CCMenu::create(startLabel, optionLabel, NULL);
    gameMenu->alignItemsVerticallyWithPadding(20);
    this->addChild(gameMenu);
    
    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}

//KYULING: 게임 메뉴 처리

void HelloWorld::gameStartMenuTapped()
{
    CCScene *scene = CCTransitionCrossFade::create(1.0f, GameSelectScene::scene());
    CCDirector::sharedDirector()->pushScene(scene);
}

void HelloWorld::gameOptionMenuTapped()
{
    CCScene *scene = GameOptionScene::scene();
    CCDirector::sharedDirector()->pushScene(scene);
}
