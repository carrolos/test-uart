#include "rpi.h"
// waits until special symbol is received to countdown
// and blast off! (blink)

void notmain(void)
{
    u32 pin = ACT_LED;
    gpio_as_output(pin);

    // internally calls a dsb()
    uart_init();
    u8 special = '!';
    u8 c;
    while ((c = uart_get8()) != special)
        printk("%c is not what we need, try again\r\n", c);

    for (i8 i = 10; i >0; i--)
        printk("%c\r\n%d\r\n", c, i);

    putk("blast off!\r\n");

    for (i8 i = 0; i < 10; i++)
    {
        gpio_set_off(pin);
        delay_us_raw(500000);
        gpio_set_on(pin);
        delay_us_raw(500000);
    }
    clean_reboot();
}
