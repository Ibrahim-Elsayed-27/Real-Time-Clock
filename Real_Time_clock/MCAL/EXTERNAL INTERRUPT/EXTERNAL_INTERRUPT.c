/*
 * EXTERNAL_INTERRUPT.c
 *
 * Created: 8/11/2023 4:36:40 PM
 *  Author: himah
 */ 
#include "EXTERNAL_INTERRUPT.h"
#include <avr/interrupt.h>

/*initialize the isr functions for each interrupt to null */
 static void (*external_interrupt_0_callback) (void) = NULL;
 static void (*external_interrupt_1_callback) (void) = NULL;
 static void (*external_interrupt_2_callback) (void) = NULL;



void external_interrupt_enable(uint8 interruprt_name,uint8 mode){
	SET_BIT(SREG_REG,I_BIT);
	switch(interruprt_name){
		case(INT0_t):
			switch(mode){
				case(LOW_LEVEL):
					CLR_BIT(MCUCR_REG,ISC00_BIT);
					CLR_BIT(MCUCR_REG,ISC01_BIT);
					break;
				case(ANY_CHANGE):
					SET_BIT(MCUCR_REG,ISC00_BIT);
					CLR_BIT(MCUCR_REG,ISC01_BIT);					
					break;
				case(FALLING_EDGE):
					CLR_BIT(MCUCR_REG,ISC00_BIT);
					SET_BIT(MCUCR_REG,ISC01_BIT);
					break;
				case(RISING_EDGE):
					SET_BIT(MCUCR_REG,ISC00_BIT);
					SET_BIT(MCUCR_REG,ISC01_BIT);
					break;
			}
			SET_BIT(GICR_REG,INT0_BIT);
			break;
		case(INT1_t):
			switch(mode){
				case(LOW_LEVEL):
				CLR_BIT(MCUCR_REG,ISC10_BIT);
				CLR_BIT(MCUCR_REG,ISC11_BIT);
				break;
				case(ANY_CHANGE):
				SET_BIT(MCUCR_REG,ISC10_BIT);
				CLR_BIT(MCUCR_REG,ISC11_BIT);
				break;
				case(FALLING_EDGE):
				CLR_BIT(MCUCR_REG,ISC10_BIT);
				SET_BIT(MCUCR_REG,ISC11_BIT);
				break;
				case(RISING_EDGE):
				SET_BIT(MCUCR_REG,ISC10_BIT);
				SET_BIT(MCUCR_REG,ISC11_BIT);
				break;
			}
			SET_BIT(GICR_REG,INT1_BIT);
			break;
		case(INT2_t):
			
			switch(mode){
				case(FALLING_EDGE):
				CLR_BIT(MCUCSR_REG,ISC2_BIT);
				break;
				case(RISING_EDGE):
				SET_BIT(MCUCSR_REG,ISC2_BIT);
				break;
			}
			SET_BIT(GICR_REG,INT2_BIT);
			break;
		
	}
}
void external_interrupt_disable(uint8 interruprt_name){
		CLR_BIT(SREG_REG,I_BIT);
		switch(interruprt_name){
			case(INT0_t):
			CLR_BIT(GICR_REG,INT0_BIT);
			break;
			case(INT1_t):
			CLR_BIT(GICR_REG,INT1_BIT);
			break;
			case(INT2_t):
			CLR_BIT(GICR_REG,INT2_BIT);
			break;
			
		}
}



/*
Setting the callback function for a given interrupt and the corresponding function to be executed upon calling
*/

void external_interrupt_callback(uint8 interrupt_name, void (*callback) (void) ){
	switch(interrupt_name){
		case INT0_t:
		external_interrupt_0_callback=callback;
		break;
		case INT1_t:
		external_interrupt_1_callback=callback;
		break;
		case INT2_t:
		external_interrupt_2_callback=callback;
		break;
	}
}


ISR(INT0_vect){
	external_interrupt_0_callback();
}

ISR(INT1_vect){
	external_interrupt_1_callback();
}

ISR(INT2_vect){
	external_interrupt_2_callback();
}
