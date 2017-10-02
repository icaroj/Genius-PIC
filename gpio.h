/* 
 * File: GPIO File
 * Author: Icaro J.
 * Comments: Resposavel pelos pinos IO
 * Revision history: 0.1
 */

#ifndef GENIUS_GPIO
#define	GENIUS_GPIO 

// Defs
#define LED_CIMA PORTAbits.RA1
#define LED_DIREITA PORTAbits.RA0
#define LED_BAIXO PORTBbits.RB2
#define LED_ESQUERDA PORTBbits.RB1

#define BOTAO_CIMA PORTBbits.RB7
#define BOTAO_DIREITA PORTBbits.RB6
#define BOTAO_BAIXO PORTBbits.RB5
#define BOTAO_ESQUERDA PORTBbits.RB4

// Functions
void initGPIO(void);
void initExtInt(void);
void setOneLed(unsigned char led);

// Libs
#include <xc.h>

#endif	/* XC_HEADER_TEMPLATE_H */