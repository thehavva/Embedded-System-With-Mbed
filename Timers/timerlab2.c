#include "mbed.h"

DigitalOut led1(p5);
DigitalOut led2(p6);
DigitalOut led3(p7);
InterruptIn button(p8);
Ticker timer1;


int count=0;
int button1=0;
int control=0;


void button_sayac(){
    extern int button1;
    
    button1++;
}
void button_ISR(){
    extern int count;
    extern int control;
    count++;
    button.fall(callback(&button_sayac));
    control=button1;

    printf("Ticker count is %d ",count);
    printf("Button count is %d\n",control);
    if(count==5){
        led1=!led1;
         count=0;
        if(control==2){
         led2=!led2;
        }
        if(control==3){
         led3=!led3;
        }
        control=0;
        button1=0;
    }
    else{
        led1=0;
    }
}
int main(){
    timer1.attach(callback(&button_ISR),1.5f);
}