#include "arbre_binaire.h"
#include "combinaison.h"
#include "noeud.h"

void _copier(void* _val, void** ptr){
		(*ptr)=(p_comb) malloc(sizeof(struct combinaison));
		char l[strlen(((p_comb)_val)->lettre)] = *((p_comb)_val)->lettre;
		*ptr=creer_combinaison(&l,((p_comb)_val)->occ);


		/*char* l = (char*)malloc(sizeof(strlen(((p_comb)_val)->lettre)));
		memcpy(l,((p_comb)_val)->lettre,sizeof(strlen(((p_comb)_val)->lettre)));
		*ptr = creer_combinaison(l,((p_comb)_val)->occ);	
		free(l);
		l=NULL;*/
}

void _detruire(void** ptr){
	supprimer_combinaison((p_comb*)(ptr));
}

void _afficher(void* _val){
	afficher_combinaison((p_comb)_val);
}

int _comparer(void* c1, void* c2) {
	return comparer_combinaison((p_comb)c1,(p_comb)c2); 
}

void* _fusion(void* c1 , void* c2){
	if(comparer_combinaison((p_comb)c1,(p_comb)c2)<0)
		return fusion_combinaison((p_comb)c1,(p_comb)c2);
	else
		return fusion_combinaison((p_comb)c2,(p_comb)c1);
}




int main (void) {


	/*char * l1="uzay";
	char * l2="umut";

	int taille = strlen(l1)+strlen(l2);

	char res [taille];

	sprintf(res,"%s%s",l1,l2);


	printf("%s\n", res);*/

	p_comb a = creer_combinaison("uzay",1);

	p_comb b = creer_combinaison(" umut",2);

	afficher_combinaison(a);

	afficher_combinaison(b);

	//p_comb res = fusion_combinaison(a,b);




	//afficher_combinaison(res);

	

	printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");

	p_arbre a1 = creer_arbre(a,&_copier);
	p_arbre a2 = creer_arbre(b,&_copier);
		supprimer_combinaison(&a);
	supprimer_combinaison(&b);

	afficher_arbre(a1,_afficher);
	afficher_arbre(a2,_afficher);

	printf("arbre fusioné\n");


	//p_arbre res_arbre_1 = fusion_arbre(a1,a2,&_fusion,&_copier,&_comparer);

	detruire_tout(&a1,&_detruire);
	detruire_tout(&a2,&_detruire);

	//detruire_tout(&res_arbre_1,&_detruire);
	//supprimer_combinaison(&res);



	
	/*p_arbre res_arbre_2 = fusion_arbre(a1,a2,&_fusion,&_copier,&_comparer);
	p_arbre res_arbre = fusion_arbre(res_arbre_2,res_arbre_1,&_fusion,&_copier,&_comparer);
	//detruire_tout(res_arbre_1,&_detruire);
	afficher_arbre(res_arbre,&_afficher);

	detruire_tout(&res_arbre,&_detruire);
	afficher_arbre(res_arbre,&_afficher);

	afficher_arbre(res_arbre_1,&_afficher);
	detruire_tout(&a1,&_detruire);
	detruire_tout(&a2,&_detruire);
	detruire_tout(&res_arbre_1,&_detruire);
	detruire_tout(&res_arbre_2,&_detruire);
	supprimer_combinaison(&res);
	supprimer_combinaison(&a);
	supprimer_combinaison(&b);

	p_comb uzay = creer_combinaison("uzay",1);
	afficher_combinaison(uzay);
	p_comb umut = creer_combinaison("umut",2);
	afficher_combinaison(umut);

	p_comb uzayumut = fusion_combinaison(umut,uzay);
	afficher_combinaison(uzayumut);




	supprimer_combinaison(&uzay);
	supprimer_combinaison(&umut);
	supprimer_combinaison(&uzayumut);*/









	return 0;

}
