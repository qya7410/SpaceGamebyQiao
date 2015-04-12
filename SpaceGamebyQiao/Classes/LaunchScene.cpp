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
    
    auto model = Sprite3D::create("boss.obj", "boss.png");
    model->setPosition(Visible_Size_Macro/2);
    model->setScale(20);
    addChild(model);
    
    return true;
}

