#include "combinaison.h"

#include <stdio.h>
#include <string.h>

p_comb creer_combinaison (char* l,int o){
	p_comb c =(p_comb) malloc(sizeof(struct combinaison));
	c->lettre = l;
	c->occ = o;
	return c;
}

void supprimer_combinaison (p_comb* c){
	free((*c));
	(*c)=NULL;

}

void afficher_combinaison(p_comb c){
	if(c!=NULL)
		printf("[ %s : %d ]", c->lettre, c->occ);
	else
		printf("Vide\n");
}

int comparer(p_comb a, p_comb b){
	if(a->occ == b->occ)
		return strcmp(a->lettre,b->lettre);
	else
		return a->occ >b->occ ? 1: -1;
}
