#include<stdio.h>
#include<stdlib.h>
#include<p18f4550.h>

void main(void){

    int sum,diff;
    sum=0;
    diff=0;
    sum=0x02 + 0X04;
    diff=0x08 - 0X03;
    TRISC=0;
    PORTC=sum;
    TRISD=0;
    PORTD=diff;
}
