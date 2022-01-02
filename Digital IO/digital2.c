#include "mbed.h"

DigitalOut  blue_led(p5);
DigitalOut  red_led(p6);
DigitalIn   button1(p7);
DigitalIn   button2(p8);

int blue_cont=0;
int red_cont=0;

int cont_blue(){
    if(button1==1){
        blue_cont++;
        printf("blue control is %d\n",blue_cont);
    }
    return blue_cont;
}

int cont_red(){
    if(button2==1){
        red_cont++;
        printf("red control is %d\n",red_cont);
    }
    return red_cont;
}
int main(){
    int blue;
    int red;
    while(1){
        blue=cont_blue();
        red=cont_red();
        if(blue%4==0){
            blue_led=1;
        }
        else
        blue_led=0;
        
        if(red%5==0){
            red_led=1;
        }
        else
        red_led=0;
        
        wait_ms(200);
    }
}