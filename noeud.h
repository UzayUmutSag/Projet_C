#ifndef NOEUD_H
#define NOEUD_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct noeud* p_noeud;

p_noeud creer_noeud (void* elt,void(*_copier)(void*,void**)) ;

void detruire_tout_noeud (p_noeud* n,void(* _detruire)(void**));

void afficher_noeud (p_noeud n, void(* _afficher)(void*));

void afficher_tout(p_noeud,void(*_afficher)(void*));

void* get_valeur(p_noeud);

int existe_noeud(void* elt, p_noeud n,int(*_compare)(void*,void*));

int nb_branches_noeud(p_noeud);

int nb_feuilles_noeud(p_noeud);

#endif