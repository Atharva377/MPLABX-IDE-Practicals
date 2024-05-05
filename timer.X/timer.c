#include<stdio.h>
#include<stdlib.h>
#include<p18f4550.h>

volatile bit timer_set=0;

void timerInit(void){
    T0CON=0b00000111;
    TMR0H=0XEB;
    TMR0L=0XB0;
}
void Interrupt_Init(void){
    RCONbits.IPEN=1;
    INTCON=0b11100000;
    INTCON2bits.TMR0IP=0;

}
void interrupt low_priority timerinterrupt(void){
    if(TMR0IF==1){
        TMR0ON=0;
        TMR0IF=0;
        TMR0H=0XEB;
        TMR0L=0XB0;
        LATDbits.LATD2= ~LATDbits.LATD2;
        TMR0ON=1;

    }

}
void main(void){
    TRISD=0x00;
    LATDbits.LATD2=1;

    Interrupt_Init();
    timerInit();

    TMR0ON=1;

    while(1);


}