#include "mbed.h"

DigitalOut blue_led(p5);
DigitalOut red_led(p6);
InterruptIn button(p7);

int count_blue=0;
int count_red=0;

void toggle(){
    extern int  count_blue;
    extern int  count_red;
    count_blue++;
    count_red++;
    printf("count blue is %d\n",count_blue);
    printf("count red is %d\n\n",count_red);
    
    wait_ms(2000);
    if(count_blue==3){
        blue_led=0;
        count_blue=0;
        wait_ms(300);
        blue_led=1;
    }
    if(count_red==5){
        red_led=0;
        count_red=0;
        wait_ms(500);
        red_led=1;
    }
}

int main(){
    blue_led=1;
    red_led=1;
    button.fall(callback(&toggle));
    wait_ms(osWaitForever);
}