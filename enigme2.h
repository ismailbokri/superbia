#include <SDL/SDL_image.h>
//#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
typedef struct{
    SDL_Surface *background;
    SDL_Surface *buttonA[2];//repons
    SDL_Surface *buttonB[2];
    SDL_Surface *buttonC[2];
    SDL_Surface *congra[2];
    SDL_Surface *text[3];
 
    int pos_selected;
    SDL_Rect background_pos;
    SDL_Rect pos_A;
    SDL_Rect pos_B;
    SDL_Rect pos_C;
    SDL_Rect pos_yes_no;
    SDL_Rect pos_time;


    int num_question;
    SDL_Rect pos_reponse1txt;
    SDL_Rect pos_reponse2txt;
    SDL_Rect pos_reponse3txt;

    int vrai_reponse;
    int positionVraiReponse;
    int reponse[3];

}enigme;

//test
void initenigme(enigme *e);
void afficher_enigme(enigme *e,SDL_Surface *screen);
void animer(enigme *e);

