#include "mbed.h"

DigitalOut led1(p5);
DigitalOut led2(p6);
InterruptIn button(p7);
Ticker timer;

int count=0;

void toggle(){
    extern int count;
    count++;
    printf("count is %d\n",count);
    if(count==5){
        count=0;
        led1=!led1;
    }
}

int main(){
    timer.attach(callback(&toggle),1.5f);
}
