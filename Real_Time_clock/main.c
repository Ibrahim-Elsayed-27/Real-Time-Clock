/*
 * Real_Time_clock.c
 *
 * Created: 9/26/2023 11:56:03 PM
 * Author : himah
 */ 

#include "MCAL/TIMER0/TIMER0.h"
#include "MCAL/TIMER2/TIMER2.h"
#include "MCAL/EXTERNAL INTERRUPT/EXTERNAL_INTERRUPT.h"
#include "MCAL/DIO/DIO.h"

#define F_CPU 8000000UL
#include <util/delay.h>

#include "HAL/7-SEG/7_SEG.h"
#include "HAL/Decoder-3t8/Decoder_3t8.h"
#include "HAL/KEYPAD/keypad.h"
#include "HAL/LCD/LCD.h"


void real_time();
void sev_seg_polling();
void update_clock();
volatile uint8 seconds_counter;
volatile uint8 minutes_counter;
volatile uint8 hours_counter;
int main(void)
{
    timer0_init();
	timer0_enable();
	timer0_set_callback(sev_seg_polling);
	
	timer2_init();
	timer2_enable();
	timer2_set_callback(real_time);
	
	
	sev_seg_dec_init(PORT_A,LOW_NIBBLE);
	decoder_3t8_init();
	keypad_init();
	lcd_init();
	uint8 keypad_check;
    while (1) 
    {
		lcd_clear_screen();
		lcd_send_string("Press 'A'");
		lcd_move_cursor(2,1);
		lcd_send_string("To Update");
		do 
		{
			keypad_check = keypad_read();
			_delay_ms(200);
		} while (keypad_check != 'A');
		update_clock();
    }
}

void sev_seg_polling(){
	static uint8 enable_counter;
	if (enable_counter == 6){
		enable_counter = 0; 
	}
	decoder_3t8_write(enable_counter);
	switch (enable_counter){
		case 0:
			sev_seg_dec_update(PORT_A,LOW_NIBBLE,seconds_counter%10);
			break;
		case 1:
			sev_seg_dec_update(PORT_A,LOW_NIBBLE,seconds_counter/10);
			break;
		case 2:
			sev_seg_dec_update(PORT_A,LOW_NIBBLE,minutes_counter%10);
			break;
		case 3:
			sev_seg_dec_update(PORT_A,LOW_NIBBLE,minutes_counter/10);
			break;
		case 4:
			sev_seg_dec_update(PORT_A,LOW_NIBBLE,hours_counter%10);
			break;
		case 5:
			sev_seg_dec_update(PORT_A,LOW_NIBBLE,hours_counter/10);
			break;
				
	}
	enable_counter++;
}


void real_time(){
	seconds_counter++;
	if(seconds_counter >= 60){
		seconds_counter = 0;
		minutes_counter++;
	}
	if(minutes_counter >= 60){
		minutes_counter = 0;
		hours_counter++;
	}
	if(hours_counter >= 24){
		hours_counter = 0;
	}
	
	
}


void update_clock(){
		uint8 keypad_check;
		
		/*Set Hours*/
		lcd_clear_screen();
		lcd_send_string("Hours:__");
		lcd_move_cursor(1,7);
		do 
		{
			keypad_check = keypad_read();
			_delay_ms(200);
		} while (keypad_check == 0xff);
		lcd_send_char(keypad_check);
		hours_counter= (keypad_check-48)*10;
		
		do 
		{
			keypad_check = keypad_read();
			_delay_ms(200);
		} while (keypad_check == 0xff);
		lcd_send_char(keypad_check);
		hours_counter += keypad_check-48;
		
		
		
		
		/*Set Minutes*/
		lcd_clear_screen();
		lcd_send_string("Minutes:__");
		lcd_move_cursor(1,9);
		do
		{
			keypad_check = keypad_read();
			_delay_ms(200);
		} while (keypad_check == 0xff);
		lcd_send_char(keypad_check);
		minutes_counter= (keypad_check-48)*10;
		
		do
		{
			keypad_check = keypad_read();
			_delay_ms(200);
		} while (keypad_check == 0xff);
		lcd_send_char(keypad_check);
		minutes_counter += keypad_check-48;
		
		
		
		
		/*Set Seconds*/
		lcd_clear_screen();
		lcd_send_string("Seconds:__");
		lcd_move_cursor(1,9);
		do
		{
			keypad_check = keypad_read();
			_delay_ms(200);
		} while (keypad_check == 0xff);
		lcd_send_char(keypad_check);
		seconds_counter= (keypad_check-48)*10;
		
		do
		{
			keypad_check = keypad_read();
			_delay_ms(200);
		} while (keypad_check == 0xff);
		lcd_send_char(keypad_check);
		seconds_counter += keypad_check-48;
		
}