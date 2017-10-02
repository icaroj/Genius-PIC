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
void interrupt ISR_Handler(void);

// Vars
struct Genius_t Genius;
unsigned char animacao = 0;

int main(void) {
    
    initOscillator();
    initInterrupts();
    initTimer0();
    initExtInt();
    initGPIO();   
    
    PORTBbits.RB1 = 1;
    PORTBbits.RB2 = 1;
    
    PORTAbits.RA0 = 1;
    PORTAbits.RA1 = 1;
    
    while(1);
    return 0;
}


void interrupt ISR_Handler(void) {
    if(INTCONbits.INTE && INTCONbits.INTF) {
        INTCONbits.INTF = 0;
        INTCONbits.INTE = 0;
        initGenius(&Genius);
    }
    
    if(INTCONbits.RBIE && INTCONbits.RBIF) {
        INTCONbits.RBIF = 0;
        switch(PORTB & 0xF0) {
            case 0xE0:
                setOneLed(3);
            break;
            case 0xD0:
                setOneLed(2);
            break;
            case 0xB0:
                setOneLed(1);
            break;
            case 0x70:
                setOneLed(0);
            break;
        }
    }
    
    if(PIR1bits.TMR1IF && PIE1bits.TMR1IE) {
        PIR1bits.TMR1IF = 0;
        TMR1 = PER_TMR1;
//        setOneLed(Genius.sequencia[Genius.passo_atual]);;
        Genius.passo_atual++;
    } 
}