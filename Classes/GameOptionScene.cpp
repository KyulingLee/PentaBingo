//
//  GameOptionScene.cpp
//  Pentabingo
//
//  Created by Lee Bong Kyu on 2014. 4. 26..
//
//

#include "GameOptionScene.h"

USING_NS_CC;

CCScene* GameOptionScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameOptionScene *layer = GameOptionScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool GameOptionScene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    //KYULING: 기존에 저장되어 있는 값을 불러온다.
    int effectOptionValue = CCUserDefault::sharedUserDefault()->getIntegerForKey("effectOptionValue");
    std::string effectOptionString;
    
    //KYULING: 초기 설치 시 들어오는 값
    if (effectOptionValue == 0) {
        //초기값이므로 그냥 on으로 하고 on값을 저장한다.
        effectOptionValue = 1;
        CCUserDefault::sharedUserDefault()->setIntegerForKey("effectOptionValue", effectOptionValue);
        
        effectOptionString = "Effect on";
    }
    //KYULING: off로 설정했을 때의 값
    else if(effectOptionValue == 2)
    {
        //off값을 보여준다
        effectOptionString = "Effect off";
    }
    //KYULING: on으로 설정했을 때의 값
    else if(effectOptionValue == 1)
    {
        //on값을 보여준다
        effectOptionString = "Effect on";
    }
    
    //설정값을 메뉴로 만들어낸다.
    CCLabelTTF *effectLabel = CCLabelTTF::create(effectOptionString.c_str(), "Arial", 24);
    CCMenuItemLabel *effectOptionMenuItem = CCMenuItemLabel::create(effectLabel, this, menu_selector(GameOptionScene::effectSettingTapped));
    
    CCMenu *optionMenu = CCMenu::create(effectOptionMenuItem, NULL);
    this->addChild(optionMenu);
    
    //이전 화면으로 돌아가는 버튼을 생성한다.
    CCMenuItemLabel *backMenuItem = CCMenuItemLabel::create(CCLabelTTF::create("back", "Arial", 16), this, menu_selector(GameOptionScene::backButtonTapped));
    CCMenu *backMenu = CCMenu::create(backMenuItem, NULL);
    backMenu->setPosition(ccp(480-50, 270-220));
    this->addChild(backMenu);
    
    return true;
    
}

//KYULING: 사운드 옵션을 설정
void GameOptionScene::effectSettingTapped()
{
    
}

void GameOptionScene::backButtonTapped()
{
    CCDirector::sharedDirector()->popScene();
}