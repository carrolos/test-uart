#include "rpi.h"

void notmain(void)
{
    uart_init();
    uart_flush_tx();
    while (1)
    {
        // test binary
        for (u8 i = 0; i <= 15; i++)
        {
            printk("i_b=<%b>", i);    
        }
        // test u32
        for (u32 i = 0; i <= 15; i++)
        {
            printk("i_u=<%u>", i);    
        }
        // test hex
        for (u32 i = 0; i <= 15; i++)
        {
            printk("i_x=<%x>", i);    
        }
        // test negatives
        for (i32 i = 0; i >= -15; i--)
        {
            printk("i_d=<%d>", i);    
        }
        // test string
        printk("%s, %s", "hello", "world");    

        dsb();
        delay_us_raw(500000);
    }
}
