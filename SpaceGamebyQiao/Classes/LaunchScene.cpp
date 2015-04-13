//
//  LaunchScene.cpp
//  SpaceGamebyQiao
//
//  Created by DevQiao on 4/12/15.
//
//

#include "LaunchScene.h"
#include "PublicAPI.h"
#include "BlinkTitle.h"

Scene* LaunchScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = LaunchScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool LaunchScene::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    pRate = 3.1415926/2;
    
   // SpriteFrameCache::getInstance()->addSpriteFramesWithFile("launchScenePicture.plist");
    
    //添加飞机
    fighter = Fighter::create();
    addChild(fighter);
    scheduleUpdate();
    //fighter->setPosition3D(Vec3(Visible_Size_Macro.width/2+50, 480-20*sin(1.05*pRate), 0));
    
    //Launch启动的后退消失粒子系统效果添加，采用默认纹理
    auto fileUtil = FileUtils::getInstance();
    auto plistData = fileUtil->getValueMapFromFile("vanishingPoint.plist");
    auto vanishing = ParticleSystemQuad::create(plistData);
    vanishing->setAnchorPoint(Vec2(0.5, 0.5));
    vanishing->setPosition(Visible_Size_Macro.width-120, Visible_Size_Macro.height/2 -50);
    vanishing->setGlobalZOrder(-1);
    addChild(vanishing);
    
    //添加背景图片
    auto background = Sprite::create("background.png");
    background->setAnchorPoint(Vec2(0,0));
    //background->setScale(background->getBoundingBox().size.width*(1334/750));
    this->addChild(background);
    background->setGlobalZOrder(-10);
    
    //添加启动界面Title
    auto blinkTitle = BlinkTitle::create("titleInLaunch.png");
    blinkTitle->setScale(1.8);
    blinkTitle->setPosition(Visible_Size_Macro.width/2,
                                                   (Visible_Size_Macro.height - 230));  //此处的硬编码后期要重新调整成相对坐标
    addChild(blinkTitle);
    
    return true;
}

void LaunchScene::update(float dt){
    pRate+=0.01;
    fighter->setPosition3D(Vec3(Visible_Size_Macro.width/2+50, 600-17*sin(1.05*pRate), 0));
}

