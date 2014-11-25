#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    
    
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
    if ( !Layer::init() )
    {
        return false;
    }
    visibleSize = Director::getInstance()->getVisibleSize();
    
    //开始游戏
    startGame();
    
    
    
    auto listener = EventListenerTouchOneByOne::create();
    listener ->onTouchBegan = [this](Touch *t,Event *e){
       
        auto blocks = TouchBlock::getTouchBlocks();
        TouchBlock *b;
        for (auto item = blocks->begin(); item != blocks->end(); item++) {
            b = *item;
            
            if (b ->getLineIndex() == 1&&b ->getBoundingBox().containsPoint(t ->getLocation())) {
                if (b ->getColor() == Color3B::BLACK) {
                    b->setColor(Color3B::GRAY);
                    moveDown();

                    if (b ->lineNum == 50) {
                        moveDown();
                    }
                }else{
                    b ->runAction(Blink::create(2.0, 4));
//                    这是测试commit
                    MessageBox("GameOver", "失败");
                }
                break;
            }
        }
        
        
        return false;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    
    return true;
}

void jishi(){
    
}

//开始加载block块
void HelloWorld::startGame(){
    linesCount = 0;
    showEnd = false;
    //添加第一界面的四行
    addStartLine();
    addNormalLine(1);
    addNormalLine(2);
    addNormalLine(3);
}

//开始行
void HelloWorld::addStartLine(){
    auto startLine = TouchBlock::createWithArg(Color3B::YELLOW, Size(visibleSize.width, visibleSize.height/4), "", 30, Color4B::BLACK);
    startLine ->setLineIndex(0);
    addChild(startLine);
    log("%f,%f",startLine ->getPositionX(),startLine ->getPositionY());
}

//结束行
void HelloWorld::addEndLine(){
    auto endLine = TouchBlock::createWithArg(Color3B::GREEN, visibleSize, "Game Over", 30, Color4B::WHITE);
    endLine ->setLineIndex(4);
    endLine ->setPosition(0,visibleSize.height);
    addChild(endLine);
    log("%f,%f",endLine ->getPositionX(),endLine ->getPositionY());
}

//黑白行
void HelloWorld::addNormalLine(int lineIndex){
    
    linesCount ++;
    TouchBlock *normalBlock;
    //随机产生黑色块位置
    int blackIndex = rand()%4;
    for (int i =0; i<4; i++) {
        normalBlock = TouchBlock::createWithArg(blackIndex == i?Color3B::BLACK:Color3B::WHITE, Size(visibleSize.width/4-1, visibleSize.height/4-1), "", 20, Color4B::BLACK);
        addChild(normalBlock);
        
        normalBlock ->setPosition(i*visibleSize.width/4, lineIndex*visibleSize.height/4);
        normalBlock ->setLineIndex(lineIndex);
        normalBlock ->lineNum = linesCount;
    }
    
}

//下移
void HelloWorld::moveDown(){
    if (linesCount<50) {
        addNormalLine(4);
    }else if(!showEnd){
        addEndLine();
        showEnd = true;
    }
   
    auto blocks = TouchBlock::getTouchBlocks();
    for (auto item = blocks ->begin(); item != blocks ->end(); item++) {
        (*item) ->touchBlockMoveDown();
    }
    
}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
