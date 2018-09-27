#ifndef NOEUD_H
#define NOEUD_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define max(a,b) (a>=b?a:b)

typedef struct noeud* p_noeud;

p_noeud creer_noeud (void* elt,void(*_copier)(void*,void**)) ;

void detruire_tout_noeud (p_noeud* n,void(* _detruire)(void**));

void afficher_noeud (p_noeud n, void(* _afficher)(void*));

void afficher_tout(p_noeud,void(*_afficher)(void*));

void* get_valeur(p_noeud n);

p_noeud get_fils_droite (p_noeud n);

p_noeud get_fils_gauche (p_noeud n);

void ajouter_fils_droite(p_noeud *racine,p_noeud *n);

void ajouter_fils_gauche(p_noeud *racine,p_noeud *n);

int hauteur_noeud(p_noeud n);


#endif