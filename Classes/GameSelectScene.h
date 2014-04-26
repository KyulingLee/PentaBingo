//
//  GameSelectScene.h
//  Pentabingo
//
//  Created by Lee Bong Kyu on 2014. 4. 26..
//
//

#ifndef __Pentabingo__GameSelectScene__
#define __Pentabingo__GameSelectScene__

#include <iostream>
#include "cocos2d.h"

class GameSelectScene : public cocos2d::CCLayer
{
public:
    virtual bool init();
    
    static cocos2d::CCScene* scene();
    
    CREATE_FUNC(GameSelectScene);
    
    //게임 모드 선택에 맞춰서 동작하는 메소드
    void fastModeSelected();
    void manyModeSelected();
    
    //이전 화면으로 돌아가는 동작하는 메소드
    void backButtonTapped();
};


#endif /* defined(__Pentabingo__GameSelectScene__) */
