// Deluppgift 3, för att kompilera -> skriv make i terminalen. (fade_led)
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <util/delay.h>

#include "led.h"
#include "timer.h"

int main(void) {
    timer_init();
    timer2();
    led_out();

    while (1) {
        // Wait to OCF2A flag to be set (timer2)
        while ((TIFR2 & (1 << OCF2A)) > 0) {
            OCR0A = simple_ramp();  // Set new duty cycle for OCR0A (timer_init)
            TIFR2 |= (1 << OCF2A);  // Clear the flag for next round (timer2)
        }
    }
    return 0;
}
