/*
 * File:   timer.c
 * Author: jonas
 *
 * Created on 1 de Outubro de 2017, 12:31
 */


#include "timer.h"

void initTimer0(void) {
    OPTION_REGbits.T0CS = 0;    // Ft0 = Fosc/4
    OPTION_REGbits.PSA = 0;     // Prescaler WDT -> Timer0
    OPTION_REGbits.PS = 0b111;  // 1:256
    TMR0 = TMR0_PER;            // 0xFF - PER 
    INTCONbits.T0IF = 0;
    INTCONbits.T0IE = 1;
    
}