/*
 * File:   gpio.c
 * Author: jonas
 *
 * Created on 1 de Outubro de 2017, 11:53
 */


#include "gpio.h"


void initGPIO(void) { 
    // LEDs
    CMCON = 0x07;           // IO pins
    TRISAbits.TRISA0 = 0;   // TOPO
    TRISAbits.TRISA1 = 0;   // DIREITA
    TRISBbits.TRISB1 = 0;   // ESQUERDA
    TRISBbits.TRISB2 = 0;   // BAIXO
    
    // Botoes
    OPTION_REGbits.nRBPU = 0; // Pull-ups on
    TRISBbits.TRISB7 = 1;
    TRISBbits.TRISB6 = 1;
    TRISBbits.TRISB5 = 1;
    TRISBbits.TRISB4 = 1;
    // RB4:RB7 on-change interrupt
    INTCONbits.RBIE = 0;
}


void initExtInt(void) {
    TRISBbits.TRISB0 = 1; // input
    INTCONbits.INTF = 0;
    INTCONbits.INTE = 1;
    OPTION_REGbits.INTEDG = 0; // fallin
}



void setLed(char led) { 
    switch(led) { 
        case 0:
            LED_CIMA = 1;
            LED_DIREITA = 0;
            LED_BAIXO = 0;
            LED_ESQUERDA = 0;
        break;
        
        case 1:
            LED_CIMA = 0;
            LED_DIREITA = 1;
            LED_BAIXO = 0;
            LED_ESQUERDA = 0;
            
        break;

        case 2:
            LED_CIMA = 0;
            LED_DIREITA = 0;
            LED_BAIXO = 1;
            LED_ESQUERDA = 0;
        break;
        
        case 3:
            LED_CIMA = 0;
            LED_DIREITA = 0;
            LED_BAIXO = 0;
            LED_ESQUERDA = 1;
        break;
        
        case TODOS:
            LED_CIMA = 1;
            LED_DIREITA = 1;
            LED_BAIXO = 1;
            LED_ESQUERDA = 1;
        break;
        
        case NENHUM:
            LED_CIMA = 0;
            LED_DIREITA = 0;
            LED_BAIXO = 0;
            LED_ESQUERDA = 0;
        break;
            
    }
}

void buttonOnRisingEdge(int *port, unsigned char mask) {
    unsigned char i;
    for(i = 0; i < 255; i++); // delay para debouncing...
    for(i = 0; i < 8; i++) 
        if(mask == (1 << i)) break;
    while(!((*port >> i) & 0x01));
}