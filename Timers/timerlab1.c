#include "mbed.h"

DigitalOut led1(p5);
DigitalOut led2(p6);
InterruptIn button(p7);
Ticker timer1;
Ticker timer2;

int count=0;
int button_count=0;
int control=0;

void toggle_ISR(){
    extern int count;
    count++;
    printf("Timer count is %d\n",count);
    if(count==4){
        count=0;
    }
}
void button_cnt(){
    extern int button_count;
    button_count++;
}
void button_ISR(){
    extern int control;
    button.fall(callback(&button_cnt));
    control=button_count;
    printf("Button count is %d\n",button_count);
    if(control>3){
        led1=1;
        led2=1;
    }
    else{
        led1=0;
        led2=0;
    }
    control=0;
    button_count=0;
}
int main(){
    timer1.attach(callback(&toggle_ISR),0.5f);
    
    timer2.attach(callback(&button_ISR), 2.0f);
    
}