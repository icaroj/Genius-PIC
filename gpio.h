/* 
 * File: GPIO File
 * Author: Icaro J.
 * Comments: Resposavel pelos pinos IO
 * Revision history: 0.1
 */

#ifndef GENIUS_GPIO
#define	GENIUS_GPIO 

// Functions
void initGPIO(void);
void setOneLed(unsigned char led);

// Libs
#include <xc.h>

#endif	/* XC_HEADER_TEMPLATE_H */