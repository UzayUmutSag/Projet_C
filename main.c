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


int main (void) {


	p_comb a_comb = creer_combinaison("A",2);
	p_arbre a = creer_arbre(&a_comb,&_copier);
	afficher_arbre(a,&_afficher);
	p_comb b_comb = creer_combinaison("B",1);
	p_arbre b = creer_arbre(&b_comb,&_copier);
	afficher_arbre(b,&_afficher);



	
	p_arbre res_fus = fusion_arbre(&a,&b,&_fusion,&_comparer,&_copier);

	printf("hauteur : %d \n", hauteur_arbre(res_fus) );

	//detruire_tout(&b,&_detruire);
	//detruire_tout(&a,&_detruire);

	p_comb c_comb = creer_combinaison("C",2);
	p_arbre c = creer_arbre(&c_comb,&_copier);
	//supprimer_combinaison(&a_comb);
	afficher_arbre(c,&_afficher);
	p_comb d_comb = creer_combinaison("D",1);
	p_arbre d = creer_arbre(&d_comb,&_copier);
	//supprimer_combinaison(&b_comb);
	afficher_arbre(d,&_afficher);


	p_arbre res_fus_bis = fusion_arbre(&c,&d,&_fusion,&_comparer,&_copier);

	p_arbre res = fusion_arbre(&res_fus,&res_fus_bis,&_fusion,&_comparer,&_copier);



	
	//detruire_tout(&res_fus,&_detruire);
	//detruire_tout(&res_fus_bis,&_detruire);

	afficher_arbre(res,_afficher);
	printf("Existe C : %d\n",existe_arbre("AF",res,&_compare_existe));
	char * code = codeprefixe(res,"A",&_compare_existe);
	free(code);
	printf("hauteur : %d \n", hauteur_arbre(res) );
	detruire_tout(&res,&_detruire);

	
	

	
	


	return 0;

}
