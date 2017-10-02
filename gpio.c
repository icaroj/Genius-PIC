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
    INTCONbits.RBIF = 0;
    INTCONbits.RBIE = 1;
}


void initExtInt(void) {
    TRISBbits.TRISB0 = 1; // input
    INTCONbits.INTF = 0;
    INTCONbits.INTE = 1;
    OPTION_REGbits.INTEDG = 0; // fallin
}



void setOneLed(char led) { 
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
    }
}