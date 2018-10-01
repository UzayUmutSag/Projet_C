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

p_arbre fusion_arbre(p_arbre * a1,p_arbre * a2,void*(*_fusion)(void*, void*),int (*_comparer)(void* c1, void* c2),void (*_copier)(void* _val, void** ptr) );

int hauteur_arbre(p_arbre a);

int existe_arbre(void*, p_arbre,int(*_compare)(void*,void*));
int nb_branches(p_arbre);
int nb_feuilles(p_arbre);

char* codeprefixe (p_arbre,void*,int(*_compare)(void*,void*));


#endif