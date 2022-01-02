#include "mbed.h"

DigitalOut  blue_led(p5);
DigitalOut  red_led(p6);
DigitalIn   button1(p7);
DigitalIn   button2(p8);

int count1=0;
int count2=0;

void toggle_blue(){
    ++count1;
    if(count1==4){
        blue_led!=blue_led;
        count1=0;
        wait_ms(200);
    }
}

void toggle_red(){
    ++count2;
    if(count2==6){
        red_led!=red_led;
        count2=0;
        wait_ms(800);
    }
}
int main(){
    button1.fall(callback(&toggle_blue));
    button2.fall(callback(&toggle_red));
    wait_ms(osWaitForever);
    
}