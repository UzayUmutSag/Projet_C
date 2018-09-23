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

int existe_arbre(void* elt, p_arbre a,int(*_compare)(void*,void*)){
	if(a!=NULL)
		return existe_noeud(elt,a->racine,_compare);
	return 0;
}

int nb_branches(p_arbre a){
	if(a!=NULL) return nb_branches_noeud(a->racine);
	return 0;
}

int nb_feuilles(p_arbre a){
	if(a!=NULL) return nb_feuilles_noeud(a->racine);
	return 0;
}