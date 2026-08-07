#include "rpi.h"

void notmain(void)
{
    u32 delay = 1000000;
    u32 pin = ACT_LED;
    gpio_as_output(pin);
    // show that GPIO works
    for (u32 i = 0; i < 7; i++)
    {
        gpio_set_off(pin);
        delay_us_raw(delay);
        gpio_set_on(pin);
        delay_us_raw(delay);
    }

    // leave on to show made it this far
    gpio_set_off(pin);
    uart_init();
    // turn off to show done with uart_init
    gpio_set_on(pin);
    while (1)
    {
         for (u32 i = 0; i < 2; i++)
        {
            gpio_set_off(pin);
            delay_us_raw(delay);
            gpio_set_on(pin);
            delay_us_raw(delay);
        }
   
        for (u32 i = 0; i < 100; i++)
            printk("hello world using printk\n");

        for (u32 i = 0; i < 4; i++)
        {
            gpio_set_off(pin);
            delay_us_raw(delay);
            gpio_set_on(pin);
            delay_us_raw(delay);
        }

    }
}
