#include "enemy.h"

void initenemy(es *e)
{
	e->imgEnemy = IMG_Load ("enemy.png");
	e->posEN.x = 100;
	e->posEN.y = 100;
	e->posSprit.x = 0;
	e->posSprit.y = 750;
	e->posSprit.w = 150;
	e->posSprit.h = 150;
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
			if(e->posSprit.x == 1200)
				e->posSprit.x = 0;
			else
				e->posSprit.x = e->posSprit.x + e->posSprit.w;
			break;
		case 1 : //gauche
			if(e->posSprit.x == 1200)
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
		e->posSprit.y = 600;
	}
	else
	{
		if (e->posEN.x < 100)
		{
			e->direct = 0;
			e->posSprit.y = 750;
		}
	}
	if (e->direct == 0)
		e->posEN.x+=10;
	else
		e->posEN.x-=10;	
}


