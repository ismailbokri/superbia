#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
#include <stdio.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include "enigme2.h"
void initenigme(enigme *e)
    {
        
        TTF_Init();

int x;
        
        //background
        e->background=IMG_Load("str");//img random engime 
        //background pos
        e->background_pos.x = 200;
        e->background_pos.y = 200;

        //buttons a b c
        e->buttonA[0]=IMG_Load("resources/image/engimepic/blackbutton.png");
        e->buttonA[1]=IMG_Load("resources/image/engimepic/whitebutton.jpeg");

        e->buttonB[0]=IMG_Load("resources/image/engimepic/blackbutton.png");
        e->buttonB[1]=IMG_Load("resources/image/engimepic/whitebutton.jpeg");

        e->buttonC[0]=IMG_Load("resources/image/engimepic/blackbutton.png");
        e->buttonC[1]=IMG_Load("resources/image/engimepic/whitebutton.jpeg");


        //right or false
        e->congra[0]=IMG_Load("resources/image/engimepic/right.png");
        e->congra[1]=IMG_Load("resources/image/engimepic/false.png");

        //pos buttons a b c
        //a
        e->pos_A.x= 200;
        e->pos_A.y= 500;
        //b
        e->pos_B.x= 400;
        e->pos_B.y= 500;
        //c
        e->pos_C.x= 600;
        e->pos_C.y= 500;

        //correct or false
        e->pos_yes_no.x= 450;
        e->pos_yes_no.y= 450;
        //pos time
        e->pos_time.x= 700;
        e->pos_time.y= 100;

        //pos reponse 1
        e->pos_reponse1txt.x= 200;
        e->pos_reponse1txt.y= 500;
        //pos rep 2
        e->pos_reponse1txt.x= 400;
        e->pos_reponse1txt.y= 500;
        //pos rep 3
        e->pos_reponse1txt.x= 600;
        e->pos_reponse1txt.y= 500;

        //random position for awnser
        x= rand() % 3;//position random number 0--2 correct awnser

        e->positionVraiReponse=x;



    //awnsers 
    int k;   
        for(k=0;k<3;k++)
            {
                if(k!=x)
                    {
                        e->reponse[k]=rand() %100;
                    }
                else 
                    {
                        e->reponse[k]=e->vrai_reponse;
                    }
            }
   
   
    }

