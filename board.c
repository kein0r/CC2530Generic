#include "board.h"

void Board_init()
{
  /* wait some time for the osc to stabilize */
  for (i=0; i<504; i++) nop();
  /* enable external OSC */
  CLKCONCMD = (CLKCONCMD_OSC32K_XOSC | CLKCONCMD_OSC_XOSC);
  /* wait until both clocks has stabilized */
  while (CLKCONSTA != CLKCONCMD) ;
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
        nop();nop();nop();nop();nop();nop();nop();nop();nop();nop();
        nop();nop();
    }
}
