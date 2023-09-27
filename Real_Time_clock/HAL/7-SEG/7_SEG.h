/*
 * _7_SEG.h
 *
 * Created: 8/4/2023 4:52:25 PM
 *  Author: himah
 */ 


#ifndef SEV_SEG_H_
#define SEV_SEG_H_
#include "../../Std_Macros.h"
#include "../../MCAL/DIO/DIO.h"

void sev_seg_init(uint8 port);
void sev_seg_update(uint8 port, uint8 number);
void sev_seg_dec_init(uint8 port, uint8 nibble);
void sev_seg_dec_update(uint8 port, uint8 nibble, uint8 number);


#endif /* 7_SEG_H_ */