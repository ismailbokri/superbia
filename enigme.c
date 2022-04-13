

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "enigmef.h"
#include <time.h>
#include <math.h>
#define nombre_de_question 4
int input(SDL_Rect pos,int x,int y){
if(x>pos.x&&x<pos.x+pos.w&&y>pos.y&&y<pos.y+pos.h)
return 1;
return 0;
}


void initenigme(enigme *e){
char load[80];
srand(time(0));
FILE *f;
f=fopen("source.txt","r");
char question[50],rep[3][50];
int r=rand()%nombre_de_question+1;
for(int i=0;i<r;i++)
fscanf(f,"%s %s %s %s %d\n",question,rep[0],rep[1],rep[2],&e->solution);
fclose(f);
e->color.r=255;
e->color.g=255;
e->color.b=255;
//blanc
e->loop=0;
e->font=TTF_OpenFont("youmurdererbb_reg.ttf",50); //reponse
e->font2=TTF_OpenFont("youmurdererbb_reg.ttf",30);//question
e->font3=TTF_OpenFont("youmurdererbb_reg.ttf",220);//failed ou passed
e->rep=0;
changechar(question);
changechar(rep[0]);
changechar(rep[1]);
changechar(rep[2]);
//colouring of the questions
for(int i=0;i<3;i++)
e->a[i]=TTF_RenderText_Blended(e->font,rep[i],e->color);
//a: button allume
e->color.r=255;
e->color.g=0;
e->color.b=0;
//noir
for(int i=0;i<3;i++)
e->b[i]=TTF_RenderText_Blended(e->font,rep[i],e->color);
//button non allume
e->question=TTF_RenderText_Blended(e->font2,question,e->color);
//le question est colore en noir 
e->posq.x=60;
e->posq.y=40;
e->posq.w=e->question->w;
e->posq.h=e->question->h;
//pos question
for (int i=0;i<3;i++)
{
e->posb[i].x=100;
e->posb[i].y=100+i*60;
e->posb[i].w=e->b[i]->w;
e->posb[i].h=e->b[i]->h;
}
// pos button (allume et non allume)
e->faild=TTF_RenderText_Blended(e->font3,"failed",e->color);
e->passed=TTF_RenderText_Blended(e->font3,"passed",e->color);
//coloring the failed and passed
for(int i=0;i<5;i++)
{
sprintf(load,"bach/%d.gif",i);
e->back[i]= IMG_Load(load);}
}
//loading the pictures of the background



void changechar(char ch[]){
for(int i=0;i<strlen(ch);i++){
if(ch[i]=='.'){ch[i]=' ';}
}
}


void afficherenigmef(enigme *e,SDL_Surface *screen,int x,int y){
SDL_BlitSurface (e->back[e->loop],NULL,screen,NULL); e->loop++;
if(e->loop==5)e->loop=0;
if(e->rep==0)
{
for(int i=0;i<3;i++){
SDL_BlitSurface(e->b[i],NULL,screen,&e->posb[i]);
		if(input(e->posb[i],x,y)){
		SDL_BlitSurface(e->a[i],NULL,screen,&e->posb[i]);
		}}

SDL_BlitSurface(e->question,NULL,screen,&e->posq);
}else if(e->rep==e->solution){
SDL_BlitSurface(e->passed,NULL,screen,&e->posb[1]);
}else{ 
SDL_BlitSurface(e->faild,NULL,screen,&e->posb[1]);
}
}

