/*
 * File:   interrupt.c
 * Author: kareemaayman
 *
 * Created on September 1, 2024, 1:45 PM
 */


#include <xc.h>

// interrupt.c
#include "interrupt.h"
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint16_t pulse_count = 0;

void init_interrupts(void) {
    EICRA = (1 << ISC00); // Trigger on any logical change
    EIMSK = (1 << INT0);  // Enable external interrupt INT0
    sei(); // Enable global interrupts
}

ISR(INT0_vect) {
    pulse_count++; // Increment pulse count on interrupt
}