void afficher_enigme(enigme *e,SDL_Surface *screen)
    {


        TTF_Init();

        TTF_Font *police = NULL;
        police = TTF_OpenFont("resources/sky.jpg", 20);



        Mix_Chunk *music1, *music2;
        Mix_AllocateChannels(1);
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
        {
            printf("%s", Mix_GetError());
        }
        music1 = Mix_LoadWAV("resources/sound/Clic1.wav");
        music2 = Mix_LoadWAV("resources/sound/Clic2.wav");


        int continuer = 1,i,reponse;
        int a,b,c,l;
        a=b=c=0;
        int yes;
        int k=1;

        SDL_Event event;

        e->background=NULL;

        initenigme(e);


        int sa=0,sb=0,sc=0;
        int hb=150,lb=150; 
while(continuer)
    {
      
    	if(SDL_PollEvent(&event))
    	{
    		switch(event.type)
    		{
    			case SDL_QUIT:
                    continuer = 0;
                break;

                case SDL_KEYDOWN:   //keyboard buttons
                switch (event.key.keysym.sym) 
                {
                	case SDLK_F4:
                	continuer = 0;
                	
                	break;
                	
                	case SDLK_RIGHT: //lower arrow
                        if (a == 0 && b == 0 && c == 0)
                        {
                            c = 1;
                            reponse=2;
                            Mix_PlayChannel(-1, music1, 0);
                        }
                        else if (c == 1 && b == 0 && c == 0)
                        {
                            a = 1;
                            c = 0;
                            b = 0;   
                            reponse=0;       
                            Mix_PlayChannel(-1, music1, 0);
                        }
                        else if (a == 1)
                        {
                            b = 1;
                            a = 0;
                            c = 0;
                            reponse=1;
                            Mix_PlayChannel(-1, music1, 0);
                        }
                        else if (b == 1)
                    {
                        b = 0;
                        c = 1;
                        a = 0;
                        reponse=2;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    break;
			/*****************************************************************************************************/
                  case SDLK_LEFT: //lower arrow
                        if (a == 0 && b == 0 && c == 0)
                        {
                            a = 1;
                            reponse=0;
                            Mix_PlayChannel(-1, music1, 0);
                        }
                        else if (a == 1 && b == 0 && c == 0)
                        {
                            c = 1;
                            a = 0;
                            b = 0;  
                            reponse=2;        
                            Mix_PlayChannel(-1, music1, 0);
                        }
                        else if (b == 1)
                        {
                            b = 0;
                            a = 1;
                            reponse=0;
                            Mix_PlayChannel(-1, music1, 0);
                        }
                        else if (c == 1)
                    {
                        c = 0;
                        b = 1;
                        reponse=1;
                        Mix_PlayChannel(-1, music1, 0);
                    }
                    break;
			
                    case SDLK_RETURN:
                        if (e->reponse[reponse] == e->vrai_reponse)
                            {

                                Mix_PlayChannel(-1, music2, 0);
                                SDL_Delay(100);
                                yes=0;
                                continuer=0;
                            }
                        else 
                            yes=1;


                    break;



                //******************************
                case SDL_MOUSEMOTION: //with mouse
                
                a = 0;
                b = 0;
                c = 0;

                if (event.motion.x > e->pos_A.x && event.motion.y > e->pos_A.y && event.motion.x < e->pos_A.x + lb && event.motion.y < e->pos_A.y + hb)
                {

                    a = 1;
                    sa++;
                    if (sa == 1)
                        Mix_PlayChannel(-1, music2, 0);
                    sb = 0;
                    sc = 0;
                    reponse=0;
                   
                }

                if (event.motion.x > e->pos_B.x && event.motion.y > e->pos_B.y && event.motion.x < e->pos_B.x + lb && event.motion.y < e->pos_B.y + hb)
                {
                    b = 1;
                    sb++;
                    if (sb == 1)
                        Mix_PlayChannel(-1, music2, 0);
                    sa = 0;
                    sc = 0;
                     reponse=1;
                }

                if (event.motion.x > e->pos_C.x && event.motion.y > e->pos_C.y && event.motion.x < e->pos_C.x + lb && event.motion.y < e->pos_C.y + hb)
                {
                    c = 1;
                    sc++;
                    if (sc == 1)
                        Mix_PlayChannel(-1, music2, 0);
                    sa = 0;
                    sb = 0;
                    reponse=2;
                }

                break;

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                     if (e->reponse[reponse] == e->vrai_reponse)
                            {

                                Mix_PlayChannel(-1, music2, 0);
                                SDL_Delay(100);
                                yes=0;
                                continuer=0;
                            }
                        else 
                            yes=1;
                   
                }
                break;


                }
                

    		}
    	}

      
    	SDL_BlitSurface(e->background,NULL,screen,&e->background_pos);
    	SDL_BlitSurface(e->buttonA[a],NULL,screen,&e->pos_A);
    	SDL_BlitSurface(e->buttonB[b],NULL,screen,&e->pos_B);
        SDL_BlitSurface(e->buttonC[c],NULL,screen,&e->pos_C);
        SDL_BlitSurface(e->congra[yes],NULL,screen,&e->pos_yes_no);

        SDL_BlitSurface(e->text[0], NULL, screen, &e->pos_reponse1txt);
        SDL_BlitSurface(e->text[1], NULL, screen, &e->pos_reponse2txt);
        SDL_BlitSurface(e->text[2], NULL, screen, &e->pos_reponse3txt);
        SDL_Flip(screen);
        }
   

    Mix_FreeChunk(music1);
    Mix_FreeChunk(music2);
    SDL_FreeSurface(e->background);
    TTF_CloseFont(police);
    for(k=0;k<2;k++)
        {
            SDL_FreeSurface(e->buttonA[k]);
            SDL_FreeSurface(e->buttonB[k]);
            SDL_FreeSurface(e->buttonC[k]);
            SDL_FreeSurface(e->congra[k]);
        }
    

    TTF_CloseFont(police);
    TTF_Quit();
}      
    	
