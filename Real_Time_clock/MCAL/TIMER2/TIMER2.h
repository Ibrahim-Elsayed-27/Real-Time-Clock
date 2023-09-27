/*
 * TIMER2.h
 *
 * Created: 9/23/2023 8:14:40 PM
 *  Author: himah
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_

#include "../../Std_Macros.h"

/*Registers*/
#define SREG_REG *((volatile uint8*) 0x5F)
#define OCR2_REG *((volatile uint8*) 0x43)
#define TIMSK_REG *((volatile uint8*) 0x59)
#define TIFR_REG *((volatile uint8*) 0x58)
#define TCCR2_REG *((volatile uint8*) 0x45)
#define TCNT2_REG *((volatile uint8*) 0x44)
#define ASSR_REG *((volatile uint8*) 0x42)



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
#define TOIE2_BIT   6
#define OCIE2_BIT   7

/*TIFR BITS*/
#define TOV2_BIT   6
#define OCF2_BIT   7

/*ASSR BITS*/
#define AS2_BIT   3



void timer2_init();
void timer2_enable();
void timer2_disable();
void timer2_set_callback(void (*callback) (void));

#endif /* TIMER2_H_ */