#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "enigmef.h"


int main (int argc, char **argv)
{
enigme en; 
int done=1;
int x,y;
SDL_Init (SDL_INIT_EVERYTHING);
TTF_Init();
SDL_Surface *screen;
screen= SDL_SetVideoMode(800,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_Event event;
initenigme(&en);
while(done){
while(SDL_PollEvent(&event)){
switch (event.type){
	case SDL_QUIT:
		done=0;
		break;

	case SDL_KEYDOWN:
		switch(event.key.keysym.sym){
		case SDLK_ESCAPE:
		done=0;
		break;
		case SDLK_a:
		en.rep=1;
		break;
		case SDLK_b:
		en.rep=2;
		break;
		case SDLK_c:
		en.rep=3;
		break;
		}

	case SDL_MOUSEBUTTONDOWN:

		if(event.button.button ==SDL_BUTTON_LEFT){
		if(en.rep!=0){done=0;}else{
		for(int i=0;i<3;i++)
		if(input(en.posb[i],event.button.x,event.button.y)){
		en.rep=i+1;
		}}
		}break;

	case SDL_MOUSEMOTION:
		x=event.motion.x;
		y=event.motion.y;
	}
}  
afficherenigmef(&en,screen,x,y);
SDL_Flip (screen);
SDL_Delay (40);
}
TTF_Quit;
SDL_Quit;
}
