/* 
 * File: GPIO File
 * Author: Icaro J.
 * Comments: Resposavel pelos pinos IO
 * Revision history: 0.1
 */

#ifndef GENIUS_GPIO
#define	GENIUS_GPIO 


// Config
#define LED_CIMA PORTAbits.RA1
#define LED_DIREITA PORTAbits.RA0
#define LED_BAIXO PORTBbits.RB2
#define LED_ESQUERDA PORTBbits.RB1

#define BOTAO_PORT PORTB
#define BOTAO_CIMA 1 << 7       // 1 << PINO     
#define BOTAO_DIREITA 1 << 6    // 1 << PINO  
#define BOTAO_BAIXO 1 << 5      // 1 << PINO 
#define BOTAO_ESQUERDA 1 << 4   // 1 << PINO 

// Defs 
#define BOTAO_PORT_PTR &BOTAO_PORT
#define BOTAO_MASK ( BOTAO_CIMA | BOTAO_DIREITA | BOTAO_BAIXO | BOTAO_ESQUERDA)
#define TODOS 0xFF
#define NENHUM 0xFE

// Functions
void initGPIO(void);
void initExtInt(void);
void setLed(unsigned char led);
void buttonOnRisingEdge(int *port, unsigned char mask);

// Libs
#include <xc.h>

#endif	/* XC_HEADER_TEMPLATE_H */