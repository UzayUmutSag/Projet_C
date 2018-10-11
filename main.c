#include "fonctions.c"


int main (void) {

	/*
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
	*/

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
