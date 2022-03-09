
#include <stdlib.h> 
#include <stdio.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h> 
#include<SDL/SDL_audio.h>


#define STAT_SOL 0
#define STAT_AIR 1
 
#define STAT_MARCHE 1
#define STAT_NOT_MARCHE 0

typedef struct  personnage
{
	int vie;
	int vitesse;
	SDL_Rect position_personnage; 
	SDL_Surface *tab[/*nb*/];
	float time;
	int score;
	SDL_Rect pos_score;
        int status;
        float x,y;
}personnage;



void initialiser_personnage(personnage *p);
void afficher_personnage(personnage p,SDL_Surface *ecran);


/* 
/*---- animations -----*/

void animation_walk_right (personnage *p);
void animation_walk_left (personnage *p);

void animation_jump_right (personnage *p);
void animation_jump_left (personnage *p);

void animation_run_right (personnage *p);
void animation_run_left (personnage *p);

void animation_fail_right (personnage *p);
void animation_slide_right (personnage *p);
void animation_crouch_right (personnage *p);

void animation_attack_right (personnage *p);
void animation_attack_left (personnage *p);

*/
/*---- deplacements ----*/

void deplacement_clavier_left(personnage *p,int clic);
void deplacement_souris(personnage *p,int clic);


/*---- controle saut ---------*/
void saut (Personne* p);

