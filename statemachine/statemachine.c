/*
*
* Author   - Justin Barnes
* Platform - Attiny85
*
* File     - statemachine.c
*/

#include <avr/io.h>
#include <util/delay.h>

#include "SN74LS47.h"

#define LEG2 0x08
#define LEG3 0x10
#define LEG7 0x04
#define LEG6 0x02
#define RUN_FOREVER 1
typedef struct STATEMACHINE TSTATEMACHINE;

typedef void (*STATEPROC)(TSTATEMACHINE * sm );

struct STATEMACHINE
{
	STATEPROC run;
};

void count_up(TSTATEMACHINE * sm);
void count_down(TSTATEMACHINE * sm);

void main(void)
{
	DDRB = 0x1E;
	TSTATEMACHINE  CurrState;
	CurrState.run = &count_up;
	while (RUN_FOREVER)
	{
		CurrState.run(&CurrState);
	}
}

void count_up(TSTATEMACHINE * sm)
{
	char number = '0';
	while (number++ != '9')
	{
		Display_DIGIT(number, LEG2, LEG3, LEG7, LEG6);
		int i = 0;
		while( i++ < 7)
		_delay_ms(50);
	}
	sm->run = &count_down;
}

void count_down(TSTATEMACHINE * sm)
{
	char number = '9';
	while (number-- != '0')
	{
		Display_DIGIT(number, LEG2, LEG3, LEG7, LEG6);
		int i = 0;
		while (i++ < 7)
			_delay_ms(50);
	}
	sm->run = &count_up;
}