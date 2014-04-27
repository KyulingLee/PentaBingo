//
//  BingoGameScene.h
//  Pentabingo
//
//  Created by Lee Bong Kyu on 2014. 4. 26..
//
//

#ifndef __Pentabingo__GameScene__
#define __Pentabingo__GameScene__

#include <iostream>
#include <stdio.h>
#include "cocos2d.h"
#include "cocos-ext.h"
#include <string>
#include <sstream>

using namespace cocos2d;
using namespace cocos2d::extension;

class BingoGameScene : public cocos2d::CCLayer, public CCScrollViewDelegate
{
public:
    virtual bool init();
    
    static cocos2d::CCScene* scene();
    
    CREATE_FUNC(BingoGameScene);
    
    int bingoBoard[5][5];
    //std::string boardString[5][5];
    
    //void imageSelected(CCNode *node);
    
    void nodeSelect(CCNode *node);
    
    
    virtual bool ccTouchBegan(CCTouch * 	pTouch, CCEvent * 	pEvent);
    virtual void ccTouchMoved	(	CCTouch * 	pTouch,
                                 CCEvent * 	pEvent
                                 );
    virtual void ccTouchCancelled	(	CCTouch * 	pTouch,
                                     CCEvent * 	pEvent
                                     );
    virtual void ccTouchEnded	(	CCTouch * 	pTouch,
                                 CCEvent * 	pEvent
                                 );
    
    virtual void scrollViewDidScroll(CCScrollView *view);
    virtual void scrollViewDidZoom(CCScrollView *view);
};




#endif /* defined(__Pentabingo__BingoGameScene__) */
