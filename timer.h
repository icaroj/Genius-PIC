/* 
 * File: Timer File
 * Author: Icaro J.
 * Comments: Resposavel pelo controle de tempo
 * Revision history: 0.1
 */

#ifndef GENIUS_TIMER
#define	GENIUS_TIMER

// Defs
#define PER_TMR1 63223    // ~ 2 seg @37kHz

// Functions
void initTimer0(void);
void initTimer1(void);

// Libs
#include <xc.h>

#endif	/* XC_HEADER_TEMPLATE_H */