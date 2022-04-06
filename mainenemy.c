#include "enemy.h"

void main()
{
//      ***************************INITIALISATION***************************
	SDL_Surface *screen = NULL;
	SDL_Event event;
	es E;
	background back,exp;
	int cont = 1;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
 	{
		printf("Unable to initialisation SDL : %s\n",SDL_GetError());
	}
	SDL_WM_SetCaption("ENEMY",NULL);
	screen = SDL_SetVideoMode(600,360,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (screen == NULL)
	{
		printf("error : %s\n",SDL_GetError());
	}
	back.img = IMG_Load ("background.jpg");
	exp.img = IMG_Load ("exp.png");
	back.pos.x = 0;
	back.pos.y = 0;
	exp.pos.x = 200;
	exp.pos.y = 200;
	exp.pos.w = 150;
	exp.pos.h = 150;
	initenemy(&E);
//      ***************************BOUCLE***************************
	while (cont)
	{		
		SDL_BlitSurface(back.img,NULL,screen,&back.pos);
		SDL_BlitSurface(exp.img,NULL,screen,&exp.pos);
		afficherenemy(E,screen);
		animerenemy(&E);
		deplacer(&E);
		SDL_Delay(100);
		if (collisionBox(exp.pos,E.posEN))
			printf("cc");
		else
			printf("ss");
		SDL_PollEvent(&event);	
		if ((event.type == SDL_QUIT)||(event.key.keysym.sym == SDLK_ESCAPE))
				cont = 0;	
		SDL_Flip(screen);
	}
	SDL_Quit();
}
