#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <string.h>


typedef struct 
{
char mazesmall[50],mazebig[50];
 SDL_Surface *maze[6],*timer[10],*back;
 SDL_Rect 	posmaze[6],postimer,posback;
 int reponsejuste,reponse,r[3];
}enigme;



void InitEnigme(enigme * e, char *nomfichier);
void afficherEnigme(enigme e, SDL_Surface * screen);
void animer (enigme *e);

