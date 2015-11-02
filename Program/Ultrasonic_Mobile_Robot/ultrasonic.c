/*
 * ultrasonic.c
 *
 *  Created on: 20 wrz 2015
 *      Author: Pablo
 */

#include <avr/io.h>

#include "ultrasonic.h"

void us_init(void){

	DDRC |= USL_TRIG;			//ustawienie pinow trigger jako wyjscia
	DDRC |= USR_TRIG;
	DDRC |= USC_TRIG;

	TL0;						//wyzerowanie stanow na wyjsciach tych pinow
	TR0;
	TC0;

	DDRC &=~ USL_ECHO;			//ustawienie pinow echo jako wejscia
	DDRC &=~ USR_ECHO;
	DDRC &=~ USC_ECHO;

}

uint8_t us_measure(uint8_t state)
{
	uint8_t result;
	switch(state)
	{
	case 0:
		result=2;			//20 us impuls na trigger USL
		TL1;
		break;
	case 1:

		break;
	default:
		break;
	}



	return result;
}
