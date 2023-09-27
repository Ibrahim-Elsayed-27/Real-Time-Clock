/*
 * _7_SEG.c
 *
 * Created: 8/4/2023 4:52:12 PM
 *  Author: himah
 */ 

#include "7_SEG.h"

uint8 numbers_cathode[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x47, 0x7f, 0x6f};
uint8 numbers_anode[] = {~0x3f, ~0x06, ~0x5b, ~0x4f, ~0x66, ~0x6d, ~0x7d, ~0x47, ~0x7f, ~0x6f};
void sev_seg_init(uint8 port){
	port_init(port,OUTPUT);
}

void sev_seg_update(uint8 port, uint8 number){
		#ifdef CC
		uint8 numbers[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x47, 0x7f, 0x6f};
		#else
		uint8 numbers[] = {~0x3f, ~0x06, ~0x5b, ~0x4f, ~0x66, ~0x6d, ~0x7d, ~0x47, ~0x7f, ~0x6f};
		#endif
		port_write(port, numbers[number]);

}


void sev_seg_dec_init(uint8 port, uint8 nibble){
	port_nibble_init(port,nibble,OUTPUT);
}

void sev_seg_dec_update(uint8 port, uint8 nibble, uint8 number){
	port_nibble_write(port,nibble,number);
}