/*
 * timer.c
 *
 *	Created on: 08-2014
 *      Author: Pawe³ Jarosz
 */


#include <avr/io.h>

#include "timer.h"

void timer_init(void){

	//timer do RTS
	TCCR2|= (1<<WGM21);			//tryb CTC
	TCCR2|= (1<<CS20);			//preskaler 1
	OCR2=159;					//przerwanie porownania co 10 us --> 100.000 Hz
	TIMSK |=(1<<OCIE2);			//odblokowanie przerwania compare match

}


