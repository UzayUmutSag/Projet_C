//
// Created by sophie on 29/08/18.
//

#ifndef UNTITLED_LISTE_GENERIQUE_H
#define UNTITLED_LISTE_GENERIQUE_H

#include "noeud_generique.h"


struct liste {
    int taille;
    nd tete;
    void(*copier)(void*, void**);
    void(*detruire)(void**);
    void(*afficher)(void*);
    int(*comparer)(void*,void*);
};

typedef struct liste* lst;

lst creer_liste(void(*_copier)(void*, void**), void(*_detruire)(void**), void(*_afficher)(void*),int(*_comparer)(void*,void*));

//void ajouter_liste_fin(void* _val,lst l);
void detruire_liste(lst* l);
void afficher_liste(lst l);
void ajouter_liste_tri(void*,lst);


void* rechercher_max_liste(lst l,int(*_comparer)(void* _val1, void* _val2));

#endif //UNTITLED_LISTE_GENERIQUE_H
