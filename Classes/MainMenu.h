//
//  MainMenu.h
//  anogame
//
//  Created by DaydreamQian on 10/26/13.
//
//

#ifndef anogame_MainMenu_h
#define anogame_MainMenu_h

#include "cocos2d.h"

class MainMenu : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(MainMenu);
};



#endif


