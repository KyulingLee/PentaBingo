//
//  BingoGameScene.cpp
//  Pentabingo
//
//  Created by Lee Bong Kyu on 2014. 4. 26..
//
//

#include "BingoGameScene.h"

USING_NS_CC;

CCScene* BingoGameScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    BingoGameScene *layer = BingoGameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool BingoGameScene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    //KYULING: 노드가 그려질 화면을 만든다.
    
    
    //KYULING: 서버에서 불려진 노드가 표시되는 화면을 만든다.
    
    
    //KYULING: 빙고 노드를 그린다
    //스프라이트가 여러개 겹쳐져셔 노드 판 하나를 만든다.
    CCLog("game start");
    
    //이 노드가 5개씩 돌아가게 된다.
    
    //테스트용 -> 스프라이트를 하나 만들고, 선택된 스프라이트의 번호를 로그로 확인해본다.
    CCSprite *nodeSprite = CCSprite::create("bingoNodeBallNormal.png");
    nodeSprite->setTag(11);
    this->addChild(nodeSprite);
    
    CCLabelTTF *numberLabel = CCLabelTTF::create("11", "Arial", 15);
    nodeSprite->addChild(numberLabel);
    
    
    return true;
    
}

