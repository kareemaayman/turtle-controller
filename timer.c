/*
 * File:   timer.c
 * Author: kareemaayman
 *
 * Created on September 1, 2024, 1:44 PM
 */


#include <xc.h>

// timer.c
#include <avr/io.h>
#include "timer.h"

void TIMER_init(void) {
    // Configure Timer/Counter for Fast PWM mode
    TCCR0A |= (1 << WGM00) | (1 << WGM01);
    TCCR0A |= (1 << COM0A1); // Clear OC0A on Compare Match
    TCCR0B |= (1 << CS01) | (1 << CS00); // Prescaler 64
    DDRD |= (1 << PD6); // Set OC0A as output
}
void TIMER1_init(void){
    // Configure Timer1 for CTC mode
    TCCR1B |= (1 << WGM12);  // CTC mode
    TCCR1B |= (1 << CS11) | (1 << CS10); // Prescaler 64
    OCR1A = 12500 - 1; // Set compare value for 1-second interval assuming 8 MHz clock
    TIMSK1 |= (1 << OCIE1A); // Enable Timer1 compare interrupt
}

void TIMER_setPWM(uint8_t dutyCycle) {
    OCR0A = dutyCycle; // Set duty cycle
}
