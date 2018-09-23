#ifndef COMBINAISON_H
#define COMBINAISON_H

#include <stdlib.h>


struct combinaison{
	char* lettre;
	int occ;
};

typedef struct combinaison* p_comb;

p_comb creer_combinaison (char* l,int o);

void supprimer_combinaison (p_comb* c);

void afficher_combinaison(p_comb c);

int comparer(p_comb,p_comb);

#endif