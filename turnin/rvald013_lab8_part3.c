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

const unsigned int MAX = 1696;

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
	if(tmpA >= MAX/2){
		tmpB = 0x01;
	}
	else{
		tmpB = 0x00;
	}
	PORTB = tmpB;
    }
    return 1;
}
