#include <stdlib.h> 
#include <stdio.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h> 
#include<SDL/SDL_audio.h>


typedef struct  personnage
{
	int vie;
	float vitesse;
	SDL_Rect position_personnage; 
	SDL_Rect posSprit;
	SDL_Surface *imgperso;
	float score;
	SDL_Rect pos_score;
        int sens;
}personnage;

/*------initialisation------*/
void initPerso(Personnage *p);
/*-------affichage_personnage-----*/
void afficher_personnage(personnage p,SDL_Surface *ecran);
/*---- animations -----*/
void animerPerso (Personnage* p);
/*---- deplacements ----*/
void deplacerPerso (personnage *p,int clic);
/*---- controle saut ---------*/
void Saute(personnage *p);

#endif // HEADER5_H_INCLUDED

