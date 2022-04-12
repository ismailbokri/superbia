#include <SDL/SDL_image.h>
//#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
 

typedef struct
{
	SDL_Surface *imgEnemy; //sprite cheet
	//Mix_Chunk *son; //son bref dans l'ataque
	SDL_Rect posEN,posSprit; //posen = position dans l'ecran / possprit = la position du l'image 
	int direct; //direction
	
}es;

/*typedef struct
{
	SDL_Surface *img; //background
	SDL_Rect pos; //position
}background;*/

void initenemy(es *e);
void afficherenemy(es e,SDL_Surface *screen);
void animerenemy(es *e);
void deplacer(es *e);
int collisionBox(SDL_Rect a, SDL_Rect b);
//void deplacerAI(es *e,SDL_Rect posper);
