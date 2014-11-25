#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "TouchBlock.h"

USING_NS_CC;
class HelloWorld : public cocos2d::Layer
{
private:
    Size visibleSize;
   
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    //添加开始行
    void addStartLine();
    //添加结束行
    void addEndLine();
    //添加黑白块行
    void addNormalLine(int lineIndex);
    //添加开始方法
    void startGame();
    //block下移
    void moveDown();
    //总行数
    int linesCount;
    //是否显示结束行
    bool showEnd;
};

#endif // __HELLOWORLD_SCENE_H__
