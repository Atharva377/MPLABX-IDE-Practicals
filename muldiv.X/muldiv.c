#include<stdio.h>
#include<stdlib.h>
#include<p18f4550.h>

void main(void){
    int mul=0;
    int div=0;
    mul=0X06*0X01;
    div=0X04/0X02;
   
    TRISC=0;
    PORTC=mul;
     TRISD=0;
    PORTD=div;
}

