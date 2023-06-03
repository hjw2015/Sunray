// Ardumower Sunray
// Copyright (c) 2013-2020 by HJ Wolff
// Licensed GPLv3 for open source use

#include "motorlifo.h"

MotorLifo::MotorLifo()
{
    top = -1;
}

bool MotorLifo::isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}

bool MotorLifo::isFull()
{
    if (top == (MOTORLIFO_SIZE-1))
        return true;
    else
        return false;
}

void MotorLifo::flush(){
    top = -1;
}

int MotorLifo::size(){
    return top+1;
}

MotorLifo::pwm MotorLifo::push(MotorLifo::pwm cmd){
    // smart/compress push => if .left & .right are the same just update the timestamp
    if(!isEmpty() && cmds[top].left == cmd.left && cmds[top].right == cmd.right){
        cmds[top].timestamp = cmd.timestamp;
    } else {
        if(isFull()){
            // deque first element
            for(int i=0;i<MOTORLIFO_SIZE-1;i++){
                cmds[i] = cmds[i+1];
            }
            top--;
        }
        cmds[++top] = cmd;
    }
    return cmd;
}

MotorLifo::pwm MotorLifo::pop(){
    MotorLifo::pwm temp;
    if(isEmpty()){
        MotorLifo::pwm null { .left = 0, .right = 0, .timestamp = 0};
        return null;
    }
    temp = cmds[top--];
    return temp;
}