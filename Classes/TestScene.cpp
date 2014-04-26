//
//  TestScene.cpp
//  Pentabingo
//
//  Created by Lee Bong Kyu on 2014. 4. 26..
//
//

#include "TestScene.h"

USING_NS_CC;

CCScene* TestScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    TestScene *layer = TestScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool TestScene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    return true;

}

