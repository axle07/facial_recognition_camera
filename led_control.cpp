#include "led_control.h"
#include "esp32-hal-ledc.h"
#include "sdkconfig.h"
#include "esp_log.h"

#define CONFIG_LED_MAX_INTENSITY 255
#define LED_LEDC_GPIO 22

int led_duty = 0;
bool isStreaming = false;

// Turns the LED on or off based on 'enable'
void enable_led(bool enable) {
    int duty = enable ? led_duty : 0;
    if (enable && isStreaming && (led_duty > CONFIG_LED_MAX_INTENSITY)) {
        duty = CONFIG_LED_MAX_INTENSITY;
    }
    ledcWrite(LED_LEDC_GPIO, duty);
    ESP_LOGI("LED", "Set LED intensity to %d", duty);
}
