//
//  MainMenu.cpp
//  anogame
//
//  Created by DaydreamQian on 10/26/13.
//
//

#include "MainMenu.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

CCScene* MainMenu::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    MainMenu *layer = MainMenu::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    
    // add background
    CCSprite* backgroundSprite = CCSprite::create("Background.png");
    backgroundSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(backgroundSprite, 0);
    
    // add background music
    CocosDenshion::SimpleAudioEngine* sharedEngine ;
    sharedEngine->preloadBackgroundMusic("main_menu.mp3");
    sharedEngine->playBackgroundMusic("main_menu.mp3", 1 ) ;
    
    
    /*preordered labels ( will replaced by button soon )*/
    
    //game name label
    CCLabelTTF* gameNameLabel = CCLabelTTF::create("Anogame", "Inconsolata", 80);
    gameNameLabel->setPosition(ccp(origin.x + visibleSize.width / 2,
                            origin.y + visibleSize.height - gameNameLabel->getContentSize().height));
    this->addChild(gameNameLabel, 1);
    
    //new game label
    CCLabelTTF* newGameLabel = CCLabelTTF::create("New Game", "Inconsolata", 50);
    newGameLabel->setPosition(ccp(origin.x + visibleSize.width / 7 ,
                                   origin.y + visibleSize.height - 3 * newGameLabel->getContentSize().height));
    this->addChild(newGameLabel, 1);

    //Story label
    CCLabelTTF* gameStoryLabel = CCLabelTTF::create("Our Storys", "Inconsolata", 50);
    gameStoryLabel->setPosition(ccp(origin.x + visibleSize.width / 6 ,
                                     origin.y + visibleSize.height - 5 * gameStoryLabel->getContentSize().height));
    this->addChild(gameStoryLabel, 1);
    
    //card edit label
    CCLabelTTF* cardEditLabel = CCLabelTTF::create("Edit Card", "Inconsolata", 50);
    cardEditLabel->setPosition(ccp(origin.x + visibleSize.width / 5 ,
                                  origin.y + visibleSize.height - 7 * cardEditLabel->getContentSize().height));
    this->addChild(cardEditLabel, 1);
    
    //option label
    CCLabelTTF* gameOptionLabel = CCLabelTTF::create("Options", "Inconsolata", 50);
    gameOptionLabel->setPosition(ccp(origin.x + visibleSize.width / 4 ,
                                   origin.y + visibleSize.height - 9 * gameOptionLabel->getContentSize().height));
    this->addChild(gameOptionLabel, 1);
    
//    the fade in function, maybe used later
//    CCSprite* sprite = [CCSprite spriteWithFile:@"sprit.png"];
//    CCFadeOut* fade =[CCFadeOut actionWithDuration:1.0f];
//    [sprite runAction:fade];
    
    return true;
}


void MainMenu::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
