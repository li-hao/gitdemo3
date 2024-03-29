#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "CustomSprite.h"
using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Thonburi", 34);

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    // position the label on the center of the screen
    pLabel->setPosition( ccp(size.width / 2, size.height - 20) );

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    //CCSprite* pSprite = CCSprite::create("HelloWorld.png");
    CCSprite * pSprite = new CustomSprite();
    pSprite->initWithFile("HelloWorld.png");
    pSprite->autorelease();
    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    CCLog(this->description());
    
    CCFiniteTimeAction * action1 = CCMoveTo::create(3, ccp(pSprite->getPosition().x, size.height));
    CCFiniteTimeAction * action2 = CCMoveTo::create(3, ccp(pSprite->getPosition().x, 0));
    CCFiniteTimeAction * seq = CCSequence::create(action1,action2,NULL);
    CCFiniteTimeAction * forever = CCRepeatForever::create((CCActionInterval *)seq);
    pSprite->runAction(forever);

    //添加个注释玩玩！
    
    CCActionInterval * jumpBy = CCJumpBy::create(5, ccp(-size.width, 0), 30, 5);
    CCActionInterval * jumpBack = jumpBy->reverse();
    CCFiniteTimeAction * seq1 = CCSequence::create(jumpBy,jumpBack,NULL);
    CCRepeatForever* re = CCRepeatForever::create((CCActionInterval*)seq1);
    
    pCloseItem->runAction(re);
    
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
