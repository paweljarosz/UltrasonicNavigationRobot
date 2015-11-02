/*
 * motors.h
 *
 *  Created on: 27 paü 2015
 *      Author: Pablo
 */

#ifndef MOTORS_H_
#define MOTORS_H_

// silniki

#define L1 (1<<PD5)				//silnik lewy - piny sterujace mostkami
#define L2 (1<<PD6)
#define L3 (1<<PD4)
#define L4 (1<<PD7)

#define R1 (1<<PD2)				//silnik prawy
#define R2 (1<<PD3)
#define R3 (1<<PD0)
#define R4 (1<<PD1)

#define L11 (PORTD |= L1)		//ustawianie stanow wysokich na pinach
#define L21 (PORTD |= L2)
#define L31 (PORTD |= L3)
#define L41 (PORTD |= L4)
#define R11 (PORTD |= R1)
#define R21 (PORTD |= R2)
#define R31 (PORTD |= R3)
#define R41 (PORTD |= R4)

#define L10 (PORTD &=~ L1)		//zerowanie do stanow niskich na pinach
#define L20 (PORTD &=~ L2)
#define L30 (PORTD &=~ L3)
#define L40 (PORTD &=~ L4)
#define R10 (PORTD &=~ R1)
#define R20 (PORTD &=~ R2)
#define R30 (PORTD &=~ R3)
#define R40 (PORTD &=~ R4)

volatile uint8_t state_mot_l;		//obecny stan cewek silnikow bipolarnych
volatile uint8_t state_mot_r;
volatile uint8_t act_step_l;		//obecny krok silnikow (actual step)
volatile uint8_t act_step_r;
volatile uint8_t MC_l;				//flaga ukonczonego ruchu (motion complete)
volatile uint8_t MC_r;

void motors_init(void);
void mot_left_go(void);
void mot_right_go(void);
void mot_left_rev(void);
void mot_right_rev(void);
void forward_step(uint8_t step);
void forward(uint8_t cm);
void backward_step(uint8_t step);
void backward(uint8_t cm);
void turn_left_step(uint8_t step);
void turn_left(uint8_t deg);
void turn_right_step(uint8_t step);
void turn_right(uint8_t deg);

#endif /* MOTORS_H_ */
