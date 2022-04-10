#ifndef Text_H
#define Text_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <time.h>

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
void init_bg(image *D);
void afficher(image p,SDL_Surface *ecran);

#endif
