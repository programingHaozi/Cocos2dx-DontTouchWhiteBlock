//
//  TouchBlock.h
//  DontTouchWhiteTouchBlock
//
//  Created by 耗子 on 14/11/13.
//
//

#ifndef __DontTouchWhiteBlock__TouchBlock__
#define __DontTouchWhiteBlock__TouchBlock__

#include <stdio.h>
#include <cocos2d.h>
USING_NS_CC;

class TouchBlock:public Sprite {
    
private:
    //定义静态数组，用来存放TouchBlock
    static Vector<TouchBlock*>* blocks;
    
    //定义block块的行数
    int lineIndex;
    
   
public:
    //TouchBlock创建方法
    static TouchBlock* createWithArg(Color3B color,Size size,std::string label,float fontSize,Color4B textColor);
   
    //TouchBlock初始化方法
    virtual bool initWithArg(Color3B color,Size size,std::string label,float fontSize,Color4B textColor);
   
    //移除TouchBlock
    void removeTouchBlock();
    
    //设置行数
    void setLineIndex(int value);
   
    //获取行数
    int getLineIndex();
   
    //获取TouchBlock数组
    static Vector<TouchBlock*>* getTouchBlocks();
    
    //touchBlock下移
    void touchBlockMoveDown();
    
    //此行block块在整体中的行数
    int lineNum;
};

#endif /* defined(__DontTouchWhiteBlock__TouchBlock__) */
