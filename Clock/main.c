/*
 * Clock.c
 *
 * Created: 02.11.2017 18:55:09
 * Author : dubos
 */ 

#define F_CPU 16000000UL

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "lcd.h"

int hours = 0;
int min = 0;
int sec = 0;
int seg1 = 0;
int seg2 = 0;
int seg3 = 0;
int seg4 = 0;
int seg = 0;
int blink = 1;
char set = 0;
char dd = 0;

//Timer interrupt
ISR(TIMER1_COMPA_vect) {
	if(set == 0) {
		if(blink == 1) {
			if(dd == 0) { PORTD |= (1<<PD7); dd = 1; }
			else { PORTD &=~ (1<<PD7); dd = 0; }
		}
		if(sec<59) {
			sec++;
		}
		else {
			sec = 0;
			if(min<59) {
				min++;
			}
			else {
				min = 0;
				if(hours<23) {
					hours++;
				}
				else {
					hours = 0;
				}
				seg1 = div(hours, 10).quot;
				seg2 = div(hours, 10).rem;
			}
			seg3 = div(min, 10).quot;
			seg4 = div(min, 10).rem;
		}
		TCNT1 = 0;
	}
}

//Button interrupt
ISR(INT1_vect) {
	GICR &=~ (1<<INT1);
	
	if(PIND & (1<<PD4)) {
		if(set == 0) {
			set = 1;
			seg = 1;
			PORTD |= (1<<PD7);
			lcdwriteint(0, 8, '1');
			_delay_ms(500);
		}
		else {
			if(seg < 3) {
				seg=seg+1;
			}
			else {
				seg = 1;
			}
		}
	}
	else if(set == 1) {
		if(seg == 1) {
			if(hours<23) {
				hours = hours + 1;
			}
			else {
				hours = 0;
			}
			seg1 = div(hours, 10).quot;
			seg2 = div(hours, 10).rem;
		}
		if(seg == 2) {
			if(min<59) {
				min++;
			}
			else {
				min = 0;
			}
			seg3 = div(min, 10).quot;
			seg4 = div(min, 10).rem;
		}
		if(seg == 3) {
			set = 0;
			seg = 1;
			PORTD &=~ (1<<PD7);
		}
		_delay_ms(10);
	}
	else {
		if(blink == 0) {
			blink = 1;
		}
		else {
			blink = 0;
		}
	}
	
	_delay_ms(50);
	GIFR &=~ (1<<INTF0);
	GICR |= (1<<INT1);
};

int main(void)
{
	DDRB |= (1<<PB2)|(1<<PB4)|(1<<PB5);
	DDRC |= (1<<PC0)|(1<<PC1)|(1<<PC2)|(1<<PC3)|(1<<PC4)|(1<<PC5);
	DDRD |= (1<<PD0)|(1<<PD1)|(1<<PD2)|(1<<PD7);
	
	//Button interrupt
	MCUCR = (1<<ISC11)|(1<<ISC10);
	GICR = (1<<INT1);
	GIFR = (1<<INTF1);
	
	//Timer setup
	TCCR1A = 0;
	TCCR1B |= (1<<CS12);
	//OCR1A = 15625;
	OCR1A = 62498;
	//OCR1A = 10000;
	TCNT1 = 0;
	TIMSK = 0b00010000;
		
	LEDDP();
	
	sei();
			
    while (1) 
    {
		while(set == 1) {
			LEDDD();
			if(seg == 1) {				
				lcdwriteint(1, seg1, '1');
				_delay_ms(1);
				lcdwriteint(2, seg2, '1');
				_delay_ms(1);
				lcdwriteint(3, seg3, '0');
				_delay_ms(1);
				lcdwriteint(4, seg4, '0');
				_delay_ms(1);
			}
			if(seg == 2) {
				lcdwriteint(1, seg1, '0');
				_delay_ms(1);
				lcdwriteint(2, seg2, '0');
				_delay_ms(1);
				lcdwriteint(3, seg3, '1');
				_delay_ms(1);
				lcdwriteint(4, seg4, '1');
				_delay_ms(1);
			}
			if(seg == 3) {
				set = 0;
				seg = 1;
				PORTD &=~ (1<<PD7);
			}
		}
		lcdwriteint(1, seg1, '0');
		_delay_ms(1);
		lcdwriteint(2, seg2, '0');
		_delay_ms(1);
		lcdwriteint(3, seg3, '0');
		_delay_ms(1);
		lcdwriteint(4, seg4, '0');
		_delay_ms(1);
	}
}

