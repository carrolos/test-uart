#include "rpi.h"

void notmain(void)
{
    u8 buf[256];
    u8* p = buf;
    uart_init();
    for (u32 i = 0; i < 3; i++)
    {
        while (1)
        {
            u8 c = uart_get8();
            if (c == '\r')
                break;
            else
                *p++ = c;
        }
        *p = '\0';
        p = buf;
        printk("%s\r\n", p);
    }
    clean_reboot();
}
