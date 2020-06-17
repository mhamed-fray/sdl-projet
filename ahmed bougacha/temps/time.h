#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
typedef struct 
{
	int currentTime;
	int lastTime;
	int counter;
    SDL_Surface *texte;
    SDL_Rect position;
    TTF_Font *police;
    SDL_Color couleur;
}Time;

void InitTime(Time *t,SDL_Rect pos,int temps);
void DisplayTime(Time *t,SDL_Surface *ecran);
int UpdateTime(Time *t);



#endif
