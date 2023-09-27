/*
 * TIMER2.c
 *
 * Created: 9/23/2023 8:14:28 PM
 *  Author: himah
 */ 

#include "timer2.h"
#include <avr/interrupt.h>

static void (* timer2_callback) (void) = NULL;



void timer2_init(){
	
	//clock source from output
	SET_BIT(ASSR_REG,AS2_BIT);
	
	//clock source with prescalar 128
	SET_BIT(TCCR2_REG,CS00_BIT);
	CLR_BIT(TCCR2_REG,CS01_BIT);
	SET_BIT(TCCR2_REG,CS02_BIT);

	//Normal mode
	CLR_BIT(TCCR2_REG,WGM00_BIT);
	CLR_BIT(TCCR2_REG,WGM01_BIT);
	
	//Normal port operation, OC0 disconnected
	CLR_BIT(TCCR2_REG,COM00_BIT);
	CLR_BIT(TCCR2_REG,COM01_BIT);
	

}

void timer2_enable(){
	SET_BIT(SREG_REG,I_BIT);
	//Enable overflow Interrupt
	SET_BIT(TIMSK_REG,TOIE2_BIT);
	
}

void timer2_disable(){
	CLR_BIT(SREG_REG,I_BIT);
	//Enable overflow Interrupt
	CLR_BIT(TIMSK_REG,TOIE2_BIT);
}

void timer2_set_callback(void (*callback) (void)){
	timer2_callback = callback;
}

ISR(TIMER2_OVF_vect){
	timer2_callback();
}