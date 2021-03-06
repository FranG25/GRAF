#include "graphe.h"


void ajouteVoisin(TypGraphe* G, int sommet, int voisin, int poids)
{
	ajouteListe(&G->voisins[sommet], voisin, poids);
}

int choixSommet(int* possible, int size)
{
	int exit = 0;
	int cible;
	int i;
	while(exit != 1)
	{
		printf("Sommet(s) possible(s) : ");
		for(i=0;i<size;i++)
		{
			if(possible[i] != 0)
			{
				printf("%d ", possible[i]);
			}
		}
		printf("\n> Cible : ");
		scanf("%i", &cible);
		scanf("%*[^\n]s");
		getchar();
		for(i=0;i<size;i++)
		{
			if(cible == possible[i])
			{
				exit = 1;
			}
		}
	}
	return cible;	
}

TypGraphe* creerGraphe()
{
	TypGraphe* G = (TypGraphe*)malloc(sizeof(TypGraphe));
	
	int i, j, size, oriente, pondere, voisins, cible, arete, k, compteur;
	arete = 0;
	oriente = -1;
	pondere = -1;


	
	while((oriente < 0)||(oriente > 1))
	{
		printf("Graphe orienté (1/0) : ");
		scanf("%i", &oriente);
		scanf("%*[^\n]s");
	}
	while((pondere < 0)||(pondere > 1))
	{	
		printf("Graphe pondéré (1/0) : ");
		scanf("%i", &pondere);
		scanf("%*[^\n]s");
	}
	
	printf("Nombre de sommet(s)  : ");
	scanf("%i", &size);
	scanf("%*[^\n]s");
	
	G->size = size;
	int possible[size];
	
	G->pondere = pondere;
	G->oriente = oriente;
	G->voisins = (TypVoisins**)malloc(G->size*sizeof(TypVoisins**));

	for(i=0;i<G->size;i++)
	{
		G->voisins[i] = NULL;
	}

	for(i=0;i<G->size;i++)
	{
		voisins = -1;
		compteur = listeVoisinsPossible(G, possible, i+1);
		if(compteur != 0)
		{	
			while((voisins < 0)||(voisins > compteur))
			{
				printf("	Sommet %d\n", i+1);
				printf(" > Nombre de voisins (max = %d) : ", compteur);
				scanf("%i", &voisins);
				scanf("%*[^\n]s");
				getchar();
			}
		
			for(j=0;j<voisins;j++)
			{
				compteur = listeVoisinsPossible(G,possible,i+1);
				cible = choixSommet(possible, size);
				if(G->pondere == 1)
				{
					printf(" > Poids de l'arête : ");
					scanf("%i", &arete);
				}
				
				ajouteVoisin(G, i, cible, arete);
				if(G->oriente == 0)
				{
					ajouteVoisin(G, cible-1, i+1, arete);
				}
			}
		}
	}
	return G;
}

int listeVoisinsPossible(TypGraphe* G, int* possible, int s)
{
	int i,j, res;
	j = 0;

	for(i=0;i<G->size;i++)
	{
		possible[i] = 0;
	}
	for(i=1;i<G->size+1;i++)
	{
		res =  presenceVoisin(G, i-1, s);
		if((i!=s)&&(res!=1))
		{
			possible[j] = i;
			j++;	 
		}
	}
	return j;
}


int presenceVoisin(TypGraphe* G, int i, int v)
{
	TypVoisins* tmp = (TypVoisins*)malloc(sizeof(TypVoisins*));
	tmp = G->voisins[v-1];
	while(tmp != NULL)
	{
		if(tmp->voisin == i+1)
		{
			return 1;
		}
		tmp = tmp->suiv;
	}
	return 0;
}

				
void afficheVoisin(TypGraphe* G)
{
	int i, j;
	TypVoisins* tmp; 	

	for(i=0;i<G->size;i++)
	{
		printf(" %d : ", i+1);
		tmp = G->voisins[i];

			while(tmp != NULL)
			{
				printf(" (%d/%d) ", tmp->voisin, tmp->poids);
				tmp = tmp->suiv;
			}
		printf("\n");
	}
}


void afficheGraphe(TypGraphe* G)
{
	
	printf(">> Affichage du Graphe\n");
	printf("# Nombre maximum de sommet\n");
	printf("%d\n", G->size);
	printf("# oriente\n");
	if(G->oriente == 1)
	{
		printf("o\n");
	}
	else
	{
		printf("n\n");
	}
	printf("# sommets : voisin\n");
	afficheVoisin(G);
	printf("\n");
}

