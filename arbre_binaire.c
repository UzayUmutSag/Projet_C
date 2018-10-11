#include "arbre_binaire.h"


p_arbre creer_arbre(void * elt,void(*_copier)(void*,void**),void* (*_fusion)(void*,void*),	void (*_afficher)(void*),int(*_compare)(void*,void*),void (*_detruire)(void**),int (*_existe)(void*,void*)){
	p_arbre a = (p_arbre)malloc(sizeof(struct arbre));
	a->racine = creer_noeud(elt,_copier);
	a->_copier=_copier;
	a->_afficher=_afficher;
	a->_detruire= _detruire;
	a->_compare=_compare;
	a->_existe = _existe;
	a->_fusion = _fusion;
	return a;
}


void detruire_tout(p_arbre* a){
	detruire_tout_noeud(&(*((p_arbre*)a))->racine,(*((p_arbre*)a))->_detruire);
	free(*a);
	*a=NULL;
}

void afficher_arbre(void* a){
	if(a!=NULL){
		afficher_tout(((p_arbre)a)->racine,((p_arbre)a)->_afficher);
	}else{
		printf("vide\n");
	}
}



p_arbre fusion_arbre(p_arbre * a1,p_arbre * a2){
	p_arbre res_fusion;
	if((*a1)->_compare(  get_valeur((*a1)->racine) , get_valeur((*a2)->racine)) <= 0) {
		void* comb_fus = (*a1)->_fusion(get_valeur((*a1)->racine),get_valeur((*a2)->racine));
		res_fusion = creer_arbre(  &comb_fus , (*a1)->_copier,(*a1)->_fusion,(*a1)->_afficher,(*a1)->_compare,(*a1)->_detruire,(*a1)->_existe);
		ajouter_fils_gauche(&(res_fusion->racine),&((*a1)->racine));
		ajouter_fils_droite(&(res_fusion->racine),&((*a2)->racine));
	}else{
		void* comb_fus = (*a1)->_fusion(get_valeur((*a2)->racine),get_valeur((*a1)->racine));
		res_fusion = creer_arbre(  &comb_fus , (*a1)->_copier,(*a1)->_fusion,(*a1)->_afficher,(*a1)->_compare,(*a1)->_detruire,(*a1)->_existe);
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

int existe_arbre(void* elt, p_arbre a){
	if(a!=NULL)
		return existe_noeud(elt,a->racine,a->_existe);
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


char* codeprefixe (p_arbre a,void* elt){
	if(existe_arbre(elt,a)){
		char* code = (char*)malloc(hauteur_arbre(a)*sizeof(char));
		return codeprefixe_noeud(a->racine,elt,code,a->_existe);
	}else{
		return NULL;
	}
}

int comparer_arbre(p_arbre a1,p_arbre a2){
	return comparer_noeud(a1->racine,a2->racine,a2->_compare);
	//return ((*((p_arbre*)a1))->_compare)(  (*((p_arbre*)a1))->racine , ((p_arbre)a2)->racine   );
}

/*void _copier(void* _val, void** ptr){
	(*ptr)=creer_combinaison(   (*((p_comb*)(_val)))->lettre , (*((p_comb*)(_val)))->occ  );
	supprimer_combinaison( (p_comb*) _val);
}*/

void copier_arbre (void* a,void** ptr){
	(*ptr) = (*((p_arbre*)a));
	(a)=NULL;
}

int comparer_arbre_liste(void * a,void * b){
	 return comparer_arbre(  (*((p_arbre*)a)) , ((p_arbre)b)   );
}


void * parcourir_arbre(p_arbre a, char* code,int* i){
	if(a!=NULL && code !=NULL){
		return parcourir_noeud(a->racine,code,i);
	}
	return NULL;
}