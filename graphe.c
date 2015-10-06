#include "graphe.h"

void ajouteVoisin(TypGraphe* G, int sommet, int voisin, int poids)
{
	//ajouteListe(&A->voisins[depart][etiquette-'a'], arrivee);
}

TypGraphe* creerGraphe()
{
	TypGraphe* G = (TypGraphe*)malloc(sizeof(TypGraphe));
	int i, j, size, oriente, pondere, voisins, cible, arete;
	arete = 0;
	
	printf("Graphe orienté (1 -> oui - 0 -> non) : ");
	scanf("%i", &oriente);
	scanf("%*[^\n]s");
	
	printf("Graphe pondéré (1 -> oui - 0 -> non) : ");
	scanf("%i", &pondere);
	scanf("%*[^\n]s");
	
	printf("Nombre de sommet : ");
	scanf("%i", &size);
	scanf("%*[^\n]s");
	
	G->size = size;
	G->pondere = pondere;
	G->oriente = oriente;
	G->voisins = (TypVoisins**)malloc(G->size*sizeof(TypVoisins**));

	for(i=0;i<G->size;i++)
	{
		G->voisins[i] = NULL;
	}

	for(i=0;i<G->size;i++)
	{
		printf("	Sommet %d\n", i+1);
		printf("> Nombre de voisin(s) : ");
		scanf("%i", &voisins);
		scanf("%*[^\n]s");
		getchar();

		for(j=0;j<voisins;j++)
		{
			printf("Sommet cible (de 1 à %d) : ", G->size);
			scanf("%i", &cible);

			if(G->pondere == 1)
			{
				printf("Poids de l'arête : ");
				scanf("%i", &arete);
			}
			ajouteVoisin(G, i, cible, arete);
		}
	}
	return G;
				
			
			
		
		
	/*
	

	
	for(i=0;i<A->size;i++)
	{
		printf("\nEtat %d\n", i);
		printf("Nombre de transition(s) : ");
		scanf ("%d",&n);
		scanf("%*[^\n]s");
		getchar();
		
		for(j=0; j<n; j++)
		{
			printf("Etat cible (de 0 à %d): ", A->size-1);
			scanf ("%d",&cible);

			printf("Transition ( de 0 (a) jusqu'à %d (%c) : ", A->sizealpha-1, 'a'+A->sizealpha-1); 
			scanf ("%d",&transition);
			scanf("%*[^\n]s");
			ajouteTransition(A, i, cible, 'a'+transition);
		}
	}*/
	
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


void afficheTransition(automate* A)
{

	int i, j;
	liste* tmp; 

	printf("\nLes transitions :\n");
	
	
	for(i=0; i<A->size; i++)
	{
		printf("-------------------\n");
		printf("Depuis l'état %d\n", i);

		for(j=0; j<A->sizealpha; j++)
		{
			printf("avec la lettre %c:\n", 'a'+j);
			
			tmp = A->trans[i][j];

			while(tmp != NULL)
			{
				printf(" %d ", tmp->state);
				tmp = tmp->suiv;
				
			}
		printf("\n");
		}
	}
}


void afficheAutomate(automate* A)
{
	int i;

	printf("Les états initiaux :\n");
	for(i=0; i<A->size; i++)
	{
		if(A->initial[i] == 1)
		{
			printf(" %d ", i);
		}
	}
	printf("\n");

	printf("Les états finaux :\n");
	for(i=0; i<A->size; i++)
	{
		if(A->final[i] == 1)
		{
			printf(" %d ", i);
		}
	}

	afficheTransition(A);
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


void decrementerTransition(automate* A, int p)
{
	int i, j;
	liste* tmp;

	for(i=0; i<A->size; i++)
	{
		for(j=0; j<A->sizealpha; j++)
		{
			tmp = A->trans[i][j];

			while(tmp != NULL)
			{
				if(tmp->state >= p)
				{
					tmp->state = tmp->state-1;
				}
				tmp = tmp->suiv;
			}
		}
	}
}



void supprimeTransition(automate* A, int depart, int arrivee, char etiquette)
{
	supprimeListe(&A->trans[depart][etiquette-'a'], arrivee);
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











		
		


	


				
		
		





	
		
		
	
		
			
	
	

	
		



