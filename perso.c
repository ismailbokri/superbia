#include "perso.h"
#include "background.h"
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
//**//

/*------initialisation p1 ------*/
void initPerso(personnage *p){

p->sens=1;/*-----sens==1(turn right)------/-----sens==0(turn left)------*/
p->imgperso = IMG_Load("/home/alaa/superbia/sprite-sheet2.png");
p->position_personnage.x=0;
p->position_personnage.y=520;

p->crouch=0;

p->vie=3; 	
p->posSprit.x=0;
p->posSprit.y=320;	
p->posSprit.w=150;
p->posSprit.h=150;	

p->up=0;

p->score=0;
p->pos_score.x=600;
p->pos_score.y=30;

p->posrel.x = -50;  
p->posrel.y = 0;


p->vitesse=0; /////vitesse maximale =0.8///////vitesse minimale =0.1
p->acceleration=0; //acceleration augmente de 0.005et diminue de 0.001;


}

void afficher_personnage(personnage p,SDL_Surface *ecran)
{
  SDL_BlitSurface(p.imgperso,&p.posSprit,ecran,&p.position_personnage);
}



void animerPerso (int action,personnage* p){

switch(action){

case 1:

p->posSprit.y =1260;////(se positionner dans la ligne correspondant a la direction)
if(p->crouch==0){
p->posSprit.x = p->posSprit.x+156; 
if(p->posSprit.x>=450)
p->posSprit.x=450;
}else
{p->crouch=1;
p->posSprit.x=0;
}
break;
case 2:
p->crouch=0;
 if(p->sens==1){
p->posSprit.y=150;////(se positionner dans la ligne correspondant a la direction)

if(p->posSprit.x>900) ////(si dernier frame atteint)
{
p->posSprit.x=0;  ////// (revenir au premier frame)
}
else 
p->posSprit.x = p->posSprit.x+156; 
}
else if(p->sens==0){

p->posSprit.y =0;////(se positionner dans la ligne correspondant a la direction)

if(p->posSprit.x>900) ////(si dernier frame atteint)
{
p->posSprit.x=0;  ////// (revenir au premier frame)
}
else 
p->posSprit.x = p->posSprit.x+156; 
}
break;



case 3:
p->crouch=0;
if(p->sens==1){

p->posSprit.y =470;////(se positionner dans la ligne correspondant a la direction)

if(p->posSprit.x>1050) ////(si dernier frame atteint)
{
p->posSprit.x=0;  ////// (revenir au premier frame)
}
else 
p->posSprit.x = p->posSprit.x+163; 
}
else if(p->sens==0){
p->posSprit.y =320;////(se positionner dans la ligne correspondant a la direction)

if(p->posSprit.x>1050) ////(si dernier frame atteint)
{
p->posSprit.x=0;  ////// (revenir au premier frame)
}
else 
p->posSprit.x = p->posSprit.x+163; 
}
break;

case 4:
p->crouch=0;
p->posSprit.y =779;////(se positionner dans la ligne correspondant a la direction)

if(p->posSprit.x>=1200) ////(si dernier frame atteint)
{
p->posSprit.x=0;  ////// (revenir au premier frame)
}
else 
p->posSprit.x = p->posSprit.x+156; 
break;

case 5:
p->crouch=0;
p->posSprit.y =630;////(se positionner dans la ligne correspondant a la direction)

if(p->posSprit.x>=1200) ////(si dernier frame atteint)
{
p->posSprit.x=0;  ////// (revenir au premier frame)
}
else 
p->posSprit.x = p->posSprit.x+156; 
break;




case 6:
p->posSprit.y =779;////(se positionner dans la ligne correspondant a la direction)
p->posSprit.x=0;  ////// (revenir au premier frame)
break;

case 8:
p->posSprit.y =630;////(se positionner dans la ligne correspondant a la direction)
p->posSprit.x=0;  ////// (revenir au premier frame)
break;


case 7:
p->crouch=0;
 if(p->sens==1){
p->posSprit.y=1420;////(se positionner dans la ligne correspondant a la direction)

if(p->posSprit.x<600) ////(si dernier frame atteint)
{ 
p->posSprit.x = p->posSprit.x+156; 
}else{
p->vie--;
SDL_Delay(500);
}
if(p->posSprit.x>=600)
p->posSprit.x=0;

}

else if(p->sens==0){

p->posSprit.y =1570;////(se positionner dans la ligne correspondant a la direction)

if(p->posSprit.x<600) ////(si dernier frame atteint)
{
p->posSprit.x = p->posSprit.x+156; 
}
else{
p->vie--;
SDL_Delay(500);
}
if(p->posSprit.x>=600)
p->posSprit.x=0;
}
break;
}
}
void deplacerPerso (personnage *p,int action,Uint32 dt){



if((action==4) &&(p->position_personnage.x<800)&&(p->vitesse>=0))
p->position_personnage.x +=(p->vitesse) *dt;

if((action==5) &&(p->position_personnage.x>30)&&(p->vitesse>=0))
p->position_personnage.x -=(p->vitesse) *dt;

if((action==7)&&(p->position_personnage.x>30)&&(p->position_personnage.x<800)&&(p->vitesse>=0))
{
if(p->sens==1)
p->position_personnage.x -=50;
if(p->sens==0)
p->position_personnage.x +=50;
}


}


