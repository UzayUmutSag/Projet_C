#ifndef ARBRE_H
#define ARBRE_H 

#include "noeud.h"

struct arbre{
	p_noeud racine;
	void (*_copier)(void*,void**);
	void* (*_fusion)(void*,void*);
	void (*_afficher)(void*);
	int (*_compare)(void*,void*);
	void (*_detruire)(void**);
	int (*_existe)(void*,void*);
};

typedef struct arbre* p_arbre;
p_arbre creer_arbre(void * elt,void(*_copier)(void*,void**),void* (*_fusion)(void*,void*),void (*_afficher)(void*),int (*_compare)(void*,void*),void (*_detruire)(void**),int (*_existe)(void*,void*));
void detruire_tout(void** a);

void afficher_arbre(void* a);


p_arbre fusion_arbre(p_arbre * a1,p_arbre * a2);

int hauteur_arbre(p_arbre a);
int comparer_arbre(p_arbre,p_arbre);

int existe_arbre(void*, p_arbre);
int nb_branches(p_arbre);
int nb_feuilles(p_arbre);

char* codeprefixe (p_arbre,void*);

void copier_arbre (void* a,void** ptr);

int comparer_arbre_liste(void * a,void * b);


void * parcourir_arbre(p_arbre a, char* code,int*);


#endif