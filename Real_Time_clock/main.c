/*
 * Real_Time_clock.c
 *
 * Created: 9/26/2023 11:56:03 PM
 * Author : himah
 */ 

#include "MCAL/TIMER0/TIMER0.h"
#include "MCAL/TIMER2/TIMER2.h"


#define F_CPU 8000000UL
#include <util/delay.h>

#include "HAL/7-SEG/7_SEG.h"
#include "HAL/Decoder-3t8/Decoder_3t8.h"
#include "HAL/KEYPAD/keypad.h"
#include "HAL/LCD/LCD.h"
#include "HAL/LED/LED.h"


void real_time();
void stop_watch();
void alarm();
void sev_seg_polling();
void update_clock(uint8 source);

volatile uint8 seconds_counter;
volatile uint8 minutes_counter;
volatile uint8 hours_counter;
volatile uint8 stop_watch_flag;
volatile uint8 alarm_flag;
volatile uint8 alarm_seconds;
volatile uint8 alarm_minutes;
volatile uint8 alarm_hours;
volatile uint8 wait_seconds;
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
	
	led_init(PORT_D,PIN0);
	uint8 keypad_check;
    while (1) 
    {
		lcd_clear_screen();
		lcd_send_string("1-Clock 2-Stop");
		lcd_move_cursor(2,1);
		lcd_send_string("3-Alarm");
		do 
		{
			keypad_check = keypad_read();
			_delay_ms(200);
			if(stop_watch_flag == 1 || alarm_flag == 1){
				stop_watch_flag = 0;
				alarm_flag = 0;
				wait_seconds = 10;
				while(wait_seconds != 0){
					led_on(PORT_D,PIN0);
				}
			led_off(PORT_D,PIN0);
			}
		} while (keypad_check != '1' && keypad_check != '2' && keypad_check != '3');
		
		
		
		if(keypad_check == '1'){
			update_clock(1);
			timer2_set_callback(real_time);
			
		}
		else if(keypad_check == '2'){
			update_clock(2);
			timer2_set_callback(stop_watch);
			
		}
		else if(keypad_check == '3'){
			update_clock(3);
			timer2_set_callback(alarm);
			
		}

			
		
		
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


void stop_watch(){
	if(seconds_counter == 0 && minutes_counter == 0 && hours_counter == 0){
			stop_watch_flag = 1;
		}
	seconds_counter--;
	wait_seconds--;
	if(seconds_counter == 255){
		seconds_counter = 59;
		minutes_counter--;
	}
	if(minutes_counter == 255){
		minutes_counter = 59;
		hours_counter--;
	}
	if(hours_counter == 255){
		hours_counter = 23;
	}

	
}

void alarm(){
	seconds_counter++;
	wait_seconds--;
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
	
	if (alarm_seconds == seconds_counter && alarm_minutes == minutes_counter && alarm_hours == hours_counter ){
		alarm_flag = 1;
	}
	
	
}

void update_clock(uint8 source){
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
		
		
		if (source == 3){
			alarm_hours = (keypad_check-48)*10;
		}
		else{
			hours_counter= (keypad_check-48)*10;
		}
		
		do 
		{
			keypad_check = keypad_read();
			_delay_ms(200);
		} while (keypad_check == 0xff);
		lcd_send_char(keypad_check);
		
		if (source == 3){
			alarm_hours += keypad_check-48;
		}
		else{
			hours_counter += keypad_check-48;
		}
		
		
		
		
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
		
		if (source == 3){
			alarm_minutes = (keypad_check-48)*10;
		}
		else{
			minutes_counter= (keypad_check-48)*10;
		}
		
		do
		{
			keypad_check = keypad_read();
			_delay_ms(200);
		} while (keypad_check == 0xff);
		lcd_send_char(keypad_check);
		if (source == 3){
			alarm_minutes += keypad_check-48;
		}
		else{
			minutes_counter += keypad_check-48;
		}
		
		
		
		
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
		
		if (source == 3){
			alarm_seconds = (keypad_check-48)*10;
		}
		else{
			seconds_counter= (keypad_check-48)*10;
		}
		
		do
		{
			keypad_check = keypad_read();
			_delay_ms(200);
		} while (keypad_check == 0xff);
		lcd_send_char(keypad_check);
		
		if (source == 3){
			alarm_seconds += keypad_check-48;
		}
		else{
			seconds_counter += keypad_check-48;
		}
		
}