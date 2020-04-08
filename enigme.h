#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED

void deplacement_selection(int* choix, int* x, int* son, int* continuer);
void update_affichage(int choix, int x, int son, SDL_Rect positionEnigme, SDL_Surface* ecran, SDL_Surface* imageDeFond, SDL_Surface*enigme,SDL_Rect positionFond);
void affichage_enigmes(SDL_Surface *question,SDL_Surface *r1, SDL_Surface *r2,SDL_Surface *r3,SDL_Surface *r4);
void validation(int choix, int ligne, int reponse[]);

#endif // ENIGME_H_INCLUDED
