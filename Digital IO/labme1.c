#include "mbed.h"

DigitalOut red_led(p5);
DigitalOut blue_led(p6);
DigitalIn  button1(p7);
DigitalIn  button2(p8);

int cnt_blue=0;
int cnt_red=0;

int main(){
    red_led=0;
    blue_led=0;
    
    while(true){
        if(button1==1){
            cnt_blue++;
            printf("blue led : %d\n",cnt_blue);
        }
        if(button2==1){
            cnt_red++;
            printf("red led : %d\n",cnt_red);
        }
        
        if(cnt_blue==4){
            blue_led=1;
        }
        if(cnt_blue==6){
            blue_led=0;
            cnt_blue=0;
        }
        
        if(cnt_red==5){
            red_led=1;
        }
        if(cnt_red==7){
            red_led=0;
            cnt_red=0;
        }
        
        wait_ms(200);
    }
}