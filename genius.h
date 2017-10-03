/* 
 * File: Genius File
 * Author: Icaro J.
 * Comments: Logica geral do jogo
 * Revision history: 0.1
 */

/*
 * CIMA, DIREITA, BAIXO, ESQUERDA: 0, 1, 2, 3.
 */
#ifndef GENIUS
#define	GENIUS

// Defines
#define MAX_SEQ    64   // Tamanho do vetor que armazena a sequencia do jogo
#define QNT_ESTADOS 4   // Apenas 4 botoes/leds


// Functions
void initGenius(struct Genius_t *Genius);
void initRandomSequence(struct Genius_t *Genius);
void initOscillator(void);
void initInterrupts(void);

// Vars
struct Genius_t { 
    unsigned char sequencia[MAX_SEQ];
    unsigned char teclado;
    unsigned char level;
    unsigned char passo;
};

// Libs
#include <xc.h>

#endif	/* XC_HEADER_TEMPLATE_H */