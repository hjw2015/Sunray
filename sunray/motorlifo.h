// Ardumower Sunray 
// Copyright (c) 2013-2020 by HJ Wolff
// Licensed GPLv3 for open source use

#ifndef MOTORLIFO_H
#define MOTORLIFO_H

#define MOTORLIFO_SIZE 100

class MotorLifo {
    public:
        struct pwm {
        int left;
        int right;
        unsigned long timestamp;
        };
    private:
        int top;
        pwm cmds[MOTORLIFO_SIZE];
    public:
        MotorLifo();
        pwm push(pwm);
        pwm pop();
        bool isEmpty();
        bool isFull();
        void flush();
        int size();
};

#endif
