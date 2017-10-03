/*
 * File:   genius.c
 * Author: jonas
 *
 * Created on 1 de Outubro de 2017, 12:15
 */
#include <stdio.h>
#include <stdlib.h>
#include "gpio.h"
#include "timer.h"
#include "genius.h"


void initGenius(struct Genius_t *Genius) {
    setLed(NENHUM);
    initRandomSequence(Genius); 
    initTimer1();
    Genius->level = 0;
    Genius->passo = 0;
    Genius->teclado = 0;
}


void initRandomSequence(struct Genius_t *Genius) {
    unsigned char i;
    srand(TMR0);
    for(i = 0; i < MAX_SEQ; i++) {
        Genius->sequencia[i] = rand() % QNT_ESTADOS;
    }
}


void initOscillator(void) { 
    PCONbits.OSCF = 0; // 37 kHz mode
}


void initInterrupts(void) {
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
}