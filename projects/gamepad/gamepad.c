/*
    How to read the seesaw: https://learn.adafruit.com/adafruit-seesaw-atsamd09-breakout/reading-and-writing-data
*/

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

int main() {
    stdio_init_all();
    
    // This example will use I2C0 on the default SDA and SCL pins (GP4, GP5 on a Pico)
    i2c_init(i2c_default, 100 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);
    // Make the I2C pins available to picotool
    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));

    int addr = 0x50;
    // Perform a 1-byte dummy read from the probe address. If a slave
    // acknowledges this address, the function returns the number of bytes
    // transferred. If the address byte is ignored, the function returns
    // -1.

    // Skip over any reserved addresses.
    int ret;
    uint8_t rxdata[4];
    uint8_t txdata[2] = {0x01, 0x04};
    while(true) {
        ret = i2c_write_blocking(i2c_default, addr, txdata, 2, true);
        printf("Write Return: %d\n", ret);

        // sleep_ms(250);
        sleep_us(250);

        ret = i2c_read_blocking(i2c_default, addr, rxdata, 4, false);
        printf("Read Return: %d\n", ret);
        printf("Data: %d %d %d %d\n", rxdata[0], rxdata[1], rxdata[2], rxdata[3]);
        sleep_ms(500);
    }
}