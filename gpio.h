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
#define BOTAO_CIMA 7        
#define BOTAO_DIREITA 6    
#define BOTAO_BAIXO 5       
#define BOTAO_ESQUERDA 4   

// Defs 
#define BOTAO_PORT_PTR &BOTAO_PORT
#define BOTAO_MASK ( 1 << BOTAO_CIMA | 1 << BOTAO_DIREITA | 1 << BOTAO_BAIXO | 1 << BOTAO_ESQUERDA)
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