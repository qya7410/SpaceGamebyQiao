#include "AppDelegate.h"

#include "LaunchScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {

        glview = GLViewImpl::createWithRect("SpaceGamebyQiao", Rect(0, 0, 800*(750.0/1334.0), 800));
        
        director->setOpenGLView(glview);
    }

    glview->setDesignResolutionSize(750, 1334, ResolutionPolicy::SHOW_ALL);
    
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    auto scene = LaunchScene::createScene();

    // run
    director->runWithScene(scene);

    glEnable(GL_CULL_FACE); //开启剔除操作效果.
    /*禁用多边形正面或者背面上的光照、阴影和颜色计算及操作，消除不必要的渲染计算。
     例如某对象无论如何位置变化，我们都只能看到构成其组成的多边形的某一面时，可使用该函数。*/
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {

    CocosDenshion::SimpleAudioEngine::getInstance()->pauseAllEffects();
    CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();

    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    
    CocosDenshion::SimpleAudioEngine::getInstance()->resumeAllEffects();
    CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
