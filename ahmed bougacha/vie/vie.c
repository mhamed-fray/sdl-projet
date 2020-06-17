#include"vie.h"

void InitVie(Vie *v,SDL_Rect pos)
{
	v->life=3;
    for(int i=1;i<4;i++){
    	char str[30];
    	sprintf(str,"v%d.png",i);
    	v->images[i]=IMG_Load(str);
    }
    v->gameover=IMG_Load("gameover.jpg");
	v->position.x=pos.x;
	v->position.y=pos.y;
}

void DisplayVie(Vie *v,SDL_Surface *ecran)
{
    if(v->life==0){
        SDL_BlitSurface(v->gameover,NULL,ecran,NULL);
        SDL_Flip(ecran);
        SDL_Delay(2000);
    }
    else{
        SDL_BlitSurface(v->images[v->life],NULL,ecran,&v->position);
        SDL_Flip(ecran);
        SDL_Delay(10);
    }
    
}

int  UpdateVie(Vie *v)
{
	v->life--;
	if(v->life==0){
		return 0;
	}
    else{
        return 1;
    }
}
