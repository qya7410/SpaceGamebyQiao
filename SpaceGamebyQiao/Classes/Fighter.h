//
//  Fighter.h
//  SpaceGamebyQiao
//
//  Created by DevQiao on 4/12/15.
//
//

#ifndef __SpaceGamebyQiao__Fighter__
#define __SpaceGamebyQiao__Fighter__

#include <iostream>
#include "cocos2d.h"
#include "GameEntity.h"

class Fighter : public GameEntity
{
public:
    CREATE_FUNC(Fighter);
    bool init();
    
private:
    float pRate;
    float originX;
    float originY;
    float originZ;
    
    const static float pXW;
    const static float pYW;
    const static float pZW;
    
    const static float pXA;
    const static float pYA;
    const static float pZA;
    
    void update(float dt);
};

#endif /* defined(__SpaceGamebyQiao__Fighter__) */
