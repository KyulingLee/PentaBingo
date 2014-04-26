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
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    //배경을 만들어준다.
    CCSprite *backgroundSprite = CCSprite::create("WoodFine.png");
    backgroundSprite->setAnchorPoint(ccp(0, 0));
    backgroundSprite->setScaleX(visibleSize.width / backgroundSprite->getContentSize().width);
    backgroundSprite->setScaleY(320 / backgroundSprite->getContentSize().height);
    //backgroundSprite->cocos2d::CCNode::setPosition(ccp(0, 50));
    this->addChild(backgroundSprite);
    
    //노드 배치를 랜덤으로 만든다
    for (int row = 1; row <= 5; row++) {
        
        for (int col = 1; col <= 5; col++) {
RETRY:
            bingoBoard[row-1][col-1] = rand()%15 + 1 + 15*(col-1);
            CCLog("row: %d, col: %d, data: %d",row, col, bingoBoard[row-1][col-1]);
            //bool checkSameData = false;
            
            if (col >= 2) {
                CCLog("-----");
                for (int i=1; i <= row-1; i++) {
                    CCLog("compare");
                    CCLog("row: %d, col: %d, data: %d", row, i, bingoBoard[i-1][col-1]);
                    
                    if (bingoBoard[row-1][col-1] == bingoBoard[i-1][col-1]) {
                        CCLog("동일 값 검색 완료");
                        goto RETRY;
                    }
                }
                CCLog("-----");
            }
            
        }
    }
    
    //로그 출력을 위한 임시
    for (int i=0; i<5; i++) {
        CCLog("%d %d %d %d %d",bingoBoard[i][0],bingoBoard[i][1],bingoBoard[i][2],bingoBoard[i][3],bingoBoard[i][4]);
    }
    
    //KYULING: 노드가 그려질 화면을 만든다.
    
    
    //KYULING: 빙고 노드를 그린다
    //스프라이트가 여러개 겹쳐져셔 노드 판 하나를 만든다.
    CCLog("game start");
    
    //이 노드가 5개씩 돌아가게 된다.
    
    //테스트용 -> 스프라이트를 하나 만들고, 선택된 스프라이트의 번호를 로그로 확인해본다.
    CCSprite *nodeSprite = CCSprite::create("bingoShowingBall.png");
    //nodeSprite->setPosition(ccp(200, 200));
    
    //this->addChild(nodeSprite);
    
    CCLabelTTF *numberLabel = CCLabelTTF::create("11", "Arial", 15);
    numberLabel->setPosition(ccp(12, 12));
    nodeSprite->addChild(numberLabel);
    
    
    CCMenuItemSprite *nodeItem = CCMenuItemSprite::create(nodeSprite, nodeSprite);
    nodeItem->setTag(11);
    nodeItem->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    
    CCMenu * nodeMenu = CCMenu::create(nodeItem, NULL);
    this->addChild(nodeMenu);
    
    return true;
    
}

void BingoGameScene::nodeSelect(CCNode *node)
{
    CCLog("tapped!");
    
    CCMenuItemSprite *sprite = (CCMenuItemSprite *)node;
    
    CCLog("tag: %d",sprite->getTag());
    
}

