/*	Author: ryan
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #8  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned short tmpA = 0x0000;
unsigned char tmpB = 0x00;


void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

const unsigned int MAX = 980;

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;	PORTA = 0xFF;
	DDRB = 0xFF;	PORTB = 0x00;
	DDRD = 0xFF;	PORTD = 0x00;
    /* Insert your solution below */

	ADC_init();
	tmpA = ADC;
    while (1) {
	tmpA = ADC;
	tmpB = 0;
	if(tmpA >= MAX/8){
		tmpB |= 0x01;
	}
	if(tmpA >= MAX/4){
		tmpB |= 0x02;
	}
	if(tmpA >= (3*MAX) / 8){
		tmpB |= 0x04;
	}
	if(tmpA >= MAX/2){
		tmpB |= 0x08;
	}
	if(tmpA >= (5*MAX) / 8){
		tmpB |= 0x10;
	}
	if(tmpA >= (6*MAX) / 8){
		tmpB |= 0x20;
	}
	if(tmpA >= (7*MAX) / 8){
		tmpB |= 0x40;
	}
	if(tmpA >= MAX){
		tmpB |= 0x80;
	}
	PORTB = tmpB;
    }
    return 1;
}
