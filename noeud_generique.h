//
// Created by sophie on 28/08/18.
//

#ifndef UNTITLED_NOEUD_GENERIQUE_H
#define UNTITLED_NOEUD_GENERIQUE_H

struct noeud_generique {
    void* val;
    struct noeud_generique* suivant;
};

typedef struct noeud_generique* nd;

nd creer_noeud_generique(void* _val, void(* _copier)(void*, void**));
void ajouter_noeud_fin(void* _val, nd n, void(* _copier)(void*, void**));
void supprimer_noeud_fin(nd n, void(* _detruire)(void**));
void detruire_n_generique(nd* n, void(* _detruire)(void**));
void afficher_tout_generique(nd n, void(* afficher)(void*));


#endif //UNTITLED_NOEUD_GENERIQUE_H
