#include "liste.h"

void ajouteListe(TypVoisins** l,int q)
{
	TypVoisins* ptl;
	TypVoisins* tmp;
	ptl=*l;
	if(!ptl)
	{
		ptl=(TypVoisins*) malloc(sizeof(TypVoisins));
		ptl->state=q;
		ptl->suiv=NULL;
		*l=ptl;
		return;
	}
	if(ptl->state == q)
	{
		return;
	}
	if(q< ptl->state)
	{
		tmp=*l;
		*l=(TypVoisins*) malloc(sizeof(TypVoisins));
		(*l)->state=q;
		(*l)->suiv=tmp;
		return;
	}
	while(ptl->suiv && ptl->suiv->state <q)
	{
		ptl=ptl->suiv;
	}
	if(!ptl->suiv)
	{
		ptl->suiv=(TypVoisins*) malloc(sizeof(TypVoisins));
		ptl=ptl->suiv;
		ptl->state=q;
		ptl->suiv=NULL;
		return;
	}
	if(ptl->suiv->state==q)
	{
		return;
	}
	
	tmp=ptl->suiv;
	ptl->suiv=(TypVoisins*) malloc(sizeof(TypVoisins));
	ptl=ptl->suiv;
	ptl->state=q;
	ptl->suiv=tmp;
}



void supprimeListe(TypVoisins** l, int arrivee)
{
	
	if(NULL == *l)
	{
		return;
	}

	if((*l)->state == arrivee)
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
