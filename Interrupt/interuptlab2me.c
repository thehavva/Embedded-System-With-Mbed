#include "mbed.h"

DigitalOut red_led(p5);
DigitalOut blue_led(p6);
InterruptIn button(p7);

int count=0;

void toggle(){
    extern int  count;
    count++;
    printf("count is %d\n",count);
    
    wait_ms(1000);
    if(count==3){
        blue_led=0;
        wait_ms(100);
        blue_led=1;
        wait_ms(100);
        blue_led=0;
        wait_ms(100);
        blue_led=1;
        wait_ms(100);
        blue_led=0;
        wait_ms(100);
        blue_led=1;
        count=0;
    }
    if(count==5){
        red_led=0;
        wait_ms(100);
        red_led=1;
        wait_ms(100);
        red_led=0;
        wait_ms(100);
        red_led=1;
        wait_ms(100);
         red_led=0;
        wait_ms(100);
        red_led=1;
        wait_ms(100);
         red_led=0;
        wait_ms(100);
        red_led=1;
        
        count=0;
    }
    
    if(count>5){
        count=0;
    }
    
    if(count!=3){
        blue_led=1;
    }
    if(count!=5){
        blue_led=1;
    }
    
    
}

int main(){
    blue_led=1;
    red_led=1;
    button.fall(callback(&toggle));
    wait_ms(osWaitForever);
}