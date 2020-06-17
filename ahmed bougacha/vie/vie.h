#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct 
{
	int life;
    SDL_Surface *images[4];
    SDL_Surface *gameover;
    SDL_Rect position;
}Vie;

void InitVie(Vie*v,SDL_Rect pos);
void DisplayVie(Vie *v,SDL_Surface *ecran);
int UpdateVie(Vie *v);



#endif
