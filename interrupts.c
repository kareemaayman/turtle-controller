/*
 * File:   interrupts.c
 * Author: kareemaayman
 *
 * Created on September 1, 2024, 1:45 PM
 */


#include <xc.h>

// interrupts.c
#include <avr/io.h>
#include <avr/interrupt.h>
#include "interrupts.h"

// Declare global variables
volatile uint16_t pulse_count = 0;         // To store the number of pulses detected
volatile uint8_t calculate_speed_flag = 0; // Flag to indicate when to calculate speed
volatile uint16_t rpm = 0;                 // To store the calculated RPM

#define PULSES_PER_REVOLUTION 100  // Replace 100 with your encoder's PPR

void INTERRUPTS_init(void) {
    // Configure INT0 for falling edge
    EICRA |= (1 << ISC01);  // Trigger on falling edge
    EIMSK |= (1 << INT0);   // Enable external interrupt INT0
    sei();  // Enable global interrupts
}

ISR(TIMER1_COMPA_vect) {
    rpm = (pulse_count * 60) / PULSES_PER_REVOLUTION;  // Convert pulse count to RPM
    pulse_count = 0;  // Reset pulse count for the next interval
    calculate_speed_flag = 1;  // Set flag to indicate that speed has been calculated
}

ISR(INT0_vect) {
    pulse_count++;  // Increment pulse count on each encoder pulse
}
