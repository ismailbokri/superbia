#include "enemy.h"

void initenemy(es *e)
{
	e->imgEnemy = IMG_Load ("enemy.png");
	e->posEN.x = 100;
	e->posEN.y = 130;
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
	int leftSideA = a.x;
	int rightSideA = a.x + a.w;
	int topA = a.y;
	int bottomA = a.y + a.h;

	int leftSideB = b.x;
	int rightSideB = b.x + b.w;
	int topB = b.y;
	int bottomB = b.y + b.h;

	if((bottomA <= topB)||(topA >= bottomB)||(rightSideA <= leftSideB)||(leftSideA >= rightSideB))
		return 1;
	else
		return 0;
} 


