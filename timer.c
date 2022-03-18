#include "timer.h"

#include <avr/io.h>

void timer_init() {
    // Fast PWM-mod, 0xFF som TOP. Table 19-4.
    TCCR0A &= ~(1 << COM0A0);  // 19-17.
    TCCR0A |= (1 << COM0A1);

    TCCR0A |= (1 << WGM00);   // WGM00 -> 1
    TCCR0A |= (1 << WGM01);   // WGM01 -> 1
    TCCR0B &= ~(1 << WGM02);  // WGM02 -> 0
    // Prescaler = 64 Table 15-9.
    TCCR0B |= (1 << CS00);   // CS00 -> 1
    TCCR0B |= (1 << CS01);   // CS01 -> 1
    TCCR0B &= ~(1 << CS02);  // CS02 -> 0
}
void timer2() {
    // CTC table 22-9.
    TCCR2A |= (1 << WGM20);   // -> 0
    TCCR2A |= (1 << WGM21);   // -> 1
    TCCR2B &= ~(1 << WGM22);  // -> 0
    // Prescaler = 1024 Table 22-10
    TCCR2B |= (1 << CS20);  // CS00 -> 1
    TCCR2B |= (1 << CS21);  // CS01 -> 1
    TCCR2B |= (1 << CS22);  // CS02 -> 1
}