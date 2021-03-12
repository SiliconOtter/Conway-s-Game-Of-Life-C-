#ifndef Prototype
#define Prototype
 
#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <unistd.h>
#include <math.h>

#include <SDL/SDL.h>

#define TABLMAX 25

#define SIZE 100

/*MT*/

/* initializes mt[N] with a seed */
void init_genrand(unsigned long s);
void init_by_array(unsigned long init_key[], int key_length);

/* generates a random number on [0,0xffffffff]-interval */
unsigned long genrand_int32(void);

/* generates a random number on [0,0x7fffffff]-interval */
long genrand_int31(void);

/* generates a random number on [0,1]-real-interval */
double genrand_real1(void);

/* generates a random number on [0,1)-real-interval */
double genrand_real2(void);

/* generates a random number on (0,1)-real-interval */
double genrand_real3(void);

/* generates a random number on [0,1) with 53-bit resolution*/
double genrand_res53(void) ;


/* Mode Texte */

int **  _Origine();

void _Affichage(int ** tab);

int _VoisinsNbr(int ** tab,int xo,int yo);

void _Evolution(int ** tab);

void _CA_Texte(int temps);


/* Mode Graphique */

SDL_Surface * initialisation_sdl();

void _AffichageGrille(int ** tab,SDL_Surface * ecran);

void _CA_Graph(int temps);

void _CA_Graph_WithLuck(int temps);


#endif 
 
