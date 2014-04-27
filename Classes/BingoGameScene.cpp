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
    //CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    //배경을 만들어준다.
    CCSprite *backgroundSprite = CCSprite::create("WoodFine.png");
    backgroundSprite->setAnchorPoint(ccp(0, 0));
    backgroundSprite->setScaleX(visibleSize.width / backgroundSprite->getContentSize().width);
    backgroundSprite->setScaleY(320 / backgroundSprite->getContentSize().height);
    //backgroundSprite->cocos2d::CCNode::setPosition(ccp(0, 50));
    this->addChild(backgroundSprite);
    
    //노드 배치를 랜덤으로 만든다
    for (int row = 0; row < 5; row++) {
        
        for (int col = 0; col < 5; col++) {
RETRY:
            bingoBoard[row][col] = rand()%15 + 1 + 15*(col);
            //CCLog("입력 완료-row: %d, col: %d, data: %d",row, col, bingoBoard[row][col]);
            //bool checkSameData = false;
            
            if (row+1 >= 2) {
                
                for (int i=0; i < row; i++) {
                    //CCLog("compare-%d:%d",bingoBoard[row][col], bingoBoard[i][col]);
                    //CCLog("row: %d, col: %d, data: %d", row, i, bingoBoard[i][col]);
                    
                    if (bingoBoard[row][col] == bingoBoard[i][col]) {
                        //CCLog("동일 값 검색 완료");
                        //CCLog("data1: %d",bingoBoard[row-1][col-1]);
                        //CCLog("data2: %d",bingoBoard[i-1][col-1]);
                        goto RETRY;
                    }
                }
                
            }
            
        }
        CCLog("-----");
    }
    
    //KYULING: 로그 출력을 위한 임시
    
    for (int i=0; i<5; i++) {
        CCLog("%d %d %d %d %d",bingoBoard[i][0],bingoBoard[i][1],bingoBoard[i][2],bingoBoard[i][3],bingoBoard[i][4]);
    }
    
    //라벨 출력용 버퍼
    char buffer[10];
    
    CCMenuItemImage *item11 = CCMenuItemImage::create("Color1_small.png", "Color1_small.png");
    item11->setTag(bingoBoard[0][0]);
    item11->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[0][0]);
    CCLabelTTF *label11 = CCLabelTTF::create(buffer, "Arial", 12);
    label11->setPosition(ccp(10, 10));
    item11->addChild(label11);
    
    CCMenuItemImage *item21 = CCMenuItemImage::create("Color1_small.png", "Color1_small.png");
    item21->setTag(bingoBoard[1][0]);
    item21->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[1][0]);
    CCLabelTTF *label21 = CCLabelTTF::create(buffer, "Arial", 12);
    label21->setPosition(ccp(10, 10));
    item21->addChild(label21);
    
    CCMenuItemImage *item31 = CCMenuItemImage::create("Color1_small.png", "Color1_small.png");
    item31->setTag(bingoBoard[2][0]);
    item31->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[2][0]);
    CCLabelTTF *label31 = CCLabelTTF::create(buffer, "Arial", 12);
    label31->setPosition(ccp(10, 10));
    item31->addChild(label31);
    
    CCMenuItemImage *item41 = CCMenuItemImage::create("Color1_small.png", "Color1_small.png");
    item41->setTag(bingoBoard[3][0]);
    item41->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[3][0]);
    CCLabelTTF *label41 = CCLabelTTF::create(buffer, "Arial", 12);
    label41->setPosition(ccp(10, 10));
    item41->addChild(label41);
    
    CCMenuItemImage *item51 = CCMenuItemImage::create("Color1_small.png", "Color1_small.png");
    item51->setTag(bingoBoard[4][0]);
    item51->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[4][0]);
    CCLabelTTF *label51 = CCLabelTTF::create(buffer, "Arial", 12);
    label51->setPosition(ccp(10, 10));
    item51->addChild(label51);
    
    CCMenu *item1Menu = CCMenu::create(item11, item21, item31, item41, item51, NULL);
    item1Menu->alignItemsVerticallyWithPadding(20);
    item1Menu->setPositionX(70);
    this->addChild(item1Menu);

    
    //line 2
    CCMenuItemImage *item12 = CCMenuItemImage::create("Color2_small.png", "Color2_small.png");
    item12->setTag(bingoBoard[0][1]);
    item12->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[0][1]);
    CCLabelTTF *label12 = CCLabelTTF::create(buffer, "Arial", 12);
    label12->setPosition(ccp(10, 10));
    item12->addChild(label12);
    
    CCMenuItemImage *item22 = CCMenuItemImage::create("Color2_small.png", "Color2_small.png");
    item22->setTag(bingoBoard[1][1]);
    item22->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[1][1]);
    CCLabelTTF *label22 = CCLabelTTF::create(buffer, "Arial", 12);
    label22->setPosition(ccp(10, 10));
    item22->addChild(label22);
    
    CCMenuItemImage *item32 = CCMenuItemImage::create("Color2_small.png", "Color2_small.png");
    item32->setTag(bingoBoard[2][1]);
    item32->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[2][1]);
    CCLabelTTF *label32 = CCLabelTTF::create(buffer, "Arial", 12);
    label32->setPosition(ccp(10, 10));
    item32->addChild(label32);
    
    CCMenuItemImage *item42 = CCMenuItemImage::create("Color2_small.png", "Color2_small.png");
    item42->setTag(bingoBoard[3][1]);
    item42->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[3][1]);
    CCLabelTTF *label42 = CCLabelTTF::create(buffer, "Arial", 12);
    label42->setPosition(ccp(10, 10));
    item42->addChild(label42);
    
    CCMenuItemImage *item52 = CCMenuItemImage::create("Color2_small.png", "Color2_small.png");
    item52->setTag(bingoBoard[4][1]);
    item52->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[4][1]);
    CCLabelTTF *label52 = CCLabelTTF::create(buffer, "Arial", 12);
    label52->setPosition(ccp(10, 10));
    item52->addChild(label52);
    
    CCMenu *item2Menu = CCMenu::create(item12, item22, item32, item42, item52, NULL);
    item2Menu->alignItemsVerticallyWithPadding(20);
    item2Menu->setPositionX(140);
    this->addChild(item2Menu);

    //line 3
    CCMenuItemImage *item13 = CCMenuItemImage::create("Color3_small.png", "Color3_small.png");
    item13->setTag(bingoBoard[0][2]);
    item13->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[0][2]);
    CCLabelTTF *label13 = CCLabelTTF::create(buffer, "Arial", 12);
    label13->setPosition(ccp(10, 10));
    item13->addChild(label13);
    
    CCMenuItemImage *item23 = CCMenuItemImage::create("Color3_small.png", "Color3_small.png");
    item23->setTag(bingoBoard[1][2]);
    item23->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[1][2]);
    CCLabelTTF *label23 = CCLabelTTF::create(buffer, "Arial", 12);
    label23->setPosition(ccp(10, 10));
    item23->addChild(label23);
    
    CCMenuItemImage *item33 = CCMenuItemImage::create("Color3_small.png", "Color3_small.png");
    item33->setTag(bingoBoard[2][2]);
    item33->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[2][2]);
    CCLabelTTF *label33 = CCLabelTTF::create(buffer, "Arial", 12);
    label33->setPosition(ccp(10, 10));
    item33->addChild(label33);
    
    CCMenuItemImage *item43 = CCMenuItemImage::create("Color3_small.png", "Color3_small.png");
    item43->setTag(bingoBoard[3][2]);
    item43->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[3][2]);
    CCLabelTTF *label43 = CCLabelTTF::create(buffer, "Arial", 12);
    label43->setPosition(ccp(10, 10));
    item43->addChild(label43);
    
    CCMenuItemImage *item53 = CCMenuItemImage::create("Color3_small.png", "Color3_small.png");
    item53->setTag(bingoBoard[4][2]);
    item53->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[4][2]);
    CCLabelTTF *label53 = CCLabelTTF::create(buffer, "Arial", 12);
    label53->setPosition(ccp(10, 10));
    item53->addChild(label53);
    
    CCMenu *item3Menu = CCMenu::create(item13, item23, item33, item43, item53, NULL);
    item3Menu->alignItemsVerticallyWithPadding(20);
    item3Menu->setPositionX(210);
    this->addChild(item3Menu);

    //line 4
    CCMenuItemImage *item14 = CCMenuItemImage::create("Color4_small.png", "Color4_small.png");
    item14->setTag(bingoBoard[0][3]);
    item14->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[0][3]);
    CCLabelTTF *label14 = CCLabelTTF::create(buffer, "Arial", 12);
    label14->setPosition(ccp(10, 10));
    item14->addChild(label14);
    
    CCMenuItemImage *item24 = CCMenuItemImage::create("Color4_small.png", "Color4_small.png");
    item24->setTag(bingoBoard[1][3]);
    item24->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[1][3]);
    CCLabelTTF *label24 = CCLabelTTF::create(buffer, "Arial", 12);
    label24->setPosition(ccp(10, 10));
    item24->addChild(label24);
    
    CCMenuItemImage *item34 = CCMenuItemImage::create("Color4_small.png", "Color4_small.png");
    item34->setTag(bingoBoard[2][3]);
    item34->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[2][3]);
    CCLabelTTF *label34 = CCLabelTTF::create(buffer, "Arial", 12);
    label34->setPosition(ccp(10, 10));
    item34->addChild(label34);
    
    CCMenuItemImage *item44 = CCMenuItemImage::create("Color4_small.png", "Color4_small.png");
    item44->setTag(bingoBoard[3][3]);
    item44->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[3][3]);
    CCLabelTTF *label44 = CCLabelTTF::create(buffer, "Arial", 12);
    label44->setPosition(ccp(10, 10));
    item44->addChild(label44);
    
    CCMenuItemImage *item54 = CCMenuItemImage::create("Color4_small.png", "Color4_small.png");
    item54->setTag(bingoBoard[4][3]);
    item54->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[4][3]);
    CCLabelTTF *label54 = CCLabelTTF::create(buffer, "Arial", 12);
    label54->setPosition(ccp(10, 10));
    item54->addChild(label54);
    
    CCMenu *item4Menu = CCMenu::create(item14, item24, item34, item44, item54, NULL);
    item4Menu->alignItemsVerticallyWithPadding(20);
    item4Menu->setPositionX(280);
    this->addChild(item4Menu);

    //line 5
    CCMenuItemImage *item15 = CCMenuItemImage::create("Color5_small.png", "Color5_small.png");
    item15->setTag(bingoBoard[0][4]);
    item15->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[0][4]);
    CCLabelTTF *label15 = CCLabelTTF::create(buffer, "Arial", 12);
    label15->setPosition(ccp(10, 10));
    item15->addChild(label15);
    
    CCMenuItemImage *item25 = CCMenuItemImage::create("Color5_small.png", "Color5_small.png");
    item25->setTag(bingoBoard[1][4]);
    item25->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[1][4]);
    CCLabelTTF *label25 = CCLabelTTF::create(buffer, "Arial", 12);
    label25->setPosition(ccp(10, 10));
    item25->addChild(label25);
    
    CCMenuItemImage *item35 = CCMenuItemImage::create("Color5_small.png", "Color5_small.png");
    item35->setTag(bingoBoard[2][4]);
    item35->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[2][4]);
    CCLabelTTF *label35 = CCLabelTTF::create(buffer, "Arial", 12);
    label35->setPosition(ccp(10, 10));
    item35->addChild(label35);
    
    CCMenuItemImage *item45 = CCMenuItemImage::create("Color5_small.png", "Color5_small.png");
    item45->setTag(bingoBoard[3][4]);
    item45->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[3][4]);
    CCLabelTTF *label45 = CCLabelTTF::create(buffer, "Arial", 12);
    label45->setPosition(ccp(10, 10));
    item45->addChild(label45);
    
    CCMenuItemImage *item55 = CCMenuItemImage::create("Color5_small.png", "Color5_small.png");
    item55->setTag(bingoBoard[4][4]);
    item55->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    sprintf(buffer, "%d", bingoBoard[4][4]);
    CCLabelTTF *label55 = CCLabelTTF::create(buffer, "Arial", 12);
    label55->setPosition(ccp(10, 10));
    item55->addChild(label55);
    
    CCMenu *item5Menu = CCMenu::create(item15, item25, item35, item45, item55, NULL);
    item5Menu->alignItemsVerticallyWithPadding(20);
    item5Menu->setPositionX(350);
    this->addChild(item5Menu);

    
    
    /*
    //plist의 캐시를 받아온다.
    CCSpriteFrameCache *Cache = CCSpriteFrameCache::sharedSpriteFrameCache();
    Cache->addSpriteFramesWithFile("CircleNodeData.plist");
    
    
    //KYULING: 노드가 그려질 화면을 만든다.
    //우선 스크롤 및 컨트롤을 할 투명 객체를 만든다
    
    //원에 포함될 서브 노드를 만들어 붙여준다.
    CCSprite *circleSub1 = CCSprite::createWithSpriteFrameName("Color1_small.png");
    
    
    
    CCMenuItemSprite *circleSub1Image1 = CCMenuItemSprite::create(circleSub1, circleSub1);
    circleSub1Image1->setTag(bingoBoard[0][0]);
    circleSub1Image1->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    
    CCMenuItemSprite *circleSub1Image2 = CCMenuItemSprite::create(circleSub1, circleSub1);
    circleSub1Image2->setTag(bingoBoard[1][0]);
    circleSub1Image2->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    
    CCMenuItemSprite *circleSub1Image3 = CCMenuItemSprite::create(circleSub1, circleSub1);
    circleSub1Image3->setTag(bingoBoard[2][0]);
    circleSub1Image3->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    
    CCMenuItemSprite *circleSub1Image4 = CCMenuItemSprite::create(circleSub1, circleSub1);
    circleSub1Image4->setTag(bingoBoard[3][0]);
    circleSub1Image4->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    
    CCMenuItemSprite *circleSub1Image5 = CCMenuItemSprite::create(circleSub1, circleSub1);
    circleSub1Image5->setTag(bingoBoard[4][0]);
    circleSub1Image5->setTarget(this, menu_selector(BingoGameScene::nodeSelect));
    
    CCMenu *circleSub1Menu = CCMenu::create(circleSub1Image1, circleSub1Image2, circleSub1Image3, circleSub1Image4, circleSub1Image5, NULL);
    circleSub1Menu->alignItemsVerticallyWithPadding(10);
    this->addChild(circleSub1Menu);
    
    
    CCSprite *circleSub2 = CCSprite::createWithSpriteFrameName("Color2_small.png");
    
    CCSprite *circleSub3 = CCSprite::createWithSpriteFrameName("Color3_small.png");
    
    CCSprite *circleSub4 = CCSprite::createWithSpriteFrameName("Color4_small.png");
    
    CCSprite *circleSub5 = CCSprite::createWithSpriteFrameName("Color5_small.png");
    */
    
    
    //KYULING: 빙고 노드를 그린다
    //스프라이트가 여러개 겹쳐져셔 노드 판 하나를 만든다.
    CCLog("game start");
    
    return true;
    
}

void BingoGameScene::nodeSelect(CCNode *node)
{
    CCLog("tapped!");
    
    CCMenuItemSprite *sprite = (CCMenuItemSprite *)node;
    
    CCLog("tag: %d",sprite->getTag());
    
}

bool BingoGameScene::ccTouchBegan(CCTouch * 	pTouch, CCEvent * 	pEvent)

{
    return true;
}
void BingoGameScene::ccTouchMoved	(	CCTouch * 	pTouch,
                             CCEvent * 	pEvent
                             )
{
    
}
void BingoGameScene::ccTouchCancelled	(	CCTouch * 	pTouch,
                                 CCEvent * 	pEvent
                                 )
{
    
}
void BingoGameScene::ccTouchEnded	(	CCTouch * 	pTouch,
                             CCEvent * 	pEvent
                             )
{
    
}

void BingoGameScene::scrollViewDidScroll(CCScrollView *view)
{
    
}

void BingoGameScene::scrollViewDidZoom(CCScrollView *view)
{
    
}
