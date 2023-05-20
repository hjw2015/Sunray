// Ardumower Sunray 
// Copyright (c) 2013-2020 by HJ Wolff
// Licensed GPLv3 for open source use

#ifndef MOTORSTACK_H
#define MOTORSTACK_H

#define MOTORSTACK_SIZE 100

class MotorStack {
    public:
        struct pwm {
        int left;
        int right;
        long timestamp;
        };
    private:
        int top;
        pwm cmds[MOTORSTACK_SIZE];
    public:
        MotorStack();
        pwm push(pwm);
        pwm pop();
        bool isEmpty();
        bool isFull();
        void flush();
        int size();
};

#endif
