/*
 * File:   main.c
 * Author: kareemaayman
 *
 * Created on September 1, 2024, 1:50 PM
 */


#include <xc.h>

#include <avr/io.h>
#include "gpio.h"
#include "adc.h"
#include "timer.h"
#include "interrupts.h"
#include "spi.h"

int main(void) {
    // Initialize peripherals
    GPIO_init();
    ADC_init();
    TIMER_init();        // Timer0 for PWM
    TIMER1_init();       // Timer1 for RPM calculation
    INTERRUPTS_init();   // External interrupts for encoder
    SPI_init();          // SPI for communication
    
    while (1) {
        // Read potentiometer value
        uint16_t potValue = ADC_read(0);  // Read from ADC channel 0 (assuming potentiometer is connected to it)
        uint8_t pwmValue = potValue / 4;  // Scale to 8-bit value (assuming 10-bit ADC)
        
        // Set PWM value to control motor speed
        TIMER_setPWM(pwmValue);
      
        // Check if it's time to process a new RPM value
        if (calculate_speed_flag) {
            calculate_speed_flag = 0;  // Clear the flag
            SPI_send(rpm);  // Send the RPM value over SPI
            // You can also use the rpm value for further motor control logic
        }
    }
}