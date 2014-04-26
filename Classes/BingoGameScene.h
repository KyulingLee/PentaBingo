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
#include "cocos2d.h"

class BingoGameScene : public cocos2d::CCLayer
{
public:
    virtual bool init();
    
    static cocos2d::CCScene* scene();
    
    CREATE_FUNC(BingoGameScene);
    
    
    
};


#endif /* defined(__Pentabingo__BingoGameScene__) */
