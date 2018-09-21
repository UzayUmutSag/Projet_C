#include "arbre_binaire.h"


p_arbre creer_arbre(void * elt,void(*_copier)(void*,void**)){
	p_arbre a = (p_arbre)malloc(sizeof(struct arbre));
	a->racine = creer_noeud(elt,*_copier);
	return a;
}


void detruire_tout(p_arbre* a, void(*_detruire)(void**)){
	detruire_tout_noeud(&(*a)->racine,_detruire);
	free(*a);
	*a=NULL;
}

void afficher_arbre(p_arbre a , void(*_afficher)(void*)){
	if(a!=NULL){
		afficher_noeud(a->racine,_afficher);
	}
}