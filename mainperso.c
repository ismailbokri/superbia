#include "perso.h"
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <time.h>

int main(){
image bg;
personnage p;
SDL_Surface* ecran;
int showperso=0;
int action=0,att=0,jum=0,retl=0,retr=0;               //le variable retl nous aide a faire l'animation de retard a gauche 
SDL_Init ( SDL_INIT_VIDEO );
SDL_Event event;
SDL_Event event2;
Uint32 dt, t_prev;
ecran= SDL_SetVideoMode(1397,860, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);
initPerso(&p);
init_bg(&bg);

////////////// initialisé le son bref////////////////////////
Mix_Chunk *sonbref1;
sonbref1=Mix_LoadWAV("/home/ismail/Desktop/psh/Jump_sound.mp3");	
Mix_Chunk *sonbref2;
sonbref2=Mix_LoadWAV("/home/ismail/Desktop/psh/Sword Sound Effect .mp3");	

while(showperso==0){
t_prev=SDL_GetTicks();	//au début de la boucle de jeu

dt=0;
do{
dt=SDL_GetTicks()-t_prev;
}while(dt<50);

SDL_PollEvent(&event);
if (event.type==SDL_KEYDOWN ){
	switch(event.key.keysym.sym){
	
///crouch
case SDLK_DOWN:
	action=1;/////9éme ligne du sprite sheet
break;

///jump
case SDLK_UP:
		Mix_PlayChannel(-1,sonbref1,0);
	action=2;//////1ere ligne du sprit sheet
		if(jum==0)
			p.posSprit.x=0;

		while(jum<5){
			t_prev=SDL_GetTicks();	//au début de la boucle de jeu
			dt=0;
				do{
				dt=SDL_GetTicks()-t_prev;
				}while(dt<80);
		afficher(bg,ecran);
		Saute(&p,action);
		animerPerso (action,&p);
		afficher_personnage(p,ecran);
		SDL_Flip(ecran);
		jum++; 
		}				
break;

///attack
case SDLK_SPACE:
		Mix_PlayChannel(-1,sonbref2,0);
	action=3;
break;

/// walk right 
case SDLK_RIGHT:
	action=4;//////5eme ligne du sprit sheet	
break;

///walk left
case SDLK_LEFT:
	action=5;//////6eme ligne du sprit sheet
break;

///animation personnage attacké 
case SDLK_a:
	action=7; 
	if(att==0)
		p.posSprit.x=0;
	while(att<4){
		t_prev=SDL_GetTicks();	//au début de la boucle de jeu
		dt=0;
		do{
		dt=SDL_GetTicks()-t_prev;
		}while(dt<40);
	afficher(bg,ecran);
	vitesse_perso(&p,action,dt);
	deplacerPerso (&p,action,dt);
	animerPerso (action,&p);
	afficher_personnage(p,ecran);
	SDL_Flip(ecran);
	att++; 
	}
break;
	}
}
	
	else if (event.type==SDL_QUIT){
		showperso=1;
		break;
		}
////reduire la vitesse du joueur si aucune bouton n'est pressé ////
	
	else if (event.type==SDL_KEYUP){
		if((event.key.keysym.sym==SDLK_RIGHT) && (p.sens==1)){
			if(retr<3){
				action=6;
				}
		}
		if((event.key.keysym.sym==SDLK_LEFT) && (p.sens==0)){
			if(retl<3){
				action=8;
				}
		}
	}
	

vitesse_perso(&p,action,dt);
afficher(bg,ecran);
deplacerPerso (&p,action,dt); 
if(jum<2)
animerPerso (action,&p);
afficher_personnage(p,ecran);
mis_a_jour(&p,&action,&att,&jum,&retl,&retr); 
SDL_Flip(ecran);

	
mis_a_jour(&p,&action,&att,&jum,&retl,&retr); 
}

SDL_FreeSurface(ecran);
return 0;
}
