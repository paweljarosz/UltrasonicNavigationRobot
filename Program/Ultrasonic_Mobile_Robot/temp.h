/*
 * temp.h
 *
 *  Created on: 27 paü 2015
 *      Author: Pablo
 */

#ifndef TEMP_H_
#define TEMP_H_

#define TEMP (1<<PB0)				//pin wejsciowy z czujnika temperatury

#define LEDL (1<<PB2)				//piny wyjsciowe na ledy
#define LEDR (1<<PB1)

#define LEDL1 (PORTB |= LEDL)		//wlaczanie diod
#define LEDR1 (PORTB |= LEDR)

#define LEDL0 (PORTB &=~ LEDL)		//wylaczanie diod
#define LEDR0 (PORTB &=~ LEDR)

#define LEDLtog (PORTB ^= LEDL)		//przelaczanie stanu led
#define LEDRtog (PORTB ^= LEDR)

#endif /* TEMP_H_ */
