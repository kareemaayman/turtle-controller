/*
 * File:   spi.c
 * Author: kareemaayman
 *
 * Created on September 1, 2024, 1:49 PM
 */


#include <xc.h>

// spi.c
#include <avr/io.h>
#include "spi.h"

void SPI_init(void) {
    // Set MOSI and SCK as output
    DDRB |= (1 << PB3) | (1 << PB5);
    SPCR |= (1 << SPE) | (1 << MSTR); // Enable SPI in Master mode
}

void SPI_send(uint16_t data) {
    SPDR = data; // Load data into the buffer
    while(!(SPSR & (1 << SPIF))); // Wait until transmission is complete
}