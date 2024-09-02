/*
 * File:   adc.c
 * Author: kareemaayman
 *
 * Created on September 1, 2024, 1:41 PM
 */


#include <xc.h>

// adc.c

#include "adc.h"
#include <avr/io.h>

void init_adc(void) {
    // Set ADC prescaler and enable ADC
    ADMUX = (1 << REFS0); // Reference voltage on AVCC
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1); // ADC Enable and prescaler of 64
}

uint16_t read_adc(uint8_t channel) {
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F); // Select ADC channel
    ADCSRA |= (1 << ADSC); // Start conversion
    while(ADCSRA & (1 << ADSC)); // Wait for conversion to complete
    return ADC;
}
