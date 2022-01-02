#include "mbed.h"

//to simulate the proximity sensor
DigitalIn   proximity_value(p5);

//to simulate  the light control unit
DigitalOut  light_control(p6);

int main(){
    light_control=0;
    while(1){
        if(proximity_value==1){
            light_control=1;
        }
        else
        light_control=0;

        wait_ms(500);
    }
}