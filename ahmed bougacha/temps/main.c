#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include "time.h"

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

	TTF_Init();//initialisation de TTF
	
	SDL_Rect position={100,0};
	int temps=20;

	Time T;
	InitTime(&T,position,temps);
	while(continuer==1)
	{
		SDL_FillRect(ecran,NULL,0);
		DisplayTime(&T,ecran);
		continuer=UpdateTime(&T);
		SDL_PollEvent(&event);
		switch (event.type)
		{ 
			case SDL_KEYDOWN:
			{
				if(event.key.keysym.sym==SDLK_ESCAPE)
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

