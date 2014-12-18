#include <stdio.h>
#include <stdlib.h>

#include "whatever.h"
#include "Edge.h"
#include "Pile.h"
#include "Arbre.h"

static int counter = 0;

Arbre *swapNode(Arbre *a, Arbre *n1, Arbre *n2)
{
	int weight = n1->elt->weight;
	Node *pre = n1->elt->from;
	Node *suc = n1->elt->to;

	n1->elt->weight = n2->elt->weight;
	n1->elt->from = n2->elt->from;
	n1->elt->to = n2->elt->to;

	n2->elt->weight = weight;
	n2->elt->from = pre;
	n2->elt->to = suc;

	return a;
}

Arbre *ranger(Arbre *a)
{
	Arbre *temp = a;
	while(temp->pere != NULL)
	{
		if(temp->elt->weight < temp->pere->elt->weight)
		{
			swapNode(a, temp, temp->pere);
		}
		temp = temp->pere;
	}

	return a;
}

Arbre *ranger2(Arbre *a)
{
	if(a->ad != NULL)
	{
		if((a->elt->weight > a->ad->elt->weight) || (a->elt->weight > a->ag->elt->weight))
		{
			if(a->ad->elt->weight < a->ag->elt->weight)
				swapNode(a, a->ad, a);

			else
				swapNode(a, a->ag, a);
		}
	}
	return a;
}

Arbre *binaryHeap(Arbre *a, Edge *elt)
{
	Pile *p = pilenouv();
	int direction;
	int mod;
	int division;
	Arbre *temp = a;
	Arbre *new = creerFeuille(elt);

	/* 1 SEUL ELEMENT */
	/* RAJOUTER A GAUCHE DIRECTEMENT */
	if(counter == 1)
	{
		counter++;
		a->ag = new;
		new->pere = a;
		new = ranger(new);

	}

	/* DESCENDRE POUR TROUVER LA BONNE PLACE POUR INSERER L'ELEMENT */
	/* 0 --> GAUCHE, 1 --> DROITE */
	else
	{
		counter++;

		if((counter/2) == 1)
		{
			a->ad = new;
			new->pere = a;
			new = ranger(new);
		}

		/* REMPLIR LA PILE */
		else
		{
			division = counter/2;
			mod = counter % 2;
			p = empiler(p, mod);
			while((division) != 1)
			{
				mod = division % 2;
				division = division/2;
				p = empiler(p, mod);
			}

			while(p != NULL)
			{
				/* GAUCHE */
				if((direction = sommet(p)) == 0)
				{
					if(temp->ag != NULL)
						temp = temp->ag;

					else
					{
						temp->ag = new;
						new->pere = temp;
						new = ranger(new);
					}
				}

				/* DROITE */
				else
				{
					if(temp->ad != NULL)
						temp = temp->ad;

					else
					{
						temp->ad = new;
						new->pere = temp;
						new = ranger(new);
					}
				}
				p = depiler(p);
			}
		}
	}

	return a;
}

Arbre *position(Arbre *a)
{
	Arbre *temp = a;
	Pile *p = pilenouv();
	int direction;
	int mod, division;

	division = counter/2;
	mod = counter % 2;
	p = empiler(p, mod);

	while(division != 1)
	{
		mod = division % 2;
		division = division/2;
		p = empiler(p, mod);
	}

	printPile(p);
	while(p != NULL)
	{
		direction = sommet(p);

		if(direction == 0)
		{
			if(temp->ag != NULL)
				temp = temp->ag;
		}

		else
		{
			if(temp->ad != NULL)
				temp = temp->ad;
		}

		p = depiler(p);
	}

	return temp;
}

Edge *extraireMin(Arbre *a, Edge *l)
{
	Arbre *temp = a;

	while(counter != 0)
	{
		//printf(RED "\n\nCOUNTER: \t%d\n" NOCOLOR, counter);
		l = addEdge(l, a->elt->from, a->elt->weight, a->elt->to);

		if(counter == 2)
		{
			a->elt = a->ag->elt;
			a->ad = NULL;
			counter--;
			/* RANGER */
			if(a->elt->weight > a->ag->elt->weight)
				swapNode(a, a->ag, a);
		}

		else if(counter == 1)
		{
			free(a);
			counter--;
		}

		else
		{
			temp = position(a);
			counter--;

			if(temp->pere->ad == NULL)
			{
				a->elt = temp->elt;
				temp->pere->ag = NULL;
				a = ranger2(a);
			}

			else
			{	
				a->elt = temp->elt;
				temp->pere->ad = NULL;
				a = ranger2(a);
			}
		}
	}

	return l;
}

/* TEST SUR HEAP SORT */
/*
int main()
{
	counter++;
	Edge *l = createEdgeList();
	Edge *new = createEdgeList();
	Edge *temp;
	Arbre *a;
	Node *from1 = nnouv('A');
	Node *to1 = nnouv('B');
	Node *from2 = nnouv('C');
	Node *to2 = nnouv('D');
	Node *from3 = nnouv('E');
	Node *to3 = nnouv('F');
	Node *from4 = nnouv('G');
	Node *to4 = nnouv('H');
	Node *from5 = nnouv('I');
	Node *to5 = nnouv('J');
	Node *from6 = nnouv('K');
	Node *to6 = nnouv('L');
	Node *from7 = nnouv('M');
	Node *to7 = nnouv('N');

	l = addEdge(l, from1, 4, to1);
	l = addEdge(l, from2, 6, to2);
	l = addEdge(l, from3, 1, to3);
	l = addEdge(l, from4, 7, to4);
	l = addEdge(l, from5, 2, to5);
	l = addEdge(l, from6, 5, to6);
	l = addEdge(l, from7, 3, to7);

	temp = l;
	a = creerFeuille(temp);
	temp = temp->next;
	while(temp != NULL)
	{
		a = binaryHeap(a, temp);
		temp = temp->next;
	}

	printf("------------------AFFICHAGE---------------\n");
	afficherArbre(a);
	printf("------------------------------------------\n");

	new = extraireMin(a, new);
	printEdgeList(new);

	return 0;
}
*/
