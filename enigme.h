#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h> 
#include <SDL/SDL_mixer.h>

typedef struct 
{
	SDL_Surface *background[2];
	SDL_Surface *boutons[5];
	SDL_Surface *reponses[5];
	SDL_Surface *question;
	SDL_Surface *win;
	SDL_Surface *lost;
	
	SDL_Rect posRepones[5];
	SDL_Rect posQuestion;
	int choix_question;
	int image_courrante;
	int positionVraiReponse;
          
      
}Enigme;


void Init_Enigme(Enigme *e);
int Play_Enigme(Enigme *e,SDL_Surface *ecran,int *Game);
void Display_Enigme(Enigme *e,SDL_Surface *ecran);
int Verify_Enigme(Enigme *e,int *Game,SDL_Surface *ecran);
void Free_Enigme(Enigme *e);
#endif