/*void init_bg(image *D){
D->img = IMG_Load("/home/ismail/Desktop/psh/bg roman.png");
	D->pos.x = 0;
	D->pos.y = 0;
}


void afficher(image p,SDL_Surface *ecran)
{
	SDL_BlitSurface(p.img,NULL,ecran,&p.pos);
}
*/


void vitesse_perso(personnage *p,int action,Uint32 dt){

(p->vitesse)+=(p->acceleration)*dt;

switch (action){ 
case 4:///right
if((p->vitesse)<1)
 p->acceleration+=0.001;
break;

case 5:///left
if((p->vitesse)<1)
 p->acceleration+=0.001;
break;


case 6: 
if((p->vitesse)>0.1)
(p->acceleration)-=0.005;
break;

case 8: 
if((p->vitesse)>0.1)
(p->acceleration)-=0.005;
break;
}

if((p->vitesse)>0.5)
p->vitesse=0.5;
if((p->vitesse)<0.1)
p->vitesse=0.1;

}

void Saute(personnage *p,int action){

if((p->up==0)&&(p->position_personnage.y>380))
		p->position_personnage.y-=70;
else if ((p->up==0)&&(p->position_personnage.y==380))
p->up=1;



if((p->up==1)&&(p->position_personnage.y<520))
p->position_personnage.y+=70;
else if ((p->up==1)&&(p->position_personnage.y==520))
p->up=0;



if(p->sens==1)
p->position_personnage.x +=50;

if(p->sens==0)
p->position_personnage.x -=50;
}


void mis_a_jour(personnage *p,int *action,int *att,int *jum,int *retl,int *retr) {

switch(*action){
case 1:
	(*jum)=0;
	(*att)=0;
	(*retr)=0;
	(*retl)=0;
break;

case 2:
	(*att)=0;
	(*retr)=0;
	(*retl)=0;
	(*jum)++;

break;

case 3:
	(*jum)=0;
	(*att)=0;
	(*retr)=0;
	(*retl)=0;
	(*action)=0;
break;

case 4:
	(*jum)=0;
	(*att)=0;
	(*retr)=0;
	(*retl)=0;
	p->sens=1;

break;

case 5:
	(*jum)=0;
	(*att)=0;
	(*retr)=0;
	(*retl)=0;
	p->sens=0;

break;

case 7:
	(*jum)=0;
	(*retr)=0;
	(*retl)=0;
	(*action)=0;
break;

case 6:
retr++;
break;


case 8:
retr--;
break;

}


}