void supprimeSommet(TypGraphe* G, int sommet)
{
	int i, j;

	if((sommet < G->size+1)&&(sommet > 0))
	{
		for(i=sommet; i<G->size+1; i++)
		{
			printf("i = %d\n", i);
			if(i+1 < G->size+1)
			{
				G->voisins[i] = G->voisins[i+1];
			}
		}
		
		G->size = G->size-1;
		free(G->voisins[G->size]);
			
	
		for(i=0; i<G->size; i++)
		{
			supprimeVoisin(G, i, sommet);
		}
		
		decrementerTransition(G, sommet);
	}
}

void supprimeVoisin(TypGraphe* G, int sommet, int voisin)
{
	supprimeListe(&G->voisins[sommet], voisin);
}

void decrementerTransition(TypGraphe* G, int p)
{
	int i, j;
	TypVoisins* tmp;

	for(i=0; i<G->size; i++)
	{
		tmp = G->voisins[i];

		while(tmp != NULL)
		{
			if(tmp->voisin >= p)
			{
				tmp->voisin = tmp->voisin-1;
			}
			tmp = tmp->suiv;
		}
	}
}

void insertArete(TypGraphe* G)
{
	int poids, sommet, cible;
	
	printf(">> Insertion d'une arête <<\n\n");
	printf("Sommet de départ : ");
	scanf("%d",&sommet);
	scanf("%*[^\n]s");
	getchar();
	printf("Sommet cible : ");
	scanf("%d",&cible);
	scanf("%*[^\n]s");
	getchar();
	poids = 0;
	if(G->pondere == 1)
	{
		printf("Poids de l'arête : ");
		scanf("%d",&poids);
		scanf("%*[^\n]s");
		getchar();
	}
	ajouteVoisin(G, sommet-1, cible, poids);
	if(G->oriente == 0)
	{
		ajouteVoisin(G, cible-1, sommet, poids);
	}
	printf("\n\n");
}


void insertSommet(TypGraphe* G)
{
	printf(">> Insertion d'un nouveau sommet <<\n\n");
	G->size++;
	realloueMemoire(G->voisins, G->size);
	G->voisins[G->size-1] = (TypVoisins*)malloc(sizeof(TypVoisins*));
	G->voisins[G->size-1] = NULL;
}

void suppressionSommet(TypGraphe* G)
{
	int choix;
	
	printf(">> Suppression d'un sommet <<\n\n");
	printf("Sommet à supprimer (1 à %d) : ", G->size);
	scanf("%d",&choix);
	scanf("%*[^\n]s");
	getchar();
	supprimeSommet(G,choix);
}


int sauvegardeVoisin(TypGraphe* G, FILE* f)
{
	int i, j;
	TypVoisins* tmp; 	

	for(i=0;i<G->size;i++)
	{
		fprintf(f,"%d : ", i+1);
		tmp = G->voisins[i];

			while(tmp != NULL)
			{
				fprintf(f,"(%d/%d) ", tmp->voisin, tmp->poids);
				tmp = tmp->suiv;
			}
		fprintf(f,"%s","\n");
	}
}

int sauvegardeGraphe(TypGraphe* G)
{
	FILE* f;
	char* chemin = (char*)malloc(50*sizeof(char));
	char* save = (char*)malloc(20*sizeof(char));
	printf("Saisir le nom du fichier : ");
	scanf("%s",save);
	scanf("%*[^\n]s");
	getchar();
	sprintf(chemin, "./sauvegarde/%s.txt", save);
	f = fopen(chemin, "w+");
	if(f == NULL)
	{
		perror("Error opening file");
	}
	else
	{
		fprintf(f,"%s\n" ,"# Nombre maximum de sommet");
		fprintf(f,"%d\n", G->size);
		fprintf(f,"%s\n", "# oriente");
		if(G->oriente == 1)
		{
			fprintf(f, "%s\n","o");
		}
		else
		{
			fprintf(f, "%s\n","n");
		}
		fprintf(f,"%s\n", "# sommets : voisin");
		sauvegardeVoisin(G,f);
		printf("...Sauvegarde dans %s.txt..\n", save);
		printf("\n");
	}
	
	fclose(f);
	free(save);
}	
			
