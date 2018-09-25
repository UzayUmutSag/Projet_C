#include "combinaison.h"

#include <stdio.h>
#include <string.h>

p_comb creer_combinaison (char* l,int o){
	p_comb c =(p_comb) malloc(sizeof(struct combinaison));
	c->lettre = (char*)malloc(sizeof(strlen(l))*sizeof(char));
	memcpy(c->lettre,l,sizeof(strlen(l)*sizeof(char)));
	c->occ = o;
	return c;
}

void supprimer_combinaison (p_comb* c){
	free((*c)->lettre);
	(*c)->lettre = NULL;
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
	int taille = (int)strlen(a->lettre)+strlen(b->lettre);
	char * l = (char*) malloc(sizeof(taille)*sizeof(char));
	strcpy(l,a->lettre);
	strcat(l,b->lettre);
	int o = a->occ+b->occ;
	p_comb res = creer_combinaison(l,o);
	free(l);
	return res;
}

p_comb copier_combinaison(p_comb comb){
	p_comb b = (p_comb)malloc(sizeof(struct combinaison));
	b=creer_combinaison(comb->lettre,comb->occ);
	return b;
}
