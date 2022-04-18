#include "header.h"
#include "text.h"
void InitEnigme(enigme * e, char *nomfichier)
{
    int x;
    int i=0,j=0 ;
    
    srand(time(0));
    x=(rand() % (3)) +1;


    FILE *F;
    int nb=x+2;
    F=fopen(nomfichier, "r");
    if(F!=NULL)
    {
        while(nb!=0)
        {
            fscanf(F,"%s %d\n",e->mazesmall,&(e->reponse));

            if(nb>3)
            {
                nb--;
            }
            else
            {
                e->maze[i]=IMG_Load( e->mazesmall) ;
printf("%d",e->reponse);
                e->r[j]= e->reponse;
                j++;
                i++;
                nb--;
            }
        }
    }
    fclose(F);

    e->timer[0] =IMG_Load("timer/0.gif");
    e->timer[1] =IMG_Load("timer/1.gif");
    e->timer[2] =IMG_Load("timer/2.gif");
    e->timer[3] =IMG_Load("timer/3.gif");
    e->timer[4] =IMG_Load("timer/4.gif");
    e->timer[5] =IMG_Load("timer/5.gif");
    e->timer[6] =IMG_Load("timer/6.gif");
    e->timer[7] =IMG_Load("timer/7.gif");
    e->timer[8] =IMG_Load("timer/8.gif");
    e->timer[9] =IMG_Load("timer/9.gif");

    e->postimer.x = 1150;
    e->postimer.y= 0;


    for(i=0; i<10; i++)
    {
        if (e->timer[i]==NULL)
        {
            printf ("erreurtimer");
            return ;
        }


    }
    e->back =IMG_Load("m.png");
    if (e->back==NULL)
    {
        printf ("erreurback");
        return ;
    }
    e->posback.x = 0 ;
    e->posback.y = 0;




    for(i=0; i<3; i++)
    {
    

        if (e->maze[i]==NULL)
        {
                printf("error2 : %s\n",SDL_GetError());
            printf ("erreurmaze");
            return ;
        }



    }
    			e->posmaze[0].x = 150;
    			e->posmaze[0].y = 150;


                    e->posmaze[1].x = 500 ;
                    e->posmaze[1].y = 170;

                    e->posmaze[2].x = 900;
                    e->posmaze[2].y = 150;

                   

     }

     void afficherEnigme(enigme e, SDL_Surface * screen)
{
    SDL_BlitSurface (e.back,NULL,screen,&e.posback);
    SDL_BlitSurface (e.maze[0],NULL,screen,&e.posmaze[0]);
    SDL_BlitSurface (e.maze[1],NULL,screen,&e.posmaze[1]);
    SDL_BlitSurface (e.maze[2],NULL,screen,&e.posmaze[2]);

}

void animer (enigme *e)
{
    TTF_Init();
//      *************************INITIALISATION*************************
    SDL_Surface *screen ;
    SDL_Event event;

text A;
    int cont = 1;
    int t=0,choix=0;
    char cc[20];
    text tt;
    time_t start,end;
    start=clock();
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Unable to initialisation SDL : %s\n",SDL_GetError());
    }
    SDL_WM_SetCaption("ENIGME",NULL);
    screen = SDL_SetVideoMode(1245,750,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (screen == NULL)
    {
        printf("error2 : %s\n",SDL_GetError());
    }


A.position.x=1200;
    A.position.y=15;
// couleur noir
    A.textColor.r=255;
    A.textColor.g=255;
    A.textColor.b=255;

    A.font = TTF_OpenFont( "police.ttf", 20 );





//      *************************BOUCLE*************************

    while (cont)
    {

        sprintf(cc, ":0%d", t);
        
       afficherEnigme(*e, screen);
          SDL_BlitSurface (e->timer[t],NULL,screen,&e->postimer);
 A.surfaceTexte = TTF_RenderText_Solid(A.font, cc, A.textColor );
    SDL_BlitSurface(A.surfaceTexte, NULL, screen,&A.position);
        
        end=clock();
        t=(end-start)/CLOCKS_PER_SEC;

        if(t==10)
        {
            cont=0;
            e->reponsejuste=0;
        }

SDL_PollEvent(&event);

        if ((event.type == SDL_QUIT)||(event.key.keysym.sym == SDLK_ESCAPE))
            cont = 0;
        SDL_Flip(screen);
        


        switch(event.type)
        {

        case SDL_KEYDOWN:

            switch(event.key.keysym.sym)
            {


            case SDLK_a:
                choix=1;
                break;
            case SDLK_q:
                choix=1;
                break;
            case SDLK_b:
                choix=2;
                break;
            case SDLK_c:
                                choix=3;
                break;
                case SDLK_SPACE:
                        cont=0;
                break;
            }
            break;
        case SDL_MOUSEMOTION:



            if (event.motion.x>170&& event.motion.y>350 && event.motion.x<380&& event.motion.y<600)

                choix=1;

            if (event.motion.x>520&& event.motion.y>350 && event.motion.x<710&& event.motion.y<600)

                choix=2;

            if (event.motion.x>880&& event.motion.y>350 && event.motion.x<1090&& event.motion.y<600)

                choix=3;

            break;
            case SDL_MOUSEBUTTONDOWN
             
            if (event.button.button==SDL_BUTTON_LEFT)
            {
		cont=0;
                }
        }
}
printf("\n%d\n",e->r[choix-1]);
        e->reponsejuste=e->r[choix-1];
        }

