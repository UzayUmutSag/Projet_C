#include "arbre_binaire.h"
#include "combinaison.h"
#include "noeud.h"
#include "liste_generique.h"



int main (void) {

	/*int taille=0;

	p_comb * tab_comb = generer_combinaison("uzay umut sag",&taille);
	printf("%d\n", taille);

	for (int i = 0; i < taille; ++i) {
		supprimer_combinaison(&tab_comb[i]);
	}
	free(tab_comb);
	tab_comb=NULL;*/
	char * chaine="uzay umut sag/ozgur deniz sag/yagiz meric sag";

	
	p_arbre test_arbre = generer_arbre(chaine);

	afficher_arbre(test_arbre);


	char * s=encoder(test_arbre,chaine);

	printf("\n code prefixe : %s\n", s);

	/*char* s = codeprefixe (test_arbre,"c");
	printf("%s\n", s);*/
	free(s);

	
	detruire_tout(&test_arbre);


	return 0;

}
