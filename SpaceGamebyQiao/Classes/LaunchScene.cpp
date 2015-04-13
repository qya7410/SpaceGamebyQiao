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
    
//    //添加尾气粒子效果
//    auto flare = ParticleSystemQuad::create("missileFlare.plist");
//    flare->setScale(3);
//    float originX = -9.0f;
//    float originY = 156.0f;
//    float originZ = 9.0f;
//    flare->setTotalParticles(20);
//    flare->setRotation3D(Vec3(-originX,-originY,-originZ));
//    flare->setPosition(convertToNodeSpace(Point(300, 0)));
//    flare->setPositionType(tPositionType::GROUPED);
//    flare->setStartColor(Color4F(0, 0.99, 1, 1));
//    flare->setGlobalZOrder(-2);
//    fighter->addChild(flare, -1);
    
    
    return true;
}

void LaunchScene::update(float dt){
    pRate+=0.01;
    fighter->setPosition3D(Vec3(Visible_Size_Macro.width/2+50, 600-17*sin(1.05*pRate), 0));
}

