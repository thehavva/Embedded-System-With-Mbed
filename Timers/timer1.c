#include "mbed.h"

DigitalOut blue_led(p5);
DigitalOut red_led(p6);

Ticker timer1;
Ticker timer2;
void toggle_blue(){
    blue_led!=blue_led;
}

void toggle_red(){
    red_led!=red_led;
}

int main(){
    timer1.attach(callback(&toggle_blue),2.0f);
    timer2.attach(callback(&toggle_red),1.0f);
    wait_ms(osWaitForever);
}