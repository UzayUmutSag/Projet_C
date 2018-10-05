#include "arbre_binaire.h"
#include "combinaison.h"
#include "noeud.h"

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

p_comb* generer_combinaison(char* chaine){
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
	    p_comb* tab_comb = (p_comb*) malloc((taille_t+1)*sizeof(struct combinaison));
	    tab_comb[0]=creer_combinaison("taille",taille_t+1);
	    for(int i = 0 ; i<taille_t+1 ; i++){
	    	char s[2]={t[i],'\0'};
	    	tab_comb[i+1]=creer_combinaison(s,tab[i]);
	    }
	    free(t);
	    free(tab);
	    return tab_comb;
	}else{
		return NULL;
	}
}

/*p_arbre generer_arbre(char* s){

}*/


int main (void) {


	p_comb a_comb = creer_combinaison("A",2);
	p_arbre a = creer_arbre(&a_comb,&_copier,&_fusion,&_afficher,&_comparer,&_detruire,&_compare_existe);
	afficher_arbre(a);
	p_comb b_comb = creer_combinaison("B",1);
	p_arbre b = creer_arbre(&b_comb,&_copier,&_fusion,&_afficher,&_comparer,&_detruire,&_compare_existe);
	afficher_arbre(b);



	
	p_arbre res_fus = fusion_arbre(&a,&b);

	printf("hauteur : %d \n", hauteur_arbre(res_fus) );

	//detruire_tout(&b,&_detruire);
	//detruire_tout(&a,&_detruire);

	p_comb c_comb = creer_combinaison("C",2);
	p_arbre c = creer_arbre(&c_comb,&_copier,&_fusion,&_afficher,&_comparer,&_detruire,&_compare_existe);
	//supprimer_combinaison(&a_comb);
	afficher_arbre(c);
	p_comb d_comb = creer_combinaison("D",1);
	p_arbre d = creer_arbre(&d_comb,&_copier,&_fusion,&_afficher,&_comparer,&_detruire,&_compare_existe);
	//supprimer_combinaison(&b_comb);
	afficher_arbre(d);


	p_arbre res_fus_bis = fusion_arbre(&c,&d);

	p_arbre res = fusion_arbre(&res_fus,&res_fus_bis);



	
	//detruire_tout(&res_fus,&_detruire);
	//detruire_tout(&res_fus_bis,&_detruire);

	afficher_arbre(res);
	printf("Existe C : %d\n",existe_arbre("AF",res));
	char* code = codeprefixe(res,"A");
	
		printf("%s",code);
	printf("\n");
	free(code);

	printf("hauteur : %d \n", hauteur_arbre(res) );
	detruire_tout(&res);

	
	

	
	


	return 0;

}
