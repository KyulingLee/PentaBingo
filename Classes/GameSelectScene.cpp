//
//  GameSelectScene.cpp
//  Pentabingo
//
//  Created by Lee Bong Kyu on 2014. 4. 26..
//
//

#include "GameSelectScene.h"
#include "BingoGameScene.h"

USING_NS_CC;

CCScene* GameSelectScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameSelectScene *layer = GameSelectScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool GameSelectScene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    //KYULING: 게임 승리방법을 선택하여 방에 입장합니다.
    CCMenuItemLabel *fastModeMenuItem = CCMenuItemLabel::create(CCLabelTTF::create("Fast Mode", "Arial", 24), this, menu_selector(GameSelectScene::fastModeSelected));
    CCMenuItemLabel *manyModeMenuItem = CCMenuItemLabel::create(CCLabelTTF::create("Many Mode", "Arial", 24), this, menu_selector(GameSelectScene::manyModeSelected));
    
    CCMenu *gameModeMenu = CCMenu::create(fastModeMenuItem, manyModeMenuItem, NULL);
    gameModeMenu->alignItemsHorizontallyWithPadding(20);
    this->addChild(gameModeMenu);
    
    //이전 화면으로 돌아가는 버튼을 생성한다.
    CCMenuItemLabel *backMenuItem = CCMenuItemLabel::create(CCLabelTTF::create("back", "Arial", 16), this, menu_selector(GameSelectScene::backButtonTapped));
    CCMenu *backMenu = CCMenu::create(backMenuItem, NULL);
    backMenu->setPosition(ccp(480-50, 270-220));
    this->addChild(backMenu);
    
    return true;
    
}

#pragma mark - button action method

void GameSelectScene::fastModeSelected()
{
    //CCScene *scene = CCTransitionFadeBL::create(1.0f, BingoGameScene::scene());
    CCScene *scene = BingoGameScene::scene();
    CCDirector::sharedDirector()->pushScene(scene);
}

void GameSelectScene::manyModeSelected()
{
    //CCScene *scene = CCTransitionFadeBL::create(1.0f, BingoGameScene::scene());
    CCScene *scene = BingoGameScene::scene();
    CCDirector::sharedDirector()->pushScene(scene);
}

void GameSelectScene::backButtonTapped()
{
    CCDirector::sharedDirector()->popScene();
}
