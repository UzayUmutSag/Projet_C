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
		printf("[ %s : %d ]\n", c->lettre, c->occ);
	else
		printf("Vide\n");
}

int comparer_combinaison(p_comb a, p_comb b){
    if(a->occ == b->occ)
            return strcmp(a->lettre, b->lettre);
    else
            return a->occ > b->occ ? 1 : -1;

}

p_comb fusion_combinaison(p_comb a, p_comb b){
	int taille = strlen(a->lettre)+strlen(b->lettre);
	char* l =(char*)malloc(sizeof(taille));
	int o;
	sprintf(l,"%s%s",a->lettre,b->lettre);
	o=(a->occ)+(b->occ);
	p_comb res=creer_combinaison(l,o);
	return res;
}
