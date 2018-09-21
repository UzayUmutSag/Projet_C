#include "noeud.h"

struct noeud{
	void* val;
	p_noeud f_droite;
	p_noeud f_gauche;
};

p_noeud creer_noeud (void* elt,void(*_copier)(void*,void**)) {
	p_noeud n = (p_noeud)malloc(sizeof(struct noeud));
	_copier(elt,&(n->val));
	n->f_droite=NULL;
	n->f_gauche=NULL;
	return n;
}

void detruire_tout_noeud (p_noeud* n,void(* _detruire)(void**)){
	if(n!=NULL){
		if((*n)->f_gauche != NULL){
			detruire_tout_noeud(&((*n)->f_gauche),_detruire);
			free((*n)->f_gauche);
			(*n)->f_gauche=NULL;
		}
		if((*n)->f_droite != NULL){
			detruire_tout_noeud(&((*n)->f_droite),_detruire);
			free((*n)->f_droite);
			(*n)->f_droite=NULL;
		}
		_detruire(&((*n)->val));
		free(*n);
		*n=NULL;
	}
}


void afficher_noeud (p_noeud n, void(* _afficher)(void*)){
	if(n==NULL)
		printf("Vide");
	else
	_afficher(n->val);
}

void afficher_tout(p_noeud n,void(*_afficher)(void*)){
	if(n!=NULL){
		_afficher(n->val);
		afficher_tout(n->f_droite,_afficher);
		afficher_tout(n->f_gauche,_afficher);
	}
}