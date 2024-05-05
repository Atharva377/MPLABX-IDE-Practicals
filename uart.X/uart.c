#include<stdio.h>
#include<stdlib.h>
#include<p18f4550.h>
#define Fosc 48000000UL

void InitUART(unsigned int baudrate){
    TRISCbits.RC6=0;
    TRISCbits.RC7=1;

    SPBRG=(unsigned char)(((Fosc/64)/baudrate)-1);
    BAUDCON=0b00000000;
    TXSTA=0b00100000;
    RCSTA=0b10010000;

}
void send_char(unsigned char data){
    while(TXSTAbits.TRMT==0);
    TXREG=data;

}
void putch(unsigned char data){

    send_char(data);
}
unsigned char getchar(void){
    while(!PIR1bits.RCIF);
    return RCREG;

}
void main(void){
    InitUART(9600);
    printf("\r\nHello MICRO-P18-Enter any key from keyword\r\n");
    while(1){
        printf("%c",getchar());
    }

    while(1);
}
