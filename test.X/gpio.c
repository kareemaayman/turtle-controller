/*
 * File:   gpio.c
 * Author: kareemaayman
 *
 * Created on September 1, 2024, 1:39 PM
 */


#include <xc.h>

#include "gpio.h"
#include <avr/io.h>

void init_gpio(void) {
    // Set up motor control pins as output
    DDRD |= (1 << PD0);  // Direction for Motor 1 (IN1)
    DDRD |= (1 << PD1);  // Direction for Motor 1 (IN2)
    DDRB |= (1 << PB1);  // PWM for Motor 1 (ENA)
}

