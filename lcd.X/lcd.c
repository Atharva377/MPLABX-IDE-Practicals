#include<stdio.h>
#include<stdlib.h>
#include<p18f4550.h>
unsigned char *string1="AISSMS";
unsigned char *string2="IOIT";

void delay(){

    int i;
    for(i=0;i<10000;i++);

}
void send_instruction(unsigned char command){
    LATCbits.LATC0=0;
    PORTB=command;
    LATCbits.LATC1=1;
    delay();
    LATCbits.LATC1=0;

}
void send_data(unsigned char data){
    LATCbits.LATC0=1;
    PORTB=data;
    LATCbits.LATC1=1;
    delay();
    LATCbits.LATC1=0;

}
void main(void){
    TRISB=0;
    TRISCbits.RC0=0;
    TRISCbits.RC1=0;
    send_instruction(0X38);
    send_instruction(0X06);
    send_instruction(0X0C);
    send_instruction(0X01);
    send_instruction(0X80);

    while(*string1){
        send_data(*string1);
        string1++;
    }
     while(*string2){
        send_data(*string2);
        string2++;
    }

}
