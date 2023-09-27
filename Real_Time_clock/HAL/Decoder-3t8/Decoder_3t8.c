/*
 * Decoder_3t8.c
 *
 * Created: 9/27/2023 12:53:20 AM
 *  Author: himah
 */ 
#include "Decoder_3t8.h"

void decoder_3t8_init(){
	pin_init(DECODER_3T8_PORT,DECODER_3T8_PIN0,OUTPUT);
	pin_init(DECODER_3T8_PORT,DECODER_3T8_PIN1,OUTPUT);
	pin_init(DECODER_3T8_PORT,DECODER_3T8_PIN2,OUTPUT);
}
void decoder_3t8_write(uint8 data){
	pin_write(DECODER_3T8_PORT,DECODER_3T8_PIN0, GET_BIT(data,0) );
	pin_write(DECODER_3T8_PORT,DECODER_3T8_PIN1, GET_BIT(data,1) );
	pin_write(DECODER_3T8_PORT,DECODER_3T8_PIN2, GET_BIT(data,2) );
}