#include "arbre_binaire.h"


p_arbre creer_arbre(void * elt,void(*_copier)(void*,void**)){
	p_arbre a = (p_arbre)malloc(sizeof(struct arbre));
	a->racine = creer_noeud(elt,_copier);
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



p_arbre fusion_arbre(p_arbre * a1,p_arbre * a2,void*(*_fusion)(void*, void*),int (*_comparer)(void* c1, void* c2),void (*_copier)(void* _val, void** ptr) ){
	p_arbre res_fusion;
	if(_comparer(  get_valeur((*a1)->racine) , get_valeur((*a2)->racine)  ) <= 0) {
		void* comb_fus = _fusion(get_valeur((*a1)->racine),get_valeur((*a2)->racine));
		res_fusion = creer_arbre(  &comb_fus ,  _copier   );
		ajouter_fils_gauche(&(res_fusion->racine),&((*a1)->racine));
		ajouter_fils_droite(&(res_fusion->racine),&((*a2)->racine));
	}else{
		void* comb_fus = _fusion(get_valeur((*a2)->racine),get_valeur((*a1)->racine));
		res_fusion = creer_arbre(   &comb_fus  ,  _copier   );
		ajouter_fils_gauche(&(res_fusion->racine),&((*a2)->racine));
		ajouter_fils_droite(&(res_fusion->racine),&((*a1)->racine));
	}
	(*a1)->racine = NULL;
	(*a2)->racine = NULL;
	free(*a1);
	free(*a2);
	(*a1)=NULL;
	(*a2)=NULL;
	return res_fusion;
}

int hauteur_arbre(p_arbre a){
	if(a!=NULL){
		return hauteur_noeud(a->racine);
	}else{
		return 0;
	}
}

int existe_arbre(void* elt, p_arbre a,int(*_compare)(void*,void*)){
	if(a!=NULL)
		return existe_noeud(elt,a->racine,_compare);
	return 0;
}

int nb_branches(p_arbre a){
	if(a!=NULL) return nb_branches_noeud(a->racine);
	return 0;
}

int nb_feuilles(p_arbre a){
	if(a!=NULL) return nb_feuilles_noeud(a->racine);
	return 0;
}


int* codeprefixe (p_arbre a,void* elt,int(*_compare)(void*,void*)){
	if(existe_arbre(elt,a,_compare)){
		int* code = (int*)malloc(hauteur_arbre(a)*sizeof(int)-1);
		for(int i =0; i < hauteur_arbre(a)-1;i++){
			code[i]=0;
		}
		return codeprefixe_noeud(a->racine,elt,code,_compare);
	}else{
		return NULL;
	}
}
