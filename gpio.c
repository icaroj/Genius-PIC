/*
 * File:   gpio.c
 * Author: jonas
 *
 * Created on 1 de Outubro de 2017, 11:53
 */


#include "gpio.h"


void initGPIO(void) { 
    TRISAbits.TRISA0 = 0;   // TOPO
    TRISAbits.TRISA1 = 0;   // DIREITA
    CMCON = 0x07;           // IO pins
    TRISBbits.TRISB1 = 0;   // ESQUERDA
    TRISBbits.TRISB2 = 0;   // BAIXO
}

void setOneLed(unsigned char led) { 
    switch(led) { 
        case 0:
            PORTAbits.RA0 = 1;
            PORTAbits.RA1 = 0;
            PORTBbits.RB1 = 0;
            PORTBbits.RB2 = 0;
        break;
        
        case 1:
            PORTAbits.RA0 = 0;
            PORTAbits.RA1 = 1;
            PORTBbits.RB1 = 0;
            PORTBbits.RB2 = 0;
            
        break;

        case 2:
            PORTAbits.RA0 = 0;
            PORTAbits.RA1 = 0;
            PORTBbits.RB1 = 1;
            PORTBbits.RB2 = 0;
        break;
        
        case 3:
            PORTAbits.RA0 = 0;
            PORTAbits.RA1 = 0;
            PORTBbits.RB1 = 0;
            PORTBbits.RB2 = 1;
        break;
    }
}