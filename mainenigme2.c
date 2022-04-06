    
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
#include <stdio.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include "enigme2.h"
void main ()
{
SDL_Surface* screen;
SDL_event event;
screen = SDL_SetVideoMode(1397,860, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);
enigme e ;
initenigme(enigme *e);
afficher_enigme(&e,screen);
animer(enigme *e);

}
