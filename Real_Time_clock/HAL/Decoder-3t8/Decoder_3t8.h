/*
 * Decoder_3t8.h
 *
 * Created: 9/27/2023 12:53:07 AM
 *  Author: himah
 */ 


#ifndef DECODER_3T8_H_
#define DECODER_3T8_H_
#include "../../Std_Macros.h"
#include "../../MCAL/DIO/DIO.h"

#define  DECODER_3T8_PORT PORT_A
#define  DECODER_3T8_PIN0 PIN4
#define  DECODER_3T8_PIN1 PIN5
#define  DECODER_3T8_PIN2 PIN6

void decoder_3t8_init();

void decoder_3t8_write(uint8 data);





#endif /* DECODER_3T8_H_ */