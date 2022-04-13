#ifndef __ENIGME_H__
#define __ENIGME_H__
typedef struct{
SDL_Surface *back[5];
SDL_Surface *b[3];
SDL_Surface *a[3];
SDL_Surface *question,*faild,*passed;
SDL_Rect posb[3],posq;
SDL_Color color;
TTF_Font *font,*font2,*font3;
int rep,solution,loop;
}enigme;


int input(SDL_Rect pos,int x,int y);
void initenigme(enigme *e);
void changechar(char ch[]);
void afficherenigmef(enigme *e,SDL_Surface *screen,int x,int y);
#endif
