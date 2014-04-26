//
//  TestScene.h
//  Pentabingo
//
//  Created by Lee Bong Kyu on 2014. 4. 26..
//
//

#ifndef __Pentabingo__TestScene__
#define __Pentabingo__TestScene__

#include <iostream>
#include "cocos2d.h"

class TestScene : public cocos2d::CCLayer
{
public:
    virtual bool init();
    
    static cocos2d::CCScene* scene();
    
    CREATE_FUNC(TestScene);
    
};


#endif /* defined(__Pentabingo__TestScene__) */
