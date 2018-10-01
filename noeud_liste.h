#ifndef NOEUD_LISTE
#define NOEUD_LISTE
#include <stdio.h>
#include <stdlib.h>

typedef struct noeud_liste* nd; 


nb creer_noeud(void*,void(*_copier)(void*,void **));
void ajouter_noeud_fin(void*,nd, void(*_copier)(void*,void**));
void supprimer_noeud_fin(nd,void(*_detruire)(void**));
void detruire_tout(nd,void(*_detruire)(void**));


#endif