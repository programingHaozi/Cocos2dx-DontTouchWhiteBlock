//
//  TouchBlock.cpp
//  DontTouchWhiteBlock
//
//  Created by 耗子 on 14/11/13.
//
//

#include "TouchBlock.h"

//初始化数组
Vector<TouchBlock*>* TouchBlock::blocks = new Vector<TouchBlock*>();

//获取TouchBlock数组
Vector<TouchBlock*>* TouchBlock::getTouchBlocks(){
    return blocks;
}

TouchBlock* TouchBlock::createWithArg(cocos2d::Color3B color, cocos2d::Size size, std::string label, float fontSize, cocos2d::Color4B textColor){
    
    auto b = new TouchBlock();
   
    //初始化TouchBlock
    b ->initWithArg(color, size, label, fontSize, textColor);
    b ->autorelease();
  
    //添加TouchBlock到数组中
    blocks ->pushBack(b);
    return b;
}


bool TouchBlock::initWithArg(cocos2d::Color3B color, cocos2d::Size size, std::string label, float fontSize, cocos2d::Color4B textColor){
    Sprite::init();
    
    //初始化行数为第0行
    lineIndex = 0;
    
    //设置大小
    setContentSize(size);
    //设置左下角位置对齐
    setAnchorPoint(Point::ZERO);
    //设置颜色
    setColor(color);
    //设置显示颜色区域
    setTextureRect(Rect(0, 0, size.width, size.height));
    
    //添加文字
    auto l = Label::create();
    l ->setString(label);
    l ->setSystemFontSize(fontSize);
    l ->setTextColor(textColor);
    l ->setPosition(size.width/2, size.height/2);
    addChild(l);
    
    
    return true;
}

void TouchBlock::removeTouchBlock(){
    removeFromParent();
    blocks ->eraseObject(this);
}

void TouchBlock::setLineIndex(int value){
    this->lineIndex = value;
}

int TouchBlock::getLineIndex(){
    return this->lineIndex;
}

void TouchBlock::touchBlockMoveDown(){
    this->lineIndex --;
   
    log("%d",lineIndex);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    runAction(Sequence::create(MoveTo::create(0.1, Point(getPositionX(),lineIndex*visibleSize.height/4)), CallFunc::create([this](){
        
        
        if (this ->getColor() == Color3B::GREEN) {
            log("green\n,%d",this ->getLineIndex());
            log("%f,%f",this ->getPositionX(),this->getPositionY());
        }
        
        
        if (lineIndex<0) {
            removeTouchBlock();
        }
    }),NULL));
    
}