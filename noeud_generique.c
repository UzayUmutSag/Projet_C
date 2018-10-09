//
// Created by sophie on 28/08/18.
//

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "noeud_generique.h"

ndg creer_noeud_generique(void* _val, void(* _copier)(void*, void**)) {
    ndg n = (ndg)malloc(sizeof(struct noeud_generique));
    _copier(_val, &(n->val));
    n->suivant = NULL;
    return n;
}
void ajouter_noeud_fin(void* _val, ndg n, void(* _copier)(void*, void**)) {
    assert(n!=NULL);
    ndg n_add = creer_noeud_generique(_val,_copier);
    ndg tmp = n;
    while (tmp->suivant != NULL)
        tmp = tmp->suivant;
    tmp->suivant = n_add;
}





void supprimer_noeud_fin(ndg n, void(* _detruire)(void**)){
    assert(n!=NULL);
    if (n->suivant == NULL)
        detruire_n_generique(&n,_detruire);
    else {
        ndg tmp = n;
        while (tmp->suivant->suivant!=NULL)
            tmp = tmp->suivant;
        detruire_n_generique(&(tmp->suivant),_detruire);
    }
}

void detruire_n_generique(ndg* n, void(* _detruire)(void**)) {
    if ((*n)!=NULL) {
        if ((*n)->suivant != NULL)
            detruire_n_generique(&((*n)->suivant), _detruire);
        _detruire(&((*n)->val));
        free(*n);
        *n = NULL;
    }
}

void afficher_tout_generique(ndg n, void(* _afficher)(void*)){
    assert (n!=NULL);
    assert (n->val != NULL);
    printf("les valeurs : ");
    ndg tmp = n;
    while(tmp->suivant!=NULL) {
        _afficher(tmp->val);
        tmp = tmp->suivant;
    }
    _afficher(tmp->val);
    printf("\n");
}

void *get_val_noeud(ndg n){
    return n->val;
}

