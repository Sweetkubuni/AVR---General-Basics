/* 
	blinker.c
	
	A simple blinky program for ATtiny85
	Connect red LED at pin 2 (PB3)
*/
#define __AVR_ATtiny85__
#include <avr/io.h>
#include <util/delay.h>
 
 
void main (void)
{
  // set PB3 to be output
	DDRB = 0b00001000;
	int i;
  while (1) {
    
    // flash# 1:
    // set PB3 high
    PORTB = 0b00001000;
	i = 100;
	while(--i)
    _delay_ms(50);
    // set PB3 low
    PORTB = 0b00000000;
	i = 100;
	while(--i)
    _delay_ms(50);
  }
 
}