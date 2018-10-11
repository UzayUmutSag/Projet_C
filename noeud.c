#include "noeud.h"

struct noeud{
	void* val;
	p_noeud f_droite;
	p_noeud f_gauche;
};

p_noeud creer_noeud (void* elt,void(*_copier)(void*,void**)) {
	p_noeud n = (p_noeud)malloc(sizeof(struct noeud));
	_copier(elt,&(n->val));
	n->f_droite=NULL;
	n->f_gauche=NULL;
	return n;
}

void detruire_tout_noeud (p_noeud* n,void(* _detruire)(void**)){
	if(n!=NULL){
		if((*n)->f_gauche != NULL){
			detruire_tout_noeud(&((*n)->f_gauche),_detruire);
			free((*n)->f_gauche);
			(*n)->f_gauche=NULL;
		}
		if((*n)->f_droite != NULL){
			detruire_tout_noeud(&((*n)->f_droite),_detruire);
			free((*n)->f_droite);
			(*n)->f_droite=NULL;
		}
		_detruire(&((*n)->val));
		free(*n);
		*n=NULL;
	}
}


void afficher_noeud (p_noeud n, void(* _afficher)(void*)){
	if(n==NULL)
		printf("Vide");
	else
	_afficher(n->val);
}

void afficher_tout(p_noeud n,void(*_afficher)(void*)){
	if(n!=NULL){
		_afficher(n->val);
		afficher_tout(n->f_gauche,_afficher);
		afficher_tout(n->f_droite,_afficher);
	}
}

void* get_valeur(p_noeud n){
	return n->val;
}


p_noeud get_fils_droite (p_noeud n){
	return n->f_droite;
}

p_noeud get_fils_gauche (p_noeud n){
	return n->f_gauche;
}

void ajouter_fils_droite(p_noeud *racine,p_noeud *n){
	(*racine)->f_droite=(*n);
}

void ajouter_fils_gauche(p_noeud *racine,p_noeud *n){
	(*racine)->f_gauche=(*n);
}

int hauteur_noeud(p_noeud n){
	if(n!=NULL){
		return 1+(max ( hauteur_noeud(n->f_gauche) , hauteur_noeud(n->f_droite) ));
	}else{
		return 0;
	}
}


int existe_noeud(void* elt, p_noeud n,int(*_compare)(void*,void*)){
	if(n!=NULL){
		int i = _compare(elt,get_valeur(n));
		if(i==0){
				i= existe_noeud(elt,n->f_droite,_compare) + existe_noeud(elt,n->f_gauche,_compare);	
		}
		return i;
	}
	return 0;
}

int nb_branches_noeud(p_noeud n){
	if(n==NULL)
		return 0;
	else{
		int i = 0;
		if(n->f_droite != NULL)
			i=1+nb_branches_noeud(n->f_droite);
		if(n->f_gauche != NULL)
			i=1+nb_branches_noeud(n->f_gauche);
		return i;
	} 
		

}

int nb_feuilles_noeud(p_noeud n){
	if(n==NULL) return 0;
	if(n->f_droite == NULL && n->f_gauche == NULL)
		return 1;
	else
		return nb_feuilles_noeud(n->f_droite)+nb_feuilles_noeud(n->f_gauche);
}

char* codeprefixe_noeud (p_noeud n,void* elt , char *code, int(*_compare)(void*,void*)){
	p_noeud fd = get_fils_droite(n);
	p_noeud fg = get_fils_gauche(n);
	if(fd&&existe_noeud(elt,fd,_compare)!=0){
		(*code)='1';
		codeprefixe_noeud(fd,elt,(code+1),_compare);
	}else if(fg&&existe_noeud(elt,fg,_compare)!=0){
		(*code)='0';
		codeprefixe_noeud(fg,elt,(code+1),_compare);
	}else{
		*(code)='\0';
	}
	return code;
}

int comparer_noeud(p_noeud n1,p_noeud n2,int (*_compare)(void*,void*)){
	return _compare(n1->val,n2->val);
}



void* parcourir_noeud(p_noeud n, char* code, int* i){
	if(n!=NULL&&code!=NULL){
		p_noeud fd = get_fils_droite(n);
		p_noeud fg = get_fils_gauche(n);
		if(fg!=NULL && fd!=NULL){
			if(*code=='0'){
				(*i)+=1;
				return parcourir_noeud(fg,code+1,i);
			}else{
				(*i)+=1;
				return parcourir_noeud(fd,code+1,i);
			}
		}else
			return get_valeur(n);
	}
		
		
	return NULL;
}

