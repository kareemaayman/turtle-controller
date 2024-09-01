/*
 * File:   gpio.c
 * Author: kareemaayman
 *
 * Created on September 1, 2024, 1:39 PM
 */


#include <xc.h>

// gpio.c
#include <avr/io.h>
#include "gpio.h"

void GPIO_init(void) {
    // Configure motor control pins as output
    DDRD |= (1 << PD2) | (1 << PD3); // Example for Motor Direction Control
    // Configure encoder and potentiometer pins as input
    DDRC &= ~(1 << PC0); // Example for Potentiometer
}
