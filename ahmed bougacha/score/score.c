#include"score.h"

void InitScore(Score *s,SDL_Rect pos)
{
	s->score=0;
    for(int i=0;i<6;i++){
    	char str[30];
    	sprintf(str,"%d.png",i);
    	s->images[i]=IMG_Load(str);
    }
	s->position.x=pos.x;
	s->position.y=pos.y;
}

void DisplayScore(Score *s,SDL_Surface *ecran)
{
    SDL_BlitSurface(s->images[s->score],NULL,ecran,&s->position);
    SDL_Flip(ecran);
    SDL_Delay(10);
}

void UpdateScore(Score *s)
{
	s->score++;
	if(s->score>5){
		s->score=5;
	}
}
