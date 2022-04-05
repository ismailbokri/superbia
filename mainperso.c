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
int action=0,att=0,jum=0;
SDL_Init ( SDL_INIT_VIDEO );
SDL_Event event;
SDL_Event event2;
Uint32 dt, t_prev;

ecran= SDL_SetVideoMode(1397,860, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);
initPerso(&p);
init_bg(&bg);
afficher(bg,ecran);
afficher_personnage(p,ecran);
SDL_Flip(ecran);
t_prev=SDL_GetTicks();	

while(showperso==0){

t_prev=SDL_GetTicks();	//au début de la boucle de jeu
dt=0;
do{
dt=SDL_GetTicks()-t_prev;
}while(dt<50);
	//SDL_Delay(60);
	
SDL_PollEvent(&event);

if (event.type==SDL_KEYDOWN ){
switch(event.key.keysym.sym){

///crouch
case SDLK_DOWN:
jum=0;
att=0;
action=1;/////9éme ligne du sprite sheet
afficher(bg,ecran);
animerPerso (action,&p);
afficher_personnage(p,ecran);
SDL_Flip(ecran);
break;

jum=0;
///jump
case SDLK_UP:
att=0;
if(jum==0)
p.posSprit.x=0;
while(jum<5){
t_prev=SDL_GetTicks();	//au début de la boucle de jeu
dt=0;
do{
dt=SDL_GetTicks()-t_prev;
}while(dt<80);
action=2;//////1ere ligne du sprit sheet
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
jum=0;
att=0;
action=3;//////3ere ligne du sprit sheet
do{
dt=SDL_GetTicks()-t_prev;
}while(dt<80);
afficher(bg,ecran);
animerPerso (action,&p);
afficher_personnage(p,ecran);
SDL_Flip(ecran);
break;

/// walk right 
case SDLK_RIGHT:
jum=0;
att=0;
p.sens=1;
action=4;//////5eme ligne du sprit sheet
afficher(bg,ecran);
dt=SDL_GetTicks()-t_prev;//à la fin de la boucle de jeu
 vitesse_perso(&p,action,dt);
deplacerPerso (&p,action,dt);
animerPerso (action,&p);
afficher_personnage(p,ecran);
SDL_Flip(ecran);
break;

///walk left
case SDLK_LEFT:
jum=0;
att=0;
p.sens=0;
action=5;//////6eme ligne du sprit sheet
afficher(bg,ecran);
dt=SDL_GetTicks()-t_prev;
 vitesse_perso(&p,action,dt);
deplacerPerso (&p,action,dt);
animerPerso (action,&p);
afficher_personnage(p,ecran);
SDL_Flip(ecran);
break;



///animation personnage attacké 
case SDLK_a:
jum=0;
if(att==0)
p.posSprit.x=0;
while(att<3){
t_prev=SDL_GetTicks();	//au début de la boucle de jeu
dt=0;
do{
dt=SDL_GetTicks()-t_prev;
}while(dt<40);
action=7; 
afficher(bg,ecran);
dt=SDL_GetTicks()-t_prev;
vitesse_perso(&p,action,dt);
deplacerPerso (&p,action,dt);
animerPerso (action,&p);
afficher_personnage(p,ecran);
SDL_Flip(ecran);
att++; 
}
break;


}}



else if (event.type==SDL_QUIT)
{showperso=1;
break;
}////reduire la vitesse du joueur si aucune bouton n'est pressé ////



else if (event.type==SDL_KEYUP){
if((event.key.keysym.sym==SDLK_RIGHT) && (p.sens==1))
{
action=6;
 vitesse_perso(&p,action,dt);
if((p.vitesse)>0){
 afficher(bg,ecran);
dt=SDL_GetTicks()-t_prev;
deplacerPerso (&p,action,dt); 
animerPerso (action,&p);
afficher_personnage(p,ecran);
SDL_Flip(ecran);}
}

if((event.key.keysym.sym==SDLK_LEFT) && (p.sens==0))
{
action=6;
 vitesse_perso(&p,action,dt);
if((p.vitesse)>0){
 afficher(bg,ecran);
dt=SDL_GetTicks()-t_prev;
deplacerPerso (&p,action,dt); 
animerPerso (action,&p);
afficher_personnage(p,ecran);
SDL_Flip(ecran);}
}}



}
SDL_FreeSurface(ecran);
return 0;
}
