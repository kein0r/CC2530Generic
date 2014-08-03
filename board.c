#include "board.h"
#include <CC253x.h>

void Board_init()
{
  /* wait some time for the osc to stabilize */
  for (int i=0; i<504; i++) nop();
  /* Init MCU, external 32MHz and 32KHz oscilator, 32MHz counter tick speed, clock speed 32MHz */
  CC253x_Init(CLKCONCMD_OSC_XOSC | CLKCONCMD_OSC32K_XOSC | CLKCONCMD_TICKSPD_32MHZ | CLKCONCMD_CLKSPD_32MHz);
}

/**
 * One clock cycle is 0.03125uS. Thus we need 32 cycles for on uS
**/
void delay_us(uint16 usec)
{
    
    while(usec--)
    {
        nop();nop();nop();nop();nop();nop();nop();nop();nop();nop();
        nop();nop();nop();nop();nop();nop();nop();nop();nop();nop();
        /* nop();nop();nop();nop();nop();nop();nop();nop();nop();nop();
        nop();nop();*/
    }
}

void delay_ms(uint16 usec)
{
    
    while(usec--)
    {
      delay_us(1000);
    }
}