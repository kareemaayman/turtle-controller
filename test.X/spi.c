/*
 * File:   spi.c
 * Author: kareemaayman
 *
 * Created on September 1, 2024, 1:49 PM
 */


#include <xc.h>

// spi.c
#include "spi.h"
#include <avr/io.h>

void init_spi(void) {
    // Set MOSI and SCK as output, all others as input
    DDRB = (1 << PB3) | (1 << PB5);
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0); // Enable SPI, Master, set clock rate fck/16
}

void spi_transmit(uint8_t data) {
    SPDR = data; // Start transmission
    while(!(SPSR & (1 << SPIF))); // Wait for transmission to complete
}

