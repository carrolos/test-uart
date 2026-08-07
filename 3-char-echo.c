#include "rpi.h"

void notmain(void)
{
    uart_init();
    uart_flush_tx();
    for (u32 i = 0; i < 10; i++)
    {
        printk("you typed: %c ", uart_get8());
    }
    clean_reboot();
}
