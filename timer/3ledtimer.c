/*
	file: 3ledtimer.c
*/

#include<avr/io.h>
#include <avr/interrupt.h>
void main(void)
{
	TCCR0 = 0x5;
}