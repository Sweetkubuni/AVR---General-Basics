/*
	filename - pwm.c
	target - attiny85

	author - Justin Barnes
*/
#include <avr/io.h>
#include <util/delay.h>

/*
	duty cycle 0 to 255
*/
void Set_DutyCycle(uint8_t duty)
{
	OCR0A = duty;
}

int main(void)
{
	/*
		initialize program for fast pwm
	*/

	/*
		DDRB sets the direction of the pin.
		Setting pin OC0A
	*/
	DDRB = 0b00000001;

	TCCR0A |=  (1 << WGM02) | (1 << WGM00)| (1 << COM0A1) | (1 << CS00);

	Set_DutyCycle(85);

	while (1)
	{

	}
	return 0;
}