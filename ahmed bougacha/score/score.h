#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct 
{
	int score;
    SDL_Surface *images[6];
    SDL_Rect position;
}Score;

void InitScore(Score *s,SDL_Rect pos);
void DisplayScore(Score *s,SDL_Surface *ecran);
void UpdateScore(Score *s);



#endif
