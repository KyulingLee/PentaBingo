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
    
    return true;
    
}

