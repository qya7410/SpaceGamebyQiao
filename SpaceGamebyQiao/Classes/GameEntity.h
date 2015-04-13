//
//  GameEntity.h
//  SpaceGamebyQiao
//
//  Created by DevQiao on 4/12/15.
//
//

#ifndef __SpaceGamebyQiao__GameEntity__
#define __SpaceGamebyQiao__GameEntity__

#include "cocos2d.h"

USING_NS_CC;

class   GameEntity : public Node
{
public:
    CREATE_FUNC(GameEntity);

    void remove();
    
    Node *getModel(){ return _model; }
    Vec3 getOrientation() { return _orientation; }
    
    void setType(int type) { _type = type; }
    int getType(){ return _type; }
    
    float getRadius(){ return _radius; };

    void forward(float distance);
    void forward(float distance, float angle);
    
public:
//    static void UseOutlineEffect(Sprite3D *sprite3d, float width, Color3B color);
    
protected:
    Node *_model;
    float  _radius;
    Vec3 _orientation;
    int _type;
};

#endif /* defined(__SpaceGamebyQiao__GameEntity__) */
