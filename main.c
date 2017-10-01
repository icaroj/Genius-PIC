/*
 * File:   main.c
 * Author: jonas
 *
 * Created on 1 de Outubro de 2017, 10:37
 */


#include "config.h"
#include "gpio.h"
#include "timer.h"
#include "genius.h"

// Func
void interrupt tc_int(void);

// Vars
struct Genius_t Genius;


int main(void) {
    
    
    initGenius(&Genius);
    
    PORTBbits.RB1 = 1;
    PORTBbits.RB2 = 1;
    
    PORTAbits.RA0 = 1;
    PORTAbits.RA1 = 1;
    
    while(1);
    return 0;
}


void interrupt tc_int(void) {
    if(INTCONbits.T0IF && INTCONbits.T0IE) {
        INTCONbits.T0IF = 0;
        TMR0 = TMR0_PER;
        setOneLed(Genius.sequencia[Genius.passo_atual]);
        Genius.passo_atual++;
    } 
}