/** @ingroup Board
 * @{
 */
#ifndef BOARD_H_
#define BOARD_H_

/*******************| Inclusions |*************************************/
#include <PlatformTypes.h>
/** @todo to be removed when hal parts are moved to own file */
#include <ioCC2530.h>
   
/*******************| Macros |*****************************************/

/**
 * Frequency of the MCU in Hz
*/
#define BOARD_CPUFREQUENCY      32000000

/** 
 * Number of cpu cycles per nanoseconds. Thus, how many cycles does the
 * cpu do in one micro second.
*/
//#define BOARD_TICKSPERMICROSECOND        BOARD_CPUFREQUENCY/1000000
#define BOARD_TICKSPERMICROSECOND        20

/** 
* LED connected to P1_0
*/
#define ledInit()       P1DIR_0 = Px_PINOUTPUT;
#define ledOn()         P1_0 = Px_LOW;
#define ledOff()        P1_0 = Px_HIGH;
   
/*******************| Type definitions |*******************************/

/*******************| Global variables |*******************************/

/*******************| Function prototypes |****************************/
void Board_init();
void delay_us(uint16_t usec);
void delay_ms(uint16_t usec);

#endif

/** @}*/