int lectureGraphe(TypGraphe* G)
{
	FILE* f;
	char tmp[TAILLE_MAX];
	char chemin[50];
	char* load  = (char*)malloc(20*sizeof(char));

	printf("Saisir le nom du fichier : ");
	scanf("%s",load);
	scanf("%*[^\n]s");
	getchar();
	sprintf(chemin, "./sauvegarde/%s.txt", load);
	f = fopen(chemin, "r");
	if(f == NULL)
	{
		perror("Error opening file. Le chemin spécifié est soit faux, soit le fichier n'existe pas");
		free(load);
		free(f);
		return -1;
	}
	else
	{
		while(f != NULL)
		{
			fgets(tmp, TAILLE_MAX, f);
			printf("%s\n", tmp);

		}
	}
	free(load);
	return 1;
}

/*automate* construitAutomateExempleDeterminisation()
{
	automate* A = (automate*)malloc(sizeof(automate));
	int i,j;
	A->size=3;
	A->sizealpha=2;
	A->initial=(int*) malloc(A->size*sizeof(int));
	A->initial[0]=1;
	A->initial[1]=0;
	A->initial[2]=0;
	A->final=(int*) malloc(A->size*sizeof(int));
	A->final[0]=0;
	A->final[1]=0;
	A->final[2]=1;
	A->trans=(liste***) malloc(A->size*sizeof(liste**));
	for(i=0;i<A->size;i++)
	{
		A->trans[i]=(liste**) malloc(A->sizealpha*sizeof(liste*));
		for(j=0;j<A->sizealpha;j++)
		{
			A->trans[i][j]=NULL;
		}
	}
	ajouteTransition(A,0,0,'a');
	ajouteTransition(A,0,0,'b');
	ajouteTransition(A,0,1,'a');
	ajouteTransition(A,1,2,'a');
	ajouteTransition(A,1,2,'b');
	return A;
}
	
automate* construitAutomateExemple()
{
	automate* A = (automate*)malloc(sizeof(automate));
	int i,j;
	A->size=2;
	A->sizealpha=2;
	A->initial=(int*) malloc(A->size*sizeof(int));
	A->initial[0]=1;
	A->initial[1]=0;
	A->final=(int*) malloc(A->size*sizeof(int));
	A->final[0]=0;
	A->final[1]=1;
	A->trans=(liste***) malloc(A->size*sizeof(liste**));
	for(i=0;i<A->size;i++)
	{
		A->trans[i]=(liste**) malloc(A->sizealpha*sizeof(liste*));
		for(j=0;j<A->sizealpha;j++)
		{
			A->trans[i][j]=NULL;
		}
	}
	ajouteTransition(A,0,0,'a');
	ajouteTransition(A,0,1,'a');
	ajouteTransition(A,1,1,'b');
	return A;
}



		
int compteTransition(automate* A)
{
	int nbTransition, i, j;
	liste* tmp;

	nbTransition = 0;

	for(i=0; i<A->size; i++)
	{
		
		for(j=0; j<A->sizealpha; j++)
		{

			tmp = A->trans[i][j];
	
			while(tmp != NULL)
			{
				nbTransition++;
				tmp=tmp->suiv;
			}
		}
	}

	return nbTransition;
}

int deterministe(automate* A)
{
	int i,j, compteur;

	compteur = 0;
	
	
	for(i=0;i<A->size;i++)
	{
		if(A->initial[i] == 1)
		{
			compteur++;
		}
	}

	if((compteur > 1)||(compteur == 0))
	{
		return 0;
	}
			
		
	for(i=0;i<A->size;i++)
	{
		for(j=0;j<A->sizealpha;j++)
		{
	
			if(A->trans[i][j] != NULL)
			{
				if(A->trans[i][j]->suiv != NULL)
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
	}
	return 1;
}


int complet(automate* A)
{
	int i, j;
	liste* tmp;
	
	for(i=0; i<A->size; i++)
	{
		for(j=0; j<A->sizealpha; j++)
		{

			tmp = A->trans[i][j];
			if(NULL == tmp)
			{
				free(tmp);
				return 0;
			}
		}
	}	
	free(tmp);
	return 1;				
}







	
	

void supprimeEtat(automate* A, int p)
{
	int i, j;
	
	
	if(p < A->size)
	{

		for(i=p; i<A->size; i++)
		{
			if(i+1 < A->size)
			{
				A->trans[i] = A->trans[i+1];
				A->initial[i] = A->initial[i+1];
				A->final[i] = A->final[i+1];
			}
		}
		
		
		A->size = A->size-1;
		free(A->trans[A->size]);
			
	
		for(i=0; i<A->size; i++)
		{
			for(j=0; j<A->sizealpha; j++)
			{
				supprimeTransition(A, i, p, ('a'+j));
			}
		}
		
		decrementerTransition(A, p);
	}

}

int ajoutEtat(automate* A)
{
	int i, res;
	
	A->size = A->size+1;
	A->trans = (liste***)realloueMemoire(A->trans, A->size*sizeof(liste**));


	A->trans[A->size-1] = (liste**)malloc(A->sizealpha*sizeof(liste*));
	
	for(i=0;i<A->sizealpha;i++)
	{
			A->trans[A->size-1][i] = NULL;
	}
	
	res = A->size-1;
	return res;
}
	

void completeAutomate(automate* A)
{
	int i, j, numEtat;
	liste* tmp;
	

	if(complet(A) == 0)
	{
		numEtat = ajoutEtat(A);
		printf("	Numéro nouvel état = %d\n", numEtat);


	
		for(i=0; i<A->size; i++)
		{
			for(j=0; j<A->sizealpha; j++)
			{
				tmp = A->trans[i][j];
				if(NULL == tmp)
				{
					ajouteTransition(A, i, numEtat, 'a'+j);  //Ajout transition vers un état "poubelle"
				}
			}
		}
	}
}

void fusionEtats(automate* A, int p1, int p2)
{

	int i,j;
	liste* tmp;
	
	if (p1 >= A->size || p1 < 0 || p2 >= A->size || p2 < 0 ){
		printf("L'Etat ou la lettre n'existe pas. \n");
		return;
	}
	

	for(i=0; i<A->size; i++)
	{
		for(j=0; j<A->sizealpha; j++)
		{
			tmp = A->trans[i][j];
			while(tmp != NULL)
			{
				if(i==p2)
				{
					if(tmp->state == p2)
					{
						ajouteTransition(A,p1,p1,('a'+j));
					}
					else
					{
						ajouteTransition(A,p1,tmp->state,('a'+j));
					}
				}
				if(tmp->state == p2){
					ajouteTransition(A,i,p1,('a'+j));
				}
				tmp = tmp->suiv;	
			}			
		}
	}
	supprimeEtat(A, p2);
}

automate* produit(automate* au1, automate* au2)
{
	int i, j, m, size, sizealpha;
	automate* produit = (automate*)malloc(sizeof(automate));
	automate* petit = (automate*)malloc(sizeof(automate));
	automate* grand = (automate*)malloc(sizeof(automate));
	liste* tmpPetit;
	liste* tmpGrand;
	
	if(au1->sizealpha >= au2->sizealpha)
	{
		sizealpha = au1->sizealpha;
	}
	else
	{
		sizealpha = au2->sizealpha;
	}

	
	if(au1->size >= au2->size)
	{
		m = au1->size;
		grand = au1;
		petit = au2;
	}
	else
	{
		m = au2->size;
		grand = au2;
		petit = au1;
	}
	
	size = grand->size*petit->size;
	produit->size = size;
	produit->sizealpha = sizealpha;
	
	produit->initial = (int*)malloc(size*sizeof(int));
	produit->final = (int*)malloc(size*sizeof(int));
	
	for(i=0;i<size;i++)
	{
		
		if((petit->initial[i/m] == 1)&&(grand->initial[i%m]== 1))
		{
			produit->initial[i] = 1;
		}
		else
		{
			produit->initial[i] = 0;
		}
		
		if((petit->final[i/m] == 1)&&(au2->final[i%m] == 1))
		{
			produit->final[i] = 1;
		}
		else
		{
			produit->final[i] = 0;
		}
	}
	

	
	produit->trans = (liste***) malloc(size*sizeof(liste**));
	
	for(i=0;i<size;i++)
	{
		produit->trans[i] = (liste**) malloc(sizealpha*sizeof(liste*));
		
			for(j=0;j<sizealpha;j++)
			{
				produit->trans[i][j] = NULL;
			}
	}
	
	for(i=0;i<size;i++)
	{
		
		for(j=0;j<sizealpha;j++)
		{
			tmpGrand = grand->trans[i%m][j];
			tmpPetit = petit->trans[i/m][j];
			
			while(tmpPetit != NULL)
			{
				while(NULL != tmpGrand)
				{
					ajouteTransition(produit, i, ((tmpPetit->state * m)+tmpGrand->state), (char)('a'+j));
					tmpGrand = tmpGrand->suiv;
				}
				tmpPetit = tmpPetit->suiv;
				tmpGrand = grand->trans[i%m][j];
			}
		}
	}
	return produit;
}
			
int intersectionVide(automate* au1, automate* au2)
{
	automate* tmp = (automate*)malloc(sizeof(automate));
	
	tmp = produit(au1, au2);
	

	return langageVide(tmp);
}


automate* determinise(automate* A)
{	
	if(deterministe(A) == 1)
	{
		return;
	}

	
	int i, j, k, n, init, test;
	ifile* file = (ifile*)malloc(sizeof(ifile));
	int* pt = (int*)malloc(A->size*sizeof(int));
	liste* tmp;
	iliste* tmpFile;

	for(i=0;i<A->size;i++)
	{
		if(A->initial[i] == 1)
		{
			pt[0] = i;
			break;
		}
	}

	
	
	ajouteFile(file, pt, 1);
	afficheFile(file);

	tmpFile = file->debut;
	while(tmpFile != NULL)
	{
		for(i=0; i<A->sizealpha; i++)
		{
			n = 0;
			
			for(j=0; j<tmpFile->tailleVal; j++)
			{
				tmp = A->trans[tmpFile->val[j]][i];

				while(tmp != NULL)
				{
					pt[n] = tmp->state;
					tmp = tmp->suiv;
					n++;
				}
			}
			
			if(estDansFile(file, pt, n) == -1)
			{
				ajouteFile(file, pt, n);
			}
		}
		tmpFile = tmpFile->suiv;
	}
	
	afficheFile(file);
	
	//Création de l'automate déterminisé
	automate* D = (automate*) malloc (sizeof(automate));
	D->size = file->fin->state + 1;
	D->sizealpha = A->sizealpha;

	D->initial=(int*) malloc(D->size*sizeof(int));

	for(i=0;i<D->size;i++)
	{
		if(i == 0)
		{
			D->initial[i] = 1;
		}
		else
		{
			D->initial[i] = 0;
		}
	}

	
	D->final=(int*) malloc(D->size*sizeof(int));
	tmpFile = file->debut;
	
	while(tmpFile != NULL){
		for(i=0; i<tmpFile->tailleVal; i++)
		{
			if(A->final[tmpFile->val[i]] == 1)
			{
				D->final[tmpFile->state] = 1;
			}
			else
			{
				D->final[tmpFile->state] = 0;
			}
		}
		tmpFile = tmpFile->suiv;
	}

	D->trans=(liste***) malloc(D->size*sizeof(liste**));
	
	for(i=0;i<D->size;i++)
	{
		D->trans[i]=(liste**) malloc(D->sizealpha*sizeof(liste*));
		
		for(j=0;j<D->sizealpha;j++)
		{
			D->trans[i][j]=NULL;
		}
	}
	
	tmpFile = file->debut;

	while(tmpFile != NULL)
	{
		for(i=0; i<A->sizealpha; i++)
		{
			n = 0;
		
			for(j=0; j<tmpFile->tailleVal; j++)
			{
				tmp = A->trans[tmpFile->val[j]][i];
				
				while(tmp != NULL)
				{
					pt[n] = tmp->state;
					tmp = tmp->suiv;
					n++;
				}
			}
			
			test = estDansFile(file, pt, n);


			if(test != -1){
				ajouteTransition(D,tmpFile->state,test,(char)('a' + i));
			}
		}
		tmpFile = tmpFile->suiv;
	}

	free(pt);
	free(tmp);
	free(tmpFile);

	return D;
}


int nerodeEquivalent(automate* A, int e1, int e2)
{
	int i;
	
	if(A->final[e1] != A->final[e2])
	{
		return 0;
	}

	for(i=0;i<A->sizealpha;i++)
	{
		if(A->final[A->trans[e1][i]->state] != A->final[A->trans[e2][i]->state] ){
			return 0;
		}
	}
	
	return 1;
}

void minimiseNerode(automate* A){
	int i, j;
	
	if(deterministe(A) == 0)
	{
		printf("Automate non déterministe > Déterminisation de l'automate\n");
		determinise(A);
	}
	
	if(complet(A) == 0)
	{
		printf("Automate non complet > Complétion de l'automate.\n");
		completeAutomate(A);
	}

	j = 0;
	for(i=0;i<A->size;i++)
	{
		j = i + 1;
		while(j<A->size)
		{
			if(nerodeEquivalent(A,i,j))
			{
				fusionEtats(A,i,j);
			}
			else
			{
				j++;
			}
		}
	}
}
*/











		
		


	


				
		
		





	
		
		
	
		
			
	
	

	
		



