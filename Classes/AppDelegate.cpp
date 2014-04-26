#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "cocos2d.h"

USING_NS_CC;

typedef struct tagResource
{
    cocos2d::CCSize size;
    char directory[100];
} Resource;

static Resource resource1 = { cocos2d::CCSizeMake(480, 320), "iphone3" };
static Resource resource2 = { cocos2d::CCSizeMake(960, 640), "iphone4" };
static Resource resource3 = { cocos2d::CCSizeMake(1024, 768), "ipad" };
static Resource resource4 = { cocos2d::CCSizeMake(2048, 1536), "ipadhd" };
static cocos2d::CCSize designResolutionSize = cocos2d::CCSizeMake(480, 320);

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);
	
    //KYULING: openGL View에 디자인 레졸루션을 적용해 준다.
    pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height,kResolutionNoBorder);
    
    //KYULING: 프레임 사이즈를 확인하여 화면별로 해상도 설정을 적용해야 하기 위해 사용한다.
    CCSize frameSize = pEGLView->getFrameSize();
    
    //각 화면 해상도에 따라 레졸루션 비율에 맞춰서 처리해준다.
    if (frameSize.height > resource3.size.height) {
        CCFileUtils::sharedFileUtils()->addSearchPath(resource4.directory);
        pDirector->setContentScaleFactor(resource4.size.height/designResolutionSize.height);
    }
    else if (frameSize.height > resource2.size.height && frameSize.height < resource4.size.height) {
        CCFileUtils::sharedFileUtils()->addSearchPath(resource3.directory);
        pDirector->setContentScaleFactor(resource3.size.height/designResolutionSize.height);
    }
    else if (frameSize.height > resource1.size.height && frameSize.height < resource3.size.height) {
        CCFileUtils::sharedFileUtils()->addSearchPath(resource2.directory);
        pDirector->setContentScaleFactor(resource2.size.height/designResolutionSize.height);
    }
    else
    {
        CCFileUtils::sharedFileUtils()->addSearchPath(resource1.directory);
        pDirector->setContentScaleFactor(resource1.size.height/designResolutionSize.height);
    }
    
    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    CCScene *pScene = HelloWorld::scene();

    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
