//
// Created by sophie on 28/08/18.
//

#ifndef UNTITLED_NOEUD_GENERIQUE_H
#define UNTITLED_NOEUD_GENERIQUE_H

struct noeud_generique {
    void* val;
    struct noeud_generique* suivant;
};

typedef struct noeud_generique* ndg;

ndg creer_noeud_generique(void* _val, void(* _copier)(void*, void**));
void ajouter_noeud_fin(void* _val, ndg n, void(* _copier)(void*, void**));
void supprimer_noeud_fin(ndg n, void(* _detruire)(void**));
void detruire_n_generique(ndg* n, void(* _detruire)(void**));
void afficher_tout_generique(ndg n, void(* afficher)(void*));


#endif //UNTITLED_NOEUD_GENERIQUE_H
