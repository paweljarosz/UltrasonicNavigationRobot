/*
 * main.c
 *
 *      Autor: Pawe³ Jarosz
 *
 *	  Program jest integralna czescia pracy inzynierskiej autora i
 *	  zostal w calosci napisany przez niego i podlega prawom autorskim.
 *
 *    Program sluzy do obslugi robota z trzema sensorami ultradzwiekowymi.
 *    Praca robota sklada sie z rozpoznania terenu, zapisaniu do pamieci danych
 *    i poruszaniu sie do przodu w celu budowania mapy otoczenia.
 *
 */

#include <avr\io.h>
#include <avr\interrupt.h>
#include "timer.h"
#include "ultrasonic.h"
#include "motors.h"
#include "temp.h"
#include <util\delay.h>

volatile uint8_t main_state;

int main(void)
{


	//-----------USTAWIANIE TIMERA i GPIO---------------------------------------------
	timer_init();
	us_init();
	motors_init();
	//--------------------------------------------------------------------------------
	sei();					//globalne zezwolenie na przerwania;

	Timer1=1;				//inicjacja zadan
	Timer2=20;
	Timer3=100;

	main_state=0;



while(1)//****************************************************************************
{


	if(!Timer1)		//#################  timer1 glowny - menu  #######################
	{
		forward_step(10);

	Timer1=320001;		//1 s
	}//koniec obslugi Timer1__________________________________________________________



	if(!Timer2)		//############  timer2 do pomiaru odleglosci z sonarow  ##########
	{
		if(MC_l==1)
			LEDR1;
		else
			LEDL0;

	Timer2=640000;		//2 s
	}//koniec obslugi Timer2__________________________________________________________



	if(!Timer3)		//#################  timer3 do obslugi silnikow   #################
	{



	}//koniec obslugi Timer3__________________________________________________________



}//koniec pelti while***************************************************************************

}//koniec funkcji main


ISR(TIMER2_COMP_vect)//=================PROCEDURA OBSLUGI PRZERWANIA OD TIMERA==================
	{
		uint16_t x;
		x=Timer1;
		if(x)
		Timer1 = --x;
		x=Timer2;
		if(x)
		Timer2 = --x;
		x=Timer3;
		if(x)
		Timer3 = --x;

	}//koniec obslugi przerwania================================================================
