/*
 * TIMER0.h
 *
 * Created: 9/23/2023 8:14:40 PM
 *  Author: himah
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "../../Std_Macros.h"

/*Registers*/
#define SREG_REG *((volatile uint8*) 0x5F)
#define OCR0_REG *((volatile uint8*) 0x5C)
#define TIMSK_REG *((volatile uint8*) 0x59)
#define TIFR_REG *((volatile uint8*) 0x58)
#define TCCR0_REG *((volatile uint8*) 0x53)
#define TCNT0_REG *((volatile uint8*) 0x52)



/*SREG BITS*/
#define I_BIT 7


/*TCCR0 BITS*/	
#define CS00_BIT	0
#define CS01_BIT	1
#define CS02_BIT	2
#define WGM01_BIT	3
#define COM00_BIT	4
#define COM01_BIT	5
#define WGM00_BIT	6
#define FOC0_BIT	7

/*TIMSK BITS*/	
#define TOIE0_BIT   0
#define OCIE0_BIT   1

/*TIFR BITS*/
#define TOV0_BIT   0
#define OCF0_BIT   1


void timer0_init();
void timer0_enable();
void timer0_disable();
void timer0_set_callback(void (*callback) (void));

#endif /* TIMER0_H_ */