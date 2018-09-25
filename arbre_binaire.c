#include "arbre_binaire.h"


p_arbre creer_arbre(void * elt,void(*_copier)(void*,void**)){
	p_arbre a = (p_arbre)malloc(sizeof(struct arbre));
	a->racine = creer_noeud(elt,*_copier);
	return a;
}


void detruire_tout(p_arbre* a, void(*_detruire)(void**)){
	detruire_tout_noeud(&(*a)->racine,_detruire);
	free(*a);
	*a=NULL;
}

void afficher_arbre(p_arbre a , void(*_afficher)(void*)){
	if(a!=NULL){
		afficher_tout(a->racine,_afficher);
	}else{
		printf("vide\n");
	}
}

p_arbre fusion_arbre (p_arbre a1,p_arbre a2,void*(*_fusion)(void*, void*),void(*_copier)(void*,void**),int (*_comparer)(void*, void*)){
	p_arbre res = creer_arbre(   _fusion(get_valeur(a1->racine),get_valeur(a2->racine))   ,   *_copier   );
	if(_comparer(get_valeur(a1->racine),get_valeur(a2->racine))<0){
		ajouter_fils_droite(&res->racine,&a2->racine);
		ajouter_fils_gauche(&res->racine,&a1->racine);
	}else{
		ajouter_fils_droite(&res->racine,&a1->racine);
		ajouter_fils_gauche(&res->racine,&a2->racine);
	}

	return res;
}