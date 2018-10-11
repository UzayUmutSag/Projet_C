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

void _detruire_tout_liste(void** val){
	detruire_tout((p_arbre*) val);
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
	    		t[taille_t]='\0';
	    		tab[taille_t-1]=1;
	    	}
	    }
	    
	    p_comb* tab_comb = (p_comb*) malloc((taille_t)*sizeof(struct combinaison));
	    for(int i = 0 ; i<taille_t ; i++){
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
	lst l=creer_liste(& copier_arbre,& _detruire_tout_liste,& afficher_arbre,& comparer_arbre_liste);
	for(int i = 0 ; i<taille ; i++){
		a=creer_arbre(&(tab_comb[i]),&_copier,&_fusion,&_afficher,&_comparer,&_detruire,&_compare_existe);
		ajouter_liste_tri(&a,l);
	}
	free(tab_comb);
	tab_comb=NULL;
	while(l->taille>=2){
		a=depiler_tete(l);
		b=depiler_tete(l);
		f=fusion_arbre(&a,&b);
		ajouter_liste_tri(&f,l);
	}
	a=depiler_tete(l);
	detruire_liste(&l);
	return a;


}

char * encoder(p_arbre a,char * c){
	int taille=strlen(c);
	int taille_code=0;
	int taille_res=0;
	char * res=(char*)malloc(sizeof(char));
	res[0]='\0';
	char s[2]={' ','\0'};
	char * code="";
	for (int i = 0; i < taille; ++i){
		s[0]=c[i];
		code=codeprefixe(a,s);
		taille_code=strlen(code);
		taille_res=strlen(res);
		res=realloc(res,(taille_code+taille_res+1)*sizeof(char));
		strcat(res,code);
		free(code);
	}
	return res;
}




char* decoder(p_arbre a, char* code){
	int pos = 0;
	char* res=(char*)malloc(sizeof(char));
	res[0]= '\0';
	while(pos<(int)strlen(code)){
		p_comb comb = parcourir_arbre(a,code+pos,&pos);
		char* lettre = get_lettre(comb);
		res=realloc(res,(strlen(res)+strlen(lettre)+1)*sizeof(char));
		strcat(res,lettre);
		free(lettre);
	}
	return res;
}


void ecrire_fichier_code(char* code, char* chaine, char* nom_fichier){
	
	if(code!=NULL&&chaine!=NULL){
		FILE* fichier = fopen(nom_fichier,"w");
		if(fichier!=NULL){
		
			int taille=0;
			p_comb* comb=generer_combinaison(chaine,&taille);
			fprintf(fichier,"%lu\n%d\n%s\n",strlen(code),taille,code);
			for(int i=0; i<taille; i++){
				char* lettre = get_lettre(comb[i]);
				fprintf(fichier,"[%s,%d]\n",lettre,get_occ(comb[i]));
				supprimer_combinaison(&comb[i]);
				free(lettre);
			}
			free(comb);
		}
		fclose(fichier);
	}else{
		printf("Erreur à la création ou écriture du fichier.");
	}
}
