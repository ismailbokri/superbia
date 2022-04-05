#ifndef Text_H
#define Text_H


#include <stdio.h>
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h> 


typedef struct 
{
   SDL_Surface * miniture;
   SDL_Rect posminimap;
   SDL_Surface * bonhomme;
   SDL_Rect posbonhomme; 
}minimap;

void initminimap( minimap * m); //init minimap 
void afficherminimap (minimap m, SDL_Surface * screen); //-------
void MAJMinimap(SDL_Rect posJoueur , minimap * m, SDL_Rect camera, int redimensionnement);//mise a jour !!!!
void Liberer (minimap * m);// libirer 
void sauvegarder( int score, char nomjoueur[], char nomfichier[]); //fichier +clavier 
void meilleur( char nomfichier[], int *score, char nomjoueur[]); // trie afficher le premier top1


#endif  

