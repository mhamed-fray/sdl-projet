#include <stdio.h>
#include <stdlib.h>
#include "score.h"

int main()
{
	SDL_Surface *ecran;
	int continuer=1;
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "Err.\n");
		return 1;
	}
	
	ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_Event event;
	
	SDL_Rect position={0,0};

	Score S;
	InitScore(&S,position);

	while(continuer==1)
	{
		SDL_FillRect(ecran,NULL,0);
		DisplayScore(&S,ecran);
		SDL_Flip(ecran);
		SDL_PollEvent(&event);
		switch (event.type)
		{ 
			case SDL_KEYDOWN:
			{
				if(event.key.keysym.sym==SDLK_RETURN)
				{
					UpdateScore(&S);
				}
				else if(event.key.keysym.sym==SDLK_ESCAPE)
				{
					continuer=0;
				}
				break;
			}
		}
	}
		
	SDL_Quit();
	exit(0);
	return EXIT_SUCCESS;
	return 0;
}

