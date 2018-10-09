#include "arbre_binaire.h"
#include "combinaison.h"
#include "noeud.h"
#include "liste_generique.h"

void _copier(void* _val, void** ptr){
	(*ptr)=creer_combinaison(   (*((p_comb*)(_val)))->lettre , (*((p_comb*)(_val)))->occ  );
	supprimer_combinaison( (p_comb*) _val);
}

void _detruire(void** ptr){
	supprimer_combinaison((p_comb*)(ptr));
	*ptr=NULL;
}

void _afficher(void* _val){
	afficher_combinaison((p_comb)_val);
}


int _comparer(void* c1, void* c2) {
	return comparer_combinaison((p_comb)c1,(p_comb)c2); 
}

void* _fusion(void* c1 , void* c2){
	return fusion_combinaison((p_comb)c1,(p_comb)c2);
}




int _compare_existe(void* a, void* b){
	char* ca = (char*)a;
	p_comb cb = (p_comb)b;
	int n = 0;
	char* chaine_comb = cb->lettre;
	for(unsigned int i=0; i<strlen(chaine_comb);i++)
		for(unsigned int j=0; j<strlen(ca);j++)
			if(chaine_comb[i]==ca[j])
				n++;

	return n;

}

p_comb* generer_combinaison(char* chaine,int * taille){
	if(	chaine!=NULL && strlen(chaine)!=0){
		int taille_chaine = strlen(chaine);
		char* t = (char*) malloc(sizeof(char)+1);
		int * tab = (int*)malloc(sizeof(int));
		int taille_t = 1;
		t[0]=chaine[0];
		tab[0]=1;
		int b=0;
	    for (int c = 1 ; c < taille_chaine; c++) {
	        b=0;
	    	for (int i = 0 ; i < taille_t && b==0; i++ ) {
	    		if (chaine[c]==t[i]) {
	    			b=1;
	    			tab[i]++;
	    		}
	    	}
	    	if(b!=1){
	    		taille_t++;
	    		t=realloc(t,taille_t*sizeof(char)+1);
	    		tab=realloc(tab,taille_t*sizeof(int));
	    		t[taille_t-1]=chaine[c];
	    		tab[taille_t-1]=1;
	    	}
	    }
	    p_comb* tab_comb = (p_comb*) malloc((taille_t)*sizeof(struct combinaison));
	    for(int i = 0 ; i<taille_t+1 ; i++){
	    	char s[2]={t[i],'\0'};
	    	tab_comb[i]=creer_combinaison(s,tab[i]);
	    }
	    *taille=taille_t;
	    free(t);
	    free(tab);
	    return tab_comb;
	}else{
		return NULL;
	}
}




p_arbre generer_arbre(char* s){
	int taille=0;
	p_arbre a=NULL;
	p_arbre b=NULL;
	p_arbre f=NULL;
	p_comb* tab_comb= generer_combinaison(s,&taille);
	lst l=creer_liste(& copier_arbre,& detruire_tout,& afficher_arbre,& comparer_arbre_liste);
	for(int i = 0 ; i<taille ; i++){
		a=creer_arbre(&(tab_comb[i]),&_copier,&_fusion,&_afficher,&_comparer,&_detruire,&_compare_existe);
		ajouter_liste_tri(&a,l);
	}
	while(l->taille>=2){
		a=depiler_tete(l);
		b=depiler_tete(l);
		f=fusion_arbre(&a,&b);
		ajouter_liste_tri(&f,l);
	}
	a=depiler_tete(l);
	free(tab_comb);
	detruire_liste(&l);
	return a;
}


int main (void) {


	p_comb a_comb = creer_combinaison("A",1);
	p_comb b_comb = creer_combinaison("B",1);
	p_comb c_comb = creer_combinaison("C",2);
	p_comb d_comb = creer_combinaison("D",1);

	printf("\n *** COMPARAISON COMBONAISON *** \n");
	printf("%d\n",comparer_combinaison(a_comb,b_comb));
	printf("%d\n",comparer_combinaison(b_comb,c_comb));
	printf("%d\n",comparer_combinaison(c_comb,d_comb));
	printf("%d\n",comparer_combinaison(d_comb,a_comb));
	printf("%d\n",comparer_combinaison(c_comb,a_comb));
	printf("%d\n",comparer_combinaison(d_comb,b_comb));
	printf("%d\n",comparer_combinaison(d_comb,d_comb));
	printf("\n *** FIN COMPARAISON COMBONAISON *** \n");



	p_arbre a = creer_arbre(&a_comb,&_copier,&_fusion,&_afficher,&_comparer,&_detruire,&_compare_existe);
	p_arbre b = creer_arbre(&b_comb,&_copier,&_fusion,&_afficher,&_comparer,&_detruire,&_compare_existe);
	p_arbre c = creer_arbre(&c_comb,&_copier,&_fusion,&_afficher,&_comparer,&_detruire,&_compare_existe);
	p_arbre d = creer_arbre(&d_comb,&_copier,&_fusion,&_afficher,&_comparer,&_detruire,&_compare_existe);

	printf("\n *** COMPARAISON ARBRES *** \n\n");
	printf("%d\n",comparer_arbre(a,b));
	printf("%d\n",comparer_arbre(b,c));
	printf("%d\n",comparer_arbre(c,d));
	printf("%d\n",comparer_arbre(d,a));
	printf("%d\n",comparer_arbre(c,a));
	printf("%d\n",comparer_arbre(d,b));
	printf("%d\n",comparer_arbre(d,d));
	printf("\n *** FIN COMPARAISON ARBRES *** \n");

	printf("\nMES ARBRES\n");
	afficher_arbre(a);
	afficher_arbre(b);
	afficher_arbre(c);
	afficher_arbre(d);
	printf("\nFIN MES ARBRES\n\n");


	lst l=creer_liste(& copier_arbre,& detruire_tout,& afficher_arbre,& comparer_arbre_liste);
	ajouter_liste_tri(&b,l);
	afficher_liste(l);
	
	ajouter_liste_tri(&a,l);
	afficher_liste(l);
	
	ajouter_liste_tri(&c,l);
	afficher_liste(l);
	
	ajouter_liste_tri(&d,l);
	afficher_liste(l);
	
	afficher_liste(l);

	detruire_liste(&l);
	
	p_arbre test_arbre = generer_arbre("uzay umut sag/ozgur deniz sag/yagiz meric sag");

	afficher_arbre(test_arbre);
	
	detruire_tout(&test_arbre);

	return 0;

}
