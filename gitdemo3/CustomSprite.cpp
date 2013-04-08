//
//  CustomSprite.cpp
//  gitdemo3
//
//  Created by MeYouGamesP2 on 13-4-8.
//
//

#include "CustomSprite.h"

void CustomSprite::draw()
{
    //CCSize s = CCDirector::sharedDirector()->getWinSize();
    CCSprite::draw();
    ccDrawLine(ccp(0, 0), ccp(winSize.width, winSize.height));
}