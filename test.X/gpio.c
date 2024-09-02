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
    DDRB |= (1 << PB1); // Example: Setting PB1 as output for PWM
}


