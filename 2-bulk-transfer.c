#include "rpi.h"

void notmain(void)
{
    uart_init();
    uart_flush_tx();
    for (u32 i = 0; i < 4000000; i++)
        printk("%u\n", i);
    clean_reboot();
}
