#ifndef Text_H
#define Text_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include "background.h"
#define SCREEN_H 1000
#define SCREEN_W 720

/*typedef struct{
	SDL_Rect pos ;
	SDL_Surface *img ;
}image;*/


typedef struct  personnage
{
	int vie;
	float vitesse;
        float acceleration;
	SDL_Rect position_personnage; 
	SDL_Rect posSprit;
	SDL_Surface *imgperso;
	float score;
	SDL_Rect pos_score;
        int sens;        
        int crouch;
        int up;
	SDL_Rect posrel;        
}personnage;


/*------initialisation------*/
void initPerso(personnage *p);
/*-------affichage_personnage-----*/
void afficher_personnage(personnage p,SDL_Surface *ecran);
/*---- animations -----*/
void animerPerso (int action,personnage* p);
/*---- deplacements ----*/
void deplacerPerso (personnage *p,int action,Uint32 dt);
/*---- controle saut ---------*/
void Saute(personnage *p,int action);
/*------reglage de vitesse-------*/
void vitesse_perso(personnage *p,int action,Uint32 dt);
/*fonction mis a jour*/
void mis_a_jour(personnage *p,int *action,int *att,int *jum,int *retl,int *retr);

/*......afficher une background......*/ 
//void init_bg(image *D);
//void afficher(image p,SDL_Surface *ecran);






typedef struct {
	SDL_Rect pos;
	SDL_Surface *img,image;
	SDL_Rect camera;
}image;

typedef struct {
  SDL_Surface *bg;
SDL_Surface *background;
	    SDL_Rect camera;
      SDL_Rect pos;
}background;

typedef struct {
Mix_Music *musique;
int vol;
} music1;


void initialiser_backround (background *b);
void afficher_background (SDL_Surface *screen,background *b);

void initBackground(image *Backg);
void initasfour(image *asfour);
void libererimg(image A);
void afficher(image A,SDL_Surface *screen);

void intvideo(music1 *m); 
void playmusic(music1 *m);
void freemusic(music1 *m);

void anime11(SDL_Rect* clip);
int collision (SDL_Rect* rec1, SDL_Rect* rec2);
void scrolling_right (background *b);
void scrolling_left (background *b);
void scrolling_UP (background *b);
void scrolling_down (background *b);
void free_memory (background *b );
















#endif
