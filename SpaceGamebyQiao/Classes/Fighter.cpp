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
    }
    
    return true;
}

void Fighter::update(float dt)
{
    pRate += 0.01;
    _model->setRotation3D(Vec3(0-pXA*sin(pXW*pRate),0,0-pZA*sin(pZW*pRate)));
}