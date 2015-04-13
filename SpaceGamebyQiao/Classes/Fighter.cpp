//
//  Fighter.cpp
//  SpaceGamebyQiao
//
//  Created by DevQiao on 4/12/15.
//
//

#include "Fighter.h"
#include "PublicAPI.h"


const float Fighter::pXW = 1.1f;
const float Fighter::pYW = 5.0f;
const float Fighter::pZW = 1.0f;
const float Fighter::pXA = 1.0f;
const float Fighter::pYA = 10.0f;
const float Fighter::pZA = 7.0f;

bool Fighter::init()
{
    pRate = 3.1415926/2;
    originX = -15.0f;
    originY = 156.0f;
    originZ = 15.0f;
    
    _model = Sprite3D::create("fighter.obj", "fighter.png");
    if (_model) {
        
        _model->setScale(48);
       _model->setRotation3D(Vec3(originX, originY, originZ));
        
        this->setRotation3D(Vec3(originX, originY, originZ));
        this->addChild(_model);
        this->scheduleUpdate();
        
        //添加尾气粒子效果
        auto flare1 = ParticleSystemQuad::create("missileFlare.plist");
        flare1->setScale(0.07);
        float originX = -9.0f;
        float originY = 156.0f;
        float originZ = 9.0f;
        flare1->setTotalParticles(20);
        flare1->setRotation3D(Vec3(-originX,-originY,-originZ));
        flare1->setPosition3D(Vec3(6.4, -0.7, 2.3));
        flare1->setPositionType(tPositionType::GROUPED);
        flare1->setStartColor(Color4F(0, 0.99, 1, 1));
        _model->addChild(flare1, -1);
        
        auto flare2 = ParticleSystemQuad::create("missileFlare.plist");
        flare2->setScale(0.07);
        
        flare2->setTotalParticles(20);
        flare2->setRotation3D(Vec3(-originX,-originY,-originZ));
        flare2->setPosition3D(Vec3(-6.4, -0.7, 2.3));
        flare2->setPositionType(tPositionType::GROUPED);
        flare2->setStartColor(Color4F(0, 0.99, 1, 1));
        _model->addChild(flare2, -1);
        
        auto emission = ParticleSystemQuad::create("launchFighterEmission.plist");
        emission->setScale(0.05);
        emission->setRotation3D(Vec3(originX,originY, -180));
        //emis->setPosition(40, 0);
        emission->setPositionType(tPositionType::GROUPED);
        emission->setRotation(-3);
        emission->setPosition3D(Vec3(0, -0.7, 5.0));
        _model->addChild(emission, -2);
    }
    
    return true;
}

void Fighter::update(float dt)
{
    pRate += 0.01;
    _model->setRotation3D(Vec3(0-pXA*sin(pXW*pRate),0,0-pZA*sin(pZW*pRate)));
}