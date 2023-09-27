/*
 * TIMER0.c
 *
 * Created: 9/23/2023 8:14:28 PM
 *  Author: himah
 */ 

#include "TIMER0.h"
#include <avr/interrupt.h>

static void (* timer0_callback) (void) = NULL;



void timer0_init(){
	
	//clock source with prescalar 1024
	SET_BIT(TCCR0_REG,CS00_BIT);
	CLR_BIT(TCCR0_REG,CS01_BIT);
	SET_BIT(TCCR0_REG,CS02_BIT);

	//ctc mode
	CLR_BIT(TCCR0_REG,WGM00_BIT);
	SET_BIT(TCCR0_REG,WGM01_BIT);
	
	//Normal port operation, OC0 disconnected
	CLR_BIT(TCCR0_REG,COM00_BIT);
	CLR_BIT(TCCR0_REG,COM01_BIT);
	
	//Initial value for OCR0
	OCR0_REG = 60;

}

void timer0_enable(){
	SET_BIT(SREG_REG,I_BIT);
	//Enable Output Compare Match Interrupt
	SET_BIT(TIMSK_REG,OCIE0_BIT);
	
}

void timer0_disable(){
	CLR_BIT(SREG_REG,I_BIT);
	//Enable Output Compare Match Interrupt
	CLR_BIT(TIMSK_REG,OCIE0_BIT);
}

void timer0_set_callback(void (*callback) (void)){
	timer0_callback = callback;
}

ISR(TIMER0_COMP_vect){
	timer0_callback();
}