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


int comparer_combinaison(p_comb a, p_comb b);

p_comb fusion_combinaison(p_comb a, p_comb b);

p_comb copier_combinaison(p_comb);

char* get_lettre(p_comb comb);

int get_occ(p_comb comb);


#endif