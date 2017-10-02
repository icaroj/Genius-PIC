/*
 * File:   timer.c
 * Author: jonas
 *
 * Created on 1 de Outubro de 2017, 12:31
 */


#include <pic16f628a.h>

#include "timer.h"

//// seed for the pseudorandom number gen
void initTimer0(void) {
    OPTION_REGbits.T0CS = 0;    // Ft0 = Fosc/4
    TMR0 = 0;         
    
}

void initTimer1(void) {
    T1CONbits.T1CKPS = 0b111; // 1:8
    TMR1 = PER_TMR1; // 0xFFFF - PER
    PIR1bits.TMR1IF = 0;
    PIE1bits.TMR1IE = 1;
    T1CONbits.TMR1ON = 1;
}