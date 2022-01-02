#include "mbed.h"

DigitalOut led1(p6);
DigitalOut led2(p7);

Ticker timer1;
Timeout timer2;

void toggle(){
    led1!=led1;
}

void flip(){
    led2!=led2;
}

int main(){
    led1=1;
    timer1.attach(callback(&toggle), 2.5f);
    timer2.attach(callback(&flip), 1.5f);
    wait_ms(osWaitForever);
}