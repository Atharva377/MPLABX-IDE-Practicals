#include<stdio.h>
#include<stdlib.h>
#include<p18f4550.h>
void delay(){
    int i;
    for(i=0;i<10000;i++){
    }

}

void main(void){
    TRISB=0;
    while(1){
        LATBbits.LATB0=1;
        LATBbits.LATB1=1;
        delay();
        LATBbits.LATB0=0;
        LATBbits.LATB1=0;
        delay();
    }

}