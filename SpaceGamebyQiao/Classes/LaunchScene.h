//
//  LaunchScene.h
//  SpaceGamebyQiao
//
//  Created by DevQiao on 4/12/15.
//
//

#ifndef __SpaceGamebyQiao__LaunchScene__
#define __SpaceGamebyQiao__LaunchScene__

#include "cocos2d.h"

USING_NS_CC;

class LaunchScene : public cocos2d::Layer
{
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(LaunchScene);
    //void update(float dt);
};

#endif /* defined(__SpaceGamebyQiao__LaunchScene__) */
