/*
 * File:   adc.c
 * Author: kareemaayman
 *
 * Created on September 1, 2024, 1:41 PM
 */


#include <xc.h>

// adc.c
#include <avr/io.h>
#include "adc.h"

void ADC_init(void) {
    // Initialize ADC
    ADMUX = (1 << REFS0);  // Reference voltage
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);  // Enable ADC and set prescaler
}

uint16_t ADC_read(uint8_t channel) {
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F); // Select ADC channel
    ADCSRA |= (1 << ADSC);  // Start conversion
    while (ADCSRA & (1 << ADSC)); // Wait for conversion to finish
    return ADC;
}
