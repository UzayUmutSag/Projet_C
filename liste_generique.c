//
// Created by sophie on 29/08/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "noeud_generique.h"
#include "liste_generique.h"

lst creer_liste(void(*_copier)(void*, void**), void(*_detruire)(void**), void(*_afficher)(void*),void(*_comparer)(void*,void*)) {
    lst l = (lst)malloc(sizeof(struct liste));
    l->tete = NULL;
    l->queue = NULL;
    l->copier = _copier;
    l->detruire = _detruire;
    l->afficher = _afficher;
    l->comaprer = _comparer;
    l->taille = 0;
    return l;
}

void ajouter_liste_fin(void* _val,lst l) {
    nd n = creer_noeud(_val,l->copier);
    if (l->tete==NULL) {
        l->tete = n;
        l->queue = n;
    }
    else {
        (l->queue)->suivant = n;
        (l->queue) = (l->queue)->suivant;
    }
    l->taille++;
}

void ajouter_liste_tri(void* _val,lst l){
    nd n = creer_noeud(_val,l->copier);
    if(l->tete == NULL){
        l->tete = n;
        l->queue = n;
    }else{
        nd p = l->tete;
        nd s = (l->tete)->suivant;
        if(l->comaprer(p->val,n->val)<=0){
            n->suivant=p;
            l->tete=n;
        }else{
            while(s->suivant != NULL){
                
            }
        }
    }
}



void supprimer_liste_fin(lst l){
    nd tmp = l->tete;
    if (l->tete==l->queue)
        detruire_liste(&l);
    else {
        while (tmp->suivant != l->queue)
            tmp = tmp->suivant;
        detruire_tout(&(l->queue), l->detruire);
        tmp->suivant = NULL;
        l->queue = tmp;
    }
}
void detruire_liste(lst* l) {
    detruire_tout(&((*l)->tete),(*l)->detruire);
    free(*l);
    (*l)=NULL;
}
void afficher_liste(lst l) {
    afficher_tout(l->tete,l->afficher);
}

void* rechercher_max_liste(lst l,int(*_comparer)(void* _val1, void* _val2)) {
    nd tmp = l->tete;
    void *max = tmp->val;
    for (int i = 1; i < l->taille; i++) {
      tmp = tmp->suivant;
      int cmp = _comparer(tmp->val,max);
      if ( cmp >= 1)
	max = tmp->val;
    }
    return max;
}
