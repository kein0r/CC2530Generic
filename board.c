#include "board.h"

/**
 * One clock cycle is 0.03125uS. Thus we need 32 cycles for on uS
**/
void delayUS(uint16 usec)
{
    
    while(usec--)
    {
        nop();nop();nop();nop();nop();nop();nop();nop();nop();nop();
        nop();nop();nop();nop();nop();nop();nop();nop();nop();nop();
        nop();nop();nop();nop();nop();nop();nop();nop();nop();nop();
        nop();nop();
    }
}