#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "perso.h"

typedef struct
{
	SDL_Surface *img; //sprite cheet
	Mix_Chunk *son; //son bref dans l'ataque
	SDL_Rect posaff,posimg; //pos aff = position dans l'ecran / pos img = la position du l'image 
	int direct; //direction
	
}es;

void initenemy(es *e);
void afficherenemy(es e,SDL_Surface *screen);
void animerenemy(es *e);
void deplacer(es *e);
int collusion(personne p,es e);
void deplacerAI(es *e,SDL_Rect posper);
