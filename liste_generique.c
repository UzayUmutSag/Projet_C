#include <stdio.h>
#include <stdlib.h>
#include "liste_generique.h"

lst creer_liste(void(*_copier)(void*, void**), void(*_detruire)(void**), void(*_afficher)(void*),int(*_comparer)(void*,void*)) {
    lst l = (lst)malloc(sizeof(struct liste));
    l->tete = NULL;
    l->copier = _copier;
    l->detruire = _detruire;
    l->afficher = _afficher;
    l->comparer = _comparer;
    l->taille = 0;
    return l;
}

/*void ajouter_liste_fin(void* _val,lst l) {
    nd n = creer_noeud_generique(_val ,l->copier);
    if (l->tete==NULL) {
        l->tete=n;        
    }else{
        nd tmp=(l->tete);
        while(tmp->suivant!=NULL)
            tmp=tmp->suivant;
        tmp->suivant=n;
        l->taille++;
    }
}*/

void ajouter_liste_tri(void* _val,lst l){
    nd n_add=creer_noeud_generique(_val,l->copier);
    if(l->tete==NULL){
        (l->tete) = n_add;
    }else{
        if((l->comparer)(_val,(l->tete)->val)<=0){
            n_add->suivant=(l->tete);
            (l->tete)=n_add;
        }else{
            if((l->tete)->suivant==NULL)
                (l->tete)->suivant=n_add;
            else{
                nd tmp=(l->tete);
                nd tmp_s=tmp->suivant;
                while(tmp->suivant!=NULL && (l->comparer)(_val,(tmp->suivant)->val)>0){
                    tmp=tmp_s;
                    tmp_s=tmp_s->suivant;
                }
                tmp->suivant=n_add;
                n_add->suivant=tmp_s;
            }
        }
    }
    l->taille++;
}

void detruire_liste(lst* l) {
    detruire_n_generique(&((*l)->tete),(*l)->detruire);
    free(*l);
    (*l)=NULL;
}
void afficher_liste(lst l) {
    afficher_tout_generique(l->tete,l->afficher);
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
