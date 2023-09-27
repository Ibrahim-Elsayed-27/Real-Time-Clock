/*
 * EXTERNAL_INTERRUPT.h
 *
 * Created: 8/11/2023 4:38:03 PM
 *  Author: himah
 */ 


#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_

#include "../../Std_Macros.h"


/*Registers*/
#define SREG_REG *((volatile uint8*) 0x5F)
#define GICR_REG *((volatile uint8*) 0x5B)
#define GIFR_REG *((volatile uint8*) 0x5A)
#define MCUCR_REG *((volatile uint8*) 0x55)
#define MCUCSR_REG *((volatile uint8*) 0x54)

/*MCUCR BITS*/
#define ISC00_BIT 0
#define ISC01_BIT 1
#define ISC10_BIT 2
#define ISC11_BIT 3

/*MCUCSR BITS*/
#define ISC2_BIT  6
 
 /*GICR BITS*/
#define INT1_BIT  7
#define INT0_BIT  6
#define INT2_BIT  5

/*GIFR BITS*/
#define INTF1_BIT  7
#define INTF0_BIT  6
#define INTF2_BIT  5


/*SREG BITS*/
#define I_BIT 7

/*Interrupts*/
#define INT0_t 0
#define INT1_t 1
#define INT2_t 2

/*Interrupt modes*/ 
#define LOW_LEVEL      0
#define ANY_CHANGE    1
#define RISING_EDGE    2
#define FALLING_EDGE   3

/*Functions Prototype*/
void external_interrupt_enable(uint8 interruprt_name,uint8 mode);
void external_interrupt_disable(uint8 interruprt_name);
void external_interrupt_callback(uint8 interrupt_name, void (*callback) (void) );

#endif /* EXTERNAL_INTERRUPT_H_ */