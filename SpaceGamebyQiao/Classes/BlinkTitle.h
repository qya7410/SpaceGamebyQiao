#ifndef __BlinkTitle_H_
#define __BlinkTitle_H_

#include "cocos2d.h"
USING_NS_CC;

class BlinkTitle : public Node
{
public:
    static BlinkTitle* create(const std::string &fileName);
    
private:
    BlinkTitle();
    bool init(const std::string &fileName);
};
#endif
