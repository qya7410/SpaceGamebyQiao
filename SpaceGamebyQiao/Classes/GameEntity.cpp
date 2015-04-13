//
//  GameEntity.cpp
//  SpaceGamebyQiao
//
//  Created by DevQiao on 4/12/15.
//
//

#include "GameEntity.h"
//#include <iostream>

USING_NS_CC_MATH;

void GameEntity::forward(float distance)
{
    float rotation = getRotation();
    setPosition(getPosition()
                +Vec2(
                      sinf(CC_DEGREES_TO_RADIANS(rotation))*distance,
                      cosf(CC_DEGREES_TO_RADIANS(rotation))*distance)); //简单的计算按朝向前进指定距离
}

void GameEntity::forward(float distance, float angle)
{
    setRotation(getRotation() - angle);
    forward(distance);
}

