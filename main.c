#include "fonctions.c"



int main (void) {

	/*int taille=0;

	p_comb * tab_comb = generer_combinaison("uzay umut sag",&taille);
	printf("%d\n", taille);

	for (int i = 0; i < taille; ++i) {
		supprimer_combinaison(&tab_comb[i]);
	}
	free(tab_comb);
	tab_comb=NULL;*/
	char * chaine="uzay, umut sag/ozgur deniz sag/yagiz meric sag";

	
	p_arbre test_arbre = generer_arbre(chaine);

	afficher_arbre(test_arbre);


	char * s=encoder(test_arbre,chaine);

	printf("\n code prefixe : %s\n", s);

	/*char* s = codeprefixe (test_arbre,"c");
	printf("%s\n", s);*/
	

	

	char * code = "0000010101111110000011100000110001001011010011110011110110010110001111010011010111011111010101000110010110100111100111111010011101000110011100110111111010101101001001011010011";
	char* chainebis = decoder(test_arbre,s);
	printf("%s\n",chainebis);
	ecrire_fichier_code(s,chaine,"test.txt");
	free(chainebis);
	free(s);


	detruire_tout(&test_arbre);


	return 0;

}
