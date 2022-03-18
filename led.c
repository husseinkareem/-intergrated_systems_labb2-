#include "led.h"

#include <avr/io.h>
#include <util/delay.h>

void led_out() {
    DDRB &= ~(1 << PB1);
    DDRD |= (1 << PD6);  // Set PD6 as output
}
int8_t dir = 1;
uint8_t pwm_Value = 0;

int simple_ramp() {
    pwm_Value += dir;
    if (pwm_Value == 255) {
        dir = -1;  // Count down
    }
    if (pwm_Value == 0) {
        dir = 1;  // Count up
    }
    return pwm_Value;
}