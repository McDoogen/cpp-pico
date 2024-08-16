#include <stdio.h>
#include "pico/stdlib.h"



int main() {
    stdio_init_all();

    // Turn Power LED On
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    gpio_put(PICO_DEFAULT_LED_PIN, true);

    while (true) {
        sleep_ms(1000);
        gpio_put(PICO_DEFAULT_LED_PIN, false);
        sleep_ms(1000);
        gpio_put(PICO_DEFAULT_LED_PIN, true);
    }
}