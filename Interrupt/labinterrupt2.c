#include "mbed.h"

DigitalOut  blue_led(p5);
DigitalOut  red_led(p6);
InterruptIn button(p7);

int blue_cont=0;
int red_cont=0;

void toggle(){
    blue_cont++;
    red_cont++;
    
    if(blue_cont%4==0){
        blue_led=1;
        blue_cont=0;
    }
    else
    blue_led=0;
    printf("led blue : %d\n",blue_cont);  
    
    if(red_cont%6==0){
        red_led=1;
        red_cont=0;
    }
    else
    red_led=0;
    printf("red blue : %d\n",red_cont);  
    
    wait_ms(200);
}


int main(){
   button.fall(callback(&toggle));
   
}