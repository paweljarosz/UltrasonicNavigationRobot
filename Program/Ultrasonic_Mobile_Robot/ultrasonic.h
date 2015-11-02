/*
 * ultrasonic.h
 *
 *  Created on: 20 wrz 2015
 *      Author: Pablo
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

// sensory ultradzwiekowe

#define USL_TRIG (1<<PC4)			//pin trigger sensora lewego
#define USL_ECHO (1<<PC5)			//pin echo sensora lewego
#define USR_TRIG (1<<PC0)			//pin trigger sensora prawego
#define USR_ECHO (1<<PC1)			//pin echo sensora prawego
#define USC_TRIG (1<<PC2)			//pin trigger sensora centralnego
#define USC_ECHO (1<<PC3)			//pin echo sensora centralnego

#define TL1 (PORTC |= USL_TRIG)		//ustawianie stanow wysokich na pinach
#define TR1 (PORTC |= USR_TRIG)
#define TC1 (PORTC |= USC_TRIG)
#define TL0 (PORTC &=~ USL_TRIG)	//zerowanie do stanow niskich na pinach
#define TR0 (PORTC &=~ USR_TRIG)
#define TC0 (PORTC &=~ USC_TRIG)

#define TLtog (PORTC ^= USL_TRIG)		//zmiana stanu na pinach
#define TCtog (PORTC ^= USL_TRIG)
#define TRtog (PORTC ^= USL_TRIG)

#define EL (!(PINC & USL_ECHO))		//sprawdzanie stanu niskiego na pinach echo
#define EC (!(PINC & USC_ECHO))
#define ER (!(PINC & USR_ECHO))

volatile uint8_t result_us,state_us;

void us_init(void);
uint8_t us_measure(uint8_t sensor);


#endif /* ULTRASONIC_H_ */
