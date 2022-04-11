#include "perso.h"
#include "enemy.h"
#include "background.h"
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <time.h>

int main()
{
//////////////////////////////////////// DECLARATION DES VARIABLES ////////////////////////////////////////
	background bg;
	personnage p;
	es E;
	image oiseau;
	SDL_Surface* ecran;
	int cont=0,frame=0,FPS=10;
	int action=0,att=0,jum=0,retl=0,retr=0;               //le variable retl nous aide a faire l'animation de retard a gauche 
	SDL_Init ( SDL_INIT_VIDEO );
	SDL_Event event;
	SDL_Event event2;
	Mix_Chunk *sonbref1;
	Mix_Chunk *sonbref2;
	Uint32 dt, t_prev,start;
////////////////////////////////////////       INITIALISATION       ////////////////////////////////////////
	ecran= SDL_SetVideoMode(1397,860, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	initPerso(&p);
	initialiser_backround (&bg);
	initenemy(&E);
	initasfour(&oiseau);
	sonbref1=Mix_LoadWAV("/home/alaa/superbia/Jump_sound.mp3");	
	sonbref2=Mix_LoadWAV("/home/alaa/superbia/Sword Sound Effect .mp3");	

////////////////////////////////////////       BOUCLE DU JEUX       ////////////////////////////////////////
	while(cont==0)
	{
		t_prev=SDL_GetTicks();	//au début de la boucle de jeu
		dt=0;
		do
		{
			dt=SDL_GetTicks()-t_prev;
		}while(dt<50);
		animerenemy(&E);
		deplacer(&E);
		SDL_PollEvent(&event);
		if (event.type==SDL_KEYDOWN )
		{
		mis_a_jour(&p,&action,&att,&jum,&retl,&retr); 
			switch(event.key.keysym.sym)
			{	
				///crouch
				case SDLK_DOWN:
					action=1; /////9éme ligne du sprite sheet
					break;
				///jump
				case SDLK_UP:
					Mix_PlayChannel(-1,sonbref1,0);
					action=2; //////1ere ligne du sprit sheet
					if(jum==0)
						p.posSprit.x=0;
					while(jum<5)
					{
						t_prev=SDL_GetTicks();	//au début de la boucle de jeu
						dt=0;
						do
							dt=SDL_GetTicks()-t_prev;
						while(dt<80);
						afficher_background(ecran,&bg);
						Saute(&p,action);
						animerPerso (action,&p);
						afficher_personnage(p,ecran);
						animerenemy(&E);
						deplacer(&E);
						afficherenemy(E,ecran);
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
					while(att<4)
					{
						t_prev=SDL_GetTicks();	//au début de la boucle de jeu
						dt=0;
						do{
							dt=SDL_GetTicks()-t_prev;
						}while(dt<40);
						afficher_background(ecran,&bg);
						vitesse_perso(&p,action,dt);
						deplacerPerso (&p,action,dt);
						animerPerso (action,&p);
						afficher_personnage(p,ecran);
						animerenemy(&E);
						deplacer(&E);
						afficherenemy(E,ecran);
						SDL_Flip(ecran);
						att++; 
					}
					break;
			}
		}
	
		else if (event.type==SDL_QUIT)
		{
			cont=1;
			break;
		}
		////reduire la vitesse du joueur si aucune bouton n'est pressé ////
		else if (event.type==SDL_KEYUP)
		{
			if((event.key.keysym.sym==SDLK_RIGHT) && (p.sens==1))
			{
				if(retr<3)
					action=6;
			}
			if((event.key.keysym.sym==SDLK_LEFT) && (p.sens==0))
			{
				if(retl<3)
					action=8;
			}
		}
		if (collisionBox(p.position_personnage,E.posEN))
		{
			action=7; 
					if(att==0)
					p.posSprit.x=0;
					while(att<4)
					{
						t_prev=SDL_GetTicks();	//au début de la boucle de jeu
						dt=0;
						do{
							dt=SDL_GetTicks()-t_prev;
						}while(dt<40);
						afficher_background(ecran,&bg);
						vitesse_perso(&p,action,dt);
						deplacerPerso (&p,action,dt);
						animerPerso (action,&p);
						afficher_personnage(p,ecran);
						animerenemy(&E);
						deplacer(&E);
						afficherenemy(E,ecran);
						SDL_Flip(ecran);
						att++; 
					}
		}
		vitesse_perso(&p,action,dt);
		afficher_background(ecran,&bg);
		if(att<2)
		deplacerPerso (&p,action,dt); 
		if(jum<2&&att<2)
			animerPerso (action,&p);
		afficher_personnage(p,ecran);
		afficherenemy(E,ecran);
		mis_a_jour(&p,&action,&att,&jum,&retl,&retr); 
		SDL_Flip(ecran);
	}
	SDL_FreeSurface(ecran);
	return 0;
}
