#include "mbed.h"

DigitalOut led1(p5);
DigitalOut led2(p6);
DigitalOut led3(p7);
InterruptIn button(p8);
Ticker timer1;
Timeout timeout1;

int count=0;
int bttn=0;
int cp;
void button_ISR(){
    extern int bttn;
    bttn++;
}
void led2_ISR(){
    led2=0;
    wait_ms(200);
    led2=1;
    cp=0;
    bttn=0;
}
void led3_ISR(){
    led3=0;
    wait_ms(200);
    led3=1;
    cp=0;
    bttn=0;
}
void toggle_ISR(){
    extern int count,cp;
    count++;
    printf("tick is %d\n",count);
    button.fall(callback(&button_ISR));
    cp=bttn;
    if(count==5){
        count=0;
        led1=!led1;
        if(cp==2){
            timeout1.attach(callback(&led2_ISR),0.5f);
        }
        if(cp==3){
            timeout1.attach(callback(&led3_ISR),0.5f);
        }
        printf("button is %d\n",cp);
        cp=0;
        bttn=0;
    }
    
}
int main(){
    led2=1;
    led3=1;
    timer1.attach(callback(&toggle_ISR),0.3f);
}