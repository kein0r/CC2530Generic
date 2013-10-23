/** @ingroup Board
 * @{
 */
#ifndef BOARD_H_
#define BOARD_H_

/*******************| Inclusions |*************************************/
#include <PlatformTypes.h>
   
/*******************| Macros |*****************************************/
#define nop()  asm("NOP")

/*
 * Frequency of the MCU in Hz
*/
#define BOARD_CPUFREQUENCY      32000000

/* 
 * Number of cpu cycles per nanoseconds. Thus, how many cycles does the
 * cpu do in one micro second.
*/
#define BOARD_TICKSPERMICROSECOND        BOARD_CPUFREQUENCY/1000000
   
/*******************| Type definitions |*******************************/

/*******************| Global variables |*******************************/

/*******************| Function prototypes |****************************/
void delay_us(uint16 usec);

#endif

/** @}*/
