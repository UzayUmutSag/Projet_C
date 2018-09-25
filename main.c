#include "arbre_binaire.h"
#include "combinaison.h"
#include "noeud.h"

void _copier(void* _val, void** ptr){
		(*ptr)=(p_comb) malloc(sizeof(struct combinaison));
		memcpy(*ptr,_val,sizeof(struct combinaison));
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
	if(comparer_combinaison((p_comb)c1,(p_comb)c2)>1)
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

	char* l="uzay";
	p_comb a = creer_combinaison(l,1);

	p_comb b = creer_combinaison(" umut",2);

	afficher_combinaison(a);

	afficher_combinaison(b);

	p_comb res = fusion_combinaison(a,b);

	afficher_combinaison(res);

	printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n");

	p_arbre a1 = creer_arbre(a,&_copier);
	p_arbre a2 = creer_arbre(b,&_copier);


	afficher_arbre(a1,_afficher);
	afficher_arbre(a2,_afficher);

	printf("arbre fusioné\n");

	p_arbre res_arbre_1 = fusion_arbre(a1,a2,&_fusion,&_copier,&_comparer);
	p_arbre res_arbre_2 = fusion_arbre(a1,a2,&_fusion,&_copier,&_comparer);
	p_arbre res_arbre = fusion_arbre(res_arbre_2,res_arbre_1,&_fusion,&_copier,&_comparer);
	//detruire_tout(res_arbre_1,&_detruire);
	afficher_arbre(res_arbre,&_afficher);

	detruire_tout(&res_arbre,&_detruire);
	afficher_arbre(res_arbre,&_afficher);

	afficher_arbre(res_arbre_1,&_afficher);






	return 0;

}
