#include"time.h"

void InitTime(Time *t,SDL_Rect pos,int temps)
{
	t->lastTime=0;
	t->currentTime=0;
	t->counter=temps;
	t->position.x=pos.x;
	t->position.y=pos.y;

	t->police = TTF_OpenFont("arial.ttf", 50);
	t->couleur.r=255;
	t->couleur.b=255;
	t->couleur.g=255;

	char time[20];
	sprintf(time, "Temps : %d", t->counter);
	t->texte = TTF_RenderText_Blended(t->police,time,t->couleur);
}

void DisplayTime(Time *t,SDL_Surface *ecran)
{
    SDL_BlitSurface(t->texte,NULL,ecran,&t->position);
    SDL_Flip(ecran);
    SDL_Delay(10);
}

int UpdateTime(Time *t)
{
	t->currentTime = SDL_GetTicks();
    if (t->currentTime - t->lastTime >= 1000) /* Si 1000ms au moins se sont écoulées */
   	{
        t->counter -= 1; /* On rajoute 100ms au compteur */
     	char time[20];
		sprintf(time, "Temps : %d", t->counter);
		SDL_FreeSurface(t->texte); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
    	t->texte = TTF_RenderText_Blended(t->police,time,t->couleur);

        t->lastTime = t->currentTime; /* On met à jour le tempsPrecedent */
		if(t->counter == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	return 1;
}
