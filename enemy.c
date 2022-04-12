#include "enemy.h"

void initenemy(es *e)
{
	e->imgEnemy = IMG_Load ("enemy.png");
	e->posEN.x = 400;
	e->posEN.y = 520;
	e->posEN.w = 156;
	e->posEN.h = 156;
	e->posSprit.x = 0;
	e->posSprit.y = 785;
	e->posSprit.w = 156;
	e->posSprit.h = 156;
	e->direct = 0;
}

void afficherenemy(es e,SDL_Surface *screen)
{
	SDL_BlitSurface(e.imgEnemy,&e.posSprit,screen,&e.posEN);
}

void animerenemy(es *e)
{
	switch(e->direct)
	{
		case 0 : //droite
			if(e->posSprit.x >= 1200)
				e->posSprit.x = 0;
			else
				e->posSprit.x = e->posSprit.x + e->posSprit.w;
			break;
		case 1 : //gauche
			if(e->posSprit.x >= 1200)
				e->posSprit.x = 0;
			else
				e->posSprit.x = e->posSprit.x + e->posSprit.w;
			break;
	}
}

void deplacer(es *e)
{
	if(e->posEN.x > 500)
	{
		e->direct = 1;
		e->posSprit.y = 630;
	}
	else
	{
		if (e->posEN.x < 100)
		{
			e->direct = 0;
			e->posSprit.y = 785;
		}
	}
	if (e->direct == 0)
		e->posEN.x+=10;
	else
		e->posEN.x-=10;	
}

int collisionBox(SDL_Rect a, SDL_Rect b)
{ 
    if(a.x+a.h<b.x || a.x>b.x+b.w ||a .y+a.h<b.y || a.y>b.y+b.h)
        return 0;
        else 
        return 1;
}


