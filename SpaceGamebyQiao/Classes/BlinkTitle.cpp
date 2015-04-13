#include "BlinkTitle.h"

BlinkTitle::BlinkTitle()
{}

BlinkTitle* BlinkTitle::create(const std::string &fileName)
{
    BlinkTitle *blinkTitle = new BlinkTitle();
    if (blinkTitle && blinkTitle->init(fileName)) {
        blinkTitle->autorelease();
        return blinkTitle;
    }
    
    CC_SAFE_DELETE(blinkTitle);
    return nullptr;
}
bool BlinkTitle::init(const std::string & fileName)
{
    if (!Node::init()) {
        return false;
    }
    
    auto cliper = ClippingNode::create();
    auto content = Sprite::create(fileName);
    auto stencil = content;
    
    auto spark = Sprite::create("spark.png");
    
    cliper->setAlphaThreshold(0.5f);
    cliper->setStencil(stencil);
    cliper->addChild(content);
    cliper->addChild(spark);
    
    this->addChild(cliper);
    
    auto moveTo = MoveTo::create(2.0f, Point(content->getContentSize().width, 0));
    //auto moveBack = MoveTo::create(2.0f, Point(-content->getContentSize().width, 0));
    auto positionReset = CallFunc::create([spark, content](){spark->setPosition(-content->getContentSize().width, 0);});
    auto seq = Sequence::create(positionReset, moveTo, NULL);
    auto action = RepeatForever::create(seq);
    spark->runAction(action);
    
    return true;
}

