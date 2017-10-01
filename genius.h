/* 
 * File: Genius File
 * Author: Icaro J.
 * Comments: Logica geral do jogo
 * Revision history: 0.1
 */

#ifndef GENIUS
#define	GENIUS

// Defines
#define MAX_SEQ    64   // Tamanho do vetor que armazena a sequencia do jogo
#define QNT_ESTADOS 4   // Apenas 4 botoes/leds


// Functions
void initGenius(struct Genius_t *Genius);
static void initRandomSequence(struct Genius_t *Genius);
static void initOscillator(void);
static void initInterrupts(void);

// Vars
struct Genius_t { 
    unsigned char sequencia[MAX_SEQ];
    unsigned char passo_atual;
};

// Libs
#include <xc.h>

#endif	/* XC_HEADER_TEMPLATE_H */