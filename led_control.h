#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Turns the LED on or off based on 'enable'
void enable_led(bool enable);

// Current LED intensity (0-255)
extern int led_duty;

// True if streaming is active, false otherwise
extern bool isStreaming;

#ifdef __cplusplus
}
#endif

#endif // LED_CONTROL_H
