#include "rpi.h"

void notmain(void)
{
    u32 pin = ACT_LED;
    gpio_as_output(pin);
    // show that GPIO works
    for (u32 i = 0; i < 7; i++)
    {
        gpio_set_off(pin);
        delay_us_raw(500000);
        gpio_set_on(pin);
        delay_us_raw(500000);
    }

    uart_init();
    while (1)
    {
         for (u32 i = 0; i < 7; i++)
        {
            gpio_set_off(pin);
            delay_us_raw(500000);
            gpio_set_on(pin);
            delay_us_raw(500000);
        }
   
        for (u32 i = 0; i < 100; i++)
            printk("hello world using printk\n");

        for (u32 i = 0; i < 7; i++)
        {
            gpio_set_off(pin);
            delay_us_raw(500000);
            gpio_set_on(pin);
            delay_us_raw(500000);
        }

    }
}
