/*
 * File:   timer.c
 * Author: kareemaayman
 *
 * Created on September 1, 2024, 1:44 PM
 */


#include <xc.h>

// timer.c
#include "timer.h"
#include <avr/io.h>

void init_pwm(void) {
    // Set fast PWM mode on Timer1 with non-inverted output
    TCCR1A = (1 << COM1A1) | (1 << WGM11);
    TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11); // Prescaler of 8
    ICR1 = 19999; // Set TOP value for 20ms period (50Hz)
}

void set_pwm_duty_cycle(uint8_t duty_cycle) {
    OCR1A = (duty_cycle / 100.0) * ICR1; // Set PWM duty cycle
}

