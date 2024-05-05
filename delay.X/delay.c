#include<stdio.h>
#include<stdlib.h>
#include<p18f4550.h>

void delay(){
    int i;
    for(i=0;i<10000;i++);
}
void main(void){
    TRISDbits.TRISD0=1;
    TRISDbits.TRISD1=1;
    TRISDbits.TRISD2=0;
    TRISAbits.TRISA4=0;
    while(1){

        if(PORTDbits.RD0==1){
            LATDbits.LATD2=1;
            LATAbits.LATA2=0;
        }
       if(PORTDbits.RD1==1){
            LATDbits.LATD2=0;
            LATAbits.LATA2=1;
        }
    }
}
