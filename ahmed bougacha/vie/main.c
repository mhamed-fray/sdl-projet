#include <stdio.h>
#include <stdlib.h>
#include "vie.h"

int main()
{
	SDL_Surface *ecran;
	int continuer=1;
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "Err.\n");
		return 1;
	}
	
	ecran = SDL_SetVideoMode(1300, 1082, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_Event event;
	
	SDL_Rect position={0,0};

	Vie V;
	InitVie(&V,position);

	while(continuer==1)
	{
		SDL_PollEvent(&event);
		switch (event.type)
		{ 
			case SDL_KEYDOWN:
			{
				if(event.key.keysym.sym==SDLK_RETURN)
				{
					continuer=UpdateVie(&V);
				}
				else if(event.key.keysym.sym==SDLK_ESCAPE)
				{
					continuer=0;
				}
				break;
			}
		}
		SDL_FillRect(ecran,NULL,0);
		DisplayVie(&V,ecran);
		SDL_Flip(ecran);
	}
		
	SDL_Quit();
	exit(0);
	return EXIT_SUCCESS;
	return 0;
}

