#include "SN74LS47.h"
#include <avr/io.h>
#define CLEAR(port) port = 0x00

void Display_DIGIT(char digit, uint8_t A, uint8_t B, uint8_t C, uint8_t D)
{
	switch (digit)
	{
	case '0':
		CLEAR(PORTB);
		break;
	case '1':
		CLEAR(PORTB);
		PORTB = A;
		break;
	case '2':
		CLEAR(PORTB);
		PORTB = B;
		break;
	case '3':
		CLEAR(PORTB);
		PORTB = A | B;
		break;
	case '4':
		CLEAR(PORTB);
		PORTB = C;
		break;
	case '5':
		CLEAR(PORTB);
		PORTB = A | C;
		break;
	case '6':
		CLEAR(PORTB);
		PORTB = B | C;
		break;
	case '7':
		CLEAR(PORTB);
		PORTB = B | C | A;
		break;
	case '8':
		CLEAR(PORTB);
		PORTB = D;
		break;
	case '9':
		CLEAR(PORTB);
		PORTB = D | A;
		break;
	default:
		CLEAR(PORTB);
		PORTB = D | C;
		break;
	}
}