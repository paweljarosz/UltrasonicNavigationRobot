/*
 * motors.c
 *
 *  Created on: 27 paü 2015
 *      Author: Pablo
 */

#include <avr/io.h>

#include "motors.h"
#include "temp.h"

void motors_init(void){

	DDRD |= L1;			//ustawienie pinow sterowania silnikow jako wyjscia
	DDRD |= L2;
	DDRD |= L3;
	DDRD |= L4;
	DDRD |= R1;
	DDRD |= R2;
	DDRD |= R3;
	DDRD |= R4;

	L10;				//zerowanie do stanow niskich na pinach
	L20;
	L30;
	L40;
	R10;
	R20;
	R30;
	R40;

	act_step_l=0;		//wyzerowanie krokow
	act_step_r=0;
	state_mot_l=0;		//stan cewek silnikow
	state_mot_r=0;
	MC_l=1;				//flaga zakonczonego ruchu silnikow
	MC_r=1;
}

void mot_left_go(void)	//krok lewego silnika do przodu
{
	switch(state_mot_l)
	{
	case 0:
			L10;
			L21;
			L31;
			LEDLtog;
	break;
	case 1:
			L10;
			L21;
			L30;
			L31;
			LEDLtog;
	break;
	case 2:
			L11;
			L20;
			L30;
			L31;
			LEDLtog;
	break;
	case 3:
			L11;
			L20;
			L31;
			L30;
			LEDLtog;
	break;
	default:
	break;
	}

	state_mot_l++;
}

void mot_right_go()		//krok prawego silnika do przodu
{

}

void mot_left_rev()		//krok lewego silnika do tylu
{

}

void mot_right_rev()	//krok prawego silnika do tylu
{

}

void forward_step(uint8_t step)	//ruch robota do przodu o dana ilosc krokow
{
	if(act_step_l<step)
	{
		MC_l=0;
		mot_left_go();
		if (state_mot_l>3)
			state_mot_l=0;
	}
	else
		MC_l=1;
	act_step_l++;

}

void forward(uint8_t cm)
{

}

void backward_step(uint8_t step)
{

}

void backward(uint8_t cm)
{

}

void turn_left_step(uint8_t step)
{

}

void turn_left(uint8_t deg)
{

}

void turn_right_step(uint8_t step)
{

}

void turn_right(uint8_t deg)
{

}
