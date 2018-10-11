#include "combinaison.h"

#include <stdio.h>
#include <string.h>

p_comb creer_combinaison (char* l,int o){
	p_comb c =(p_comb) malloc(sizeof(struct combinaison));
	int i = strlen(l);
	c->lettre = (char*)malloc(i*sizeof(char)+1);
	strcpy(c->lettre,l);
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
    if(a->occ > b->occ){
    	return 1;
    }else if (a->occ < b->occ){
    	return -1;
    }else{
    	return strcmp(a->lettre, b->lettre);
    }
}

p_comb fusion_combinaison(p_comb a, p_comb b){
	int taille = strlen(a->lettre)+strlen(b->lettre);
	char * l = (char*) malloc(taille+1);
	strcpy(l,a->lettre);
	strcat(l,b->lettre);
	int o = a->occ+b->occ;
	p_comb res = creer_combinaison(l,o);
	free(l);
	return res;
}

p_comb copier_combinaison(p_comb comb){
	return creer_combinaison(comb->lettre,comb->occ);
}

char* get_lettre(p_comb comb){
	char * c = (char*)malloc(sizeof(char)*(strlen(comb->lettre)+1));
	strcpy(c,comb->lettre);
	return c;
}

int get_occ(p_comb comb){
	return comb->occ;
}
