// Ardumower Sunray
// Copyright (c) 2013-2020 by HJ Wolff
// Licensed GPLv3 for open source use

#include "motorstack.h"

MotorStack::MotorStack()
{
    top = -1;
}

bool MotorStack::isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}

bool MotorStack::isFull()
{
    if (top == (MOTORSTACK_SIZE-1))
        return true;
    else
        return false;
}

void MotorStack::flush(){
    top = -1;
}

int MotorStack::size(){
    return top+1;
}

MotorStack::pwm MotorStack::push(MotorStack::pwm cmd){
    if(isFull()){
        MotorStack::pwm null { .left = 0, .right = 0, .timestamp = 0};
        return null;
    }
    // smart/compress push => if .left & .right are the same just update the timestamp
    if(!isEmpty() && cmds[top].left == cmd.left && cmds[top].right == cmd.right){
        cmds[top].timestamp = cmd.timestamp;
    } else {
        cmds[++top] = cmd;
    }
    return cmd;
}

MotorStack::pwm MotorStack::pop(){
    MotorStack::pwm temp;
    if(isEmpty()){
        MotorStack::pwm null { .left = 0, .right = 0, .timestamp = 0};
        return null;
    }
    temp = cmds[top--];
    return temp;
}