#include "graph_matrix.h"

#define NEXIST 0 //valeur "NULL"

Graph grnouv(int size)
{
	Graph g;
	int i,j;
	g.size = size;
	//Création du tableau des noeud, tous on un nom vide.
	g.Nodes = malloc(sizeof(Node *) * size);
	for(i = 0; i < size; i++)
		g.Nodes[i] = NULL;

	//création de la matrice, entièrement vide
	g.matrix = malloc(sizeof(int *) * size);
	for(i = 0; i < size; i++)
	{
		g.matrix[i] = malloc(sizeof(int) * size);
		for(j = 0; j < size; j++)
			g.matrix[i][j] = NEXIST;
	}
	return g;
} 

void adjs(Graph * g, Node * n)
{
	int i;
	for(i = 0; i < g->size; i++)
	{
		if(g->Nodes[i] == NULL) //premier emplacement libre
		{
			n->index = i;
			g->Nodes[i] = n;
			return;
		}
	}
	printf("Erreur Graph plein (%c). \n", n->name);
}


void adja(Graph * g, Node * n1, Node * n2, int v)
{
	g->matrix[n1->index][n2->index] = v;
}

void sups(Graph * g, Node * n)
{
	int i;
	for(i = 0; i < g->size; i++)
	{
		if(g->matrix[i][n->index] != NEXIST)
			g->matrix[i][n->index] = NEXIST;
		if(g->matrix[n->index][i] != NEXIST)
			g->matrix[n->index][i] = NEXIST;
	}
	g->Nodes[n->index] = NULL;
	n->index = -1;
}

void supa(Graph * g, Node * n1, Node * n2)
{
	g->matrix[n1->index][n2->index] = NEXIST;
}

int exs(Graph * g, Node * n)
{
	int i;
	for(i = 0; i < g->size; i++)
		if(equals(g->Nodes[i], n))
			return 1;
	return 0;
}

int exa(Graph * g, Node * n1, Node * n2)
{
	return (g->matrix[n1->index][n2->index] != NEXIST);
}

int exsname(Graph g, char name)
{
	int i;
	for(i = 0; i < g.size; i++)
		if(g.Nodes[i] != NULL && g.Nodes[i]->name == name)
			return 1;
	return 0;
}

Node * getnode(Graph g, char name)
{
	int i;
	for(i = 0; i < g.size; i++)
		if(g.Nodes[i]->name == name)
			return g.Nodes[i];
	return NULL;
}

void pgraph(Graph g)
{
	int i,j;
	printf("   ");
	for(i = 0; i < g.size; i++)
	{
		printf(" %c ", g.Nodes[i]->name);
	}
	printf("\n");

	for(i = 0; i < g.size; i++)
	{
		for(j = 0; j < g.size; j++)
		{
			if(j == 0)
				printf(" %c ", g.Nodes[i]->name);
			printf(" %d ", g.matrix[i][j]);
		}
		printf("\n");
	}
}

Edge * getEdgeList(Graph g)
{
    Edge * res = createEdgeList();
    Node * n1;
    Node * n2;
    int i, j;
    for(i = 0; i < g.size; i++)
    {
        n1 = g.Nodes[i];
        for(j = 0; j < g.size; j++)
        {
            n2 = g.Nodes[j];
            if(g.matrix[i][j] > 0)
                res = addEdge(res, n1, g.matrix[i][j], n2);
        }
    }
    return res;
}

Edge * getNeighboors(Graph * g) //on marque tout les noeuds déjà ajouté à 1
{
	Edge * res = createEdgeList();
	Node * n1;
	Node * n2;
	int i, j;
    for(i = 0; i < g->size; i++)
    {
        n1 = g->Nodes[i];
        for(j = 0; j < g->size; j++)
        {
            n2 = g->Nodes[j];
        	if(n1->tag > 0 && n2->tag == 0) //si l'arrete en question pars d'un noeud ajouté (tag = 1) vers un nouveau noeud (tag = 0)
	            if(g->matrix[i][j] > 0)
	                res = addEdge(res, n1, g->matrix[i][j], n2);
        }
    }
    return res;
}

