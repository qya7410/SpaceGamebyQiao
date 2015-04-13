//
//  LaunchScene.cpp
//  SpaceGamebyQiao
//
//  Created by DevQiao on 4/12/15.
//
//

#include "LaunchScene.h"
#include "PublicAPI.h"

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
    
    //添加飞机
    fighter = Fighter::create();
    addChild(fighter);
    scheduleUpdate();
//    fighter->setPosition3D(Vec3(Visible_Size_Macro.width/2+50, 480-20*sin(1.05*pRate), 0));
    
    //Launch启动的粒子系统效果添加，采用默认纹理
    auto fileUtil = FileUtils::getInstance();
    auto plistData = fileUtil->getValueMapFromFile("vanishingPoint.plist");
    auto vanishing = ParticleSystemQuad::create(plistData);
    vanishing->setAnchorPoint(Vec2(0.5, 0.5));
    vanishing->setPosition(Visible_Size_Macro.width-120, Visible_Size_Macro.height/2 -50);
    vanishing->setGlobalZOrder(-1);
    addChild(vanishing);
    
    return true;
}

void LaunchScene::update(float dt){
    pRate+=0.01;
    fighter->setPosition3D(Vec3(Visible_Size_Macro.width/2+50, 600-17*sin(1.05*pRate), 0));
}

