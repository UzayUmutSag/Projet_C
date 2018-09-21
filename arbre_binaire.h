#ifndef ARBRE_H
#define ARBRE_H 

#include "noeud.h"

struct arbre{
	p_noeud racine;
};

typedef struct arbre* p_arbre;
p_arbre creer_arbre(void * elt,void(*_copier)(void*,void**));
void detruire_tout(p_arbre* a, void(*_detruire)(void**));
void afficher_arbre(p_arbre a , void(*_afficher)(void*));

#endif