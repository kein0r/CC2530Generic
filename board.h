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


/** @todo Move to hal.h */
/* 
 * Direction of port pins
*/
#define HAL_PINOUTPUT   (uint8_t)1
#define HAL_PININPUT    (uint8_t)0

/** 
 * Logic level of pins
*/
#define HAL_HIGH        (uint8_t)1
#define HAL_LOW         (uint8_t)0

/** 
* LED connected to P1_0
*/
#define ledInit()       P1DIR_0 = HAL_PINOUTPUT;
#define ledOn()         P1_0 = HAL_LOW;
#define ledOff()        P1_0 = HAL_HIGH;

/** 
 * Macros for enabling/disabling all or one particular interrupt
*/
#define IEN0_EA         0x80
#define enableInterrupt(reg, bit) reg |= bit
#define disableInterrupt(reg, bit) reg &= ~bit
#define enableAllInterrupt() enableInterrupt(IEN0, IEN0_EA)
#define disableAllInterrupt() disableInterrupt(IEN0, IEN0_EA)

/**
 * Macro to clear interrupt flag. See swru191c.pdf Chapter 2.5.1 why interrupt 
 * flags are cleared as follows.
*/
#define clearInterruptFlag(reg, bit) reg = ~bit

/**
* For easier access of the direction bits
*/
/* Port 0                                                                           */
SFRBIT( P0DIRbits      ,  0xFD, P0DIR_7, P0DIR_6, P0DIR_5, P0DIR_4, P0DIR_3, P0DIR_2, P0DIR_1, P0DIR_0 )
/* Port 1                                                                           */
SFRBIT( P1DIRbits      ,  0xFE, P1DIR_7, P1DIR_6, P1DIR_5, P1DIR_4, P1DIR_3, P1DIR_2, P1DIR_1, P1DIR_0 )
   
/*******************| Type definitions |*******************************/

/*******************| Global variables |*******************************/

/*******************| Function prototypes |****************************/
void Board_init();
void delay_us(uint16_t usec);
void delay_ms(uint16_t usec);

#endif

/** @}*/
