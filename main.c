#include "arbre_binaire.h"
#include "combinaison.h"

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


int main (void) {
	char* l="uzay";
	p_comb c = creer_combinaison(l,1);
	
	afficher_combinaison(c);
	p_arbre a = creer_arbre(c,&_copier);
	supprimer_combinaison(&c);
	free(c);


	afficher_combinaison(c);



	afficher_arbre(	a,&_afficher);
	detruire_tout(&a,&_detruire);
	afficher_arbre(a,&_afficher);
	




	return 0;

}
