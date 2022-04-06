#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void initialiser_backround (background *b)
{

b->background=NULL;
b->bg=NULL;

b->pos.x=0;
b->pos.y=0;
b->pos.w=1800;
b->pos.h=720;


b->camera.x=0;
b->camera.y=0;
b->camera.w=1800;
b->camera.h=720;
b->background=IMG_Load("map.jpg");
b->bg=IMG_Load("masks.jpg");

}

void afficher_background (SDL_Surface *screen,background *b)
{
SDL_BlitSurface(b->bg,&(b->pos),screen,NULL);

	SDL_BlitSurface(b->background,&(b->camera),screen,NULL);
}
void initasfour(image *asfour){




asfour->img= IMG_Load("./asfour.png");
	if (asfour->img == NULL) {
		printf("Unable to load : %s\n", SDL_GetError());
		return;
		}
	asfour->pos.x=0;
	asfour->pos.y=0;
	asfour->pos.w=SCREEN_W; 
	asfour->pos.h=SCREEN_H;
}
void libererimg(image A){
	SDL_FreeSurface(A.img); 
}
void afficher(image p,SDL_Surface *screen)
{
  SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
	SDL_BlitSurface(p.img,NULL,screen,&p.pos);
}

//music
void intvideo(music1 *m){

 m->musique=Mix_LoadMUS("Epic Arabian Music Golden Age.mp3");
 m->vol=100;
 Mix_VolumeMusic(m->vol);
}

void playmusic(music1 *m){
Mix_PlayMusic(m->musique,-1);
}

void freemusic( music1 *m){
Mix_FreeMusic(m->musique);
}
void anime11(SDL_Rect* clip){
clip[ 0 ].x = 0;
    clip[ 0 ].y = 0;
    clip[ 0 ].w = 160;
    clip[ 0 ].h = 180;
 
    //On coupe la partie en haut à droite (second sprite)
    clip[ 1 ].x = 130;
    clip[ 1 ].y = 0;
    clip[ 1 ].w = 160;
    clip[ 1 ].h = 180;
 
    //On coupe la partie en bas à gauche (troisième sprite)
    clip[ 2 ].x = 300;
    clip[ 2 ].y = 0;
    clip[ 2 ].w = 160;
    clip[ 2 ].h = 180;
 }


void scrolling_right (background *b)
{

	if (b->camera.x<=1130){
		 b->pos.x+=70 ;
		b->camera.x+=70; 
		
		}


}


void scrolling_left (background *b)
{
	if (b->camera.x>=70){
	
  b->pos.x-=70 ;
b->camera.x-=70 ;

}



}
void scrolling_UP (background *b)
{

	if (b->camera.y<20){
		 b->pos.y+=20 ;
		b->camera.y+=20; 
		
		}


}
void scrolling_down (background *b)
{
	if (b->camera.y>=20){
	
  b->pos.y-=20 ;
b->camera.y-=20 ;

}
}

void free_memory (background *b )
{ 
 
 SDL_FreeSurface (b->background) ;
 SDL_FreeSurface (b->bg) ;


 SDL_Quit () ;

}
