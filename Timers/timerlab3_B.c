#include "mbed.h"

DigitalOut led1(p5);
DigitalOut led2(p6);
InterruptIn button(p7);
Ticker timer;

int count=0;
int bttn=0;
int cntrl=0;
void btn_ISR(){
    extern int bttn;
    bttn++;
}
void toggle(){
    extern int count,cntrl;
    count++;
    printf("count is %d\n",count);
    button.fall(callback(&btn_ISR));
    cntrl=bttn;
    printf("button count is %d\n",cntrl);
    if(count==5){
        count=0;
        led1=!led1;
    }
    bttn=0;
}

int main(){
    timer.attach(callback(&toggle),1.5f);
}