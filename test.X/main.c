/*
 * File:   main.c
 * Author: kareemaayman
 *
 * Created on September 1, 2024, 1:50 PM
 */


#include <xc.h>

#include <stdint.h> 
#include "gpio.h"
#include "adc.h"
#include "timer.h"
#include "interrupt.h"
#include "spi.h"
#include "motor.h"

int main(void) {
    init_gpio();
    init_adc();
    init_pwm();
    init_interrupts();
    init_spi();

    while (1) {
        uint16_t adc_value = read_adc(0); // Read potentiometer
        uint8_t speed = (adc_value / 1023.0) * 100; // Convert to percentage
        set_pwm_duty_cycle(speed); // Control motor speed

        // Assume RPM calculation based on pulse_count is done here
        uint8_t rpm = calculate_rpm(); // Pseudo function
        spi_transmit(rpm); // Send RPM via SPI
    }
}


