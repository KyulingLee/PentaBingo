//
//  GameOptionScene.h
//  Pentabingo
//
//  Created by Lee Bong Kyu on 2014. 4. 26..
//
//

#ifndef __Pentabingo__GameOptionScene__
#define __Pentabingo__GameOptionScene__

#include <iostream>
#include "cocos2d.h"

class GameOptionScene : public cocos2d::CCLayer
{
public:
    virtual bool init();
    
    static cocos2d::CCScene* scene();
    
    CREATE_FUNC(GameOptionScene);
    
    //KYULING: 옵션값을 불러온다
    
    //KYULING: 사운드 옵션을 설정하는 메소드
    void effectSettingTapped();
    
    void backButtonTapped();
    
};


#endif /* defined(__Pentabingo__GameOptionScene__) */
