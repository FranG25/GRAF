#include "liste.h"

void ajouteListe(TypVoisins** l,int voisin, int poids)
{
	TypVoisins* ptl;
	TypVoisins* tmp;
	ptl=*l;
	if(!ptl)
	{
		ptl=(TypVoisins*)malloc(sizeof(TypVoisins));
		ptl->voisin=voisin;
		ptl->poids=poids;
		ptl->suiv=NULL;
		*l=ptl;
		return;
	}
	if(ptl->voisin == voisin)
	{
		return;
	}
	if(voisin< ptl->voisin)
	{
		tmp=*l;
		*l=(TypVoisins*) malloc(sizeof(TypVoisins));
		(*l)->voisin=voisin;
		(*l)->poids=poids;
		
		(*l)->suiv=tmp;
		return;
	}
	while(ptl->suiv && ptl->suiv->voisin <voisin)
	{
		ptl=ptl->suiv;
	}
	if(!ptl->suiv)
	{
		ptl->suiv=(TypVoisins*) malloc(sizeof(TypVoisins));
		ptl=ptl->suiv;
		ptl->voisin=voisin;
		ptl->poids=poids;
		ptl->suiv=NULL;
		return;
	}
	if(ptl->suiv->voisin==voisin)
	{
		return;
	}
	
	tmp=ptl->suiv;
	ptl->suiv=(TypVoisins*) malloc(sizeof(TypVoisins));
	ptl=ptl->suiv;
	ptl->voisin=voisin;
	ptl->suiv=tmp;
}



void supprimeListe(TypVoisins** l, int arrivee)
{
	
	if(NULL == *l)
	{
		return;
	}

	if((*l)->voisin == arrivee)
	{
		*l = (*l)->suiv;
	}
	else
	{
		if(NULL != (*l)->suiv)
		{
			supprimeListe(&(*l)->suiv, arrivee);
		}
	}
}
