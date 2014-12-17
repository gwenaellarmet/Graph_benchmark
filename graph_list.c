#include "graph_list.h"

Graph grnouv(int size)
{
	Graph g;
	int i;
	g.size = size;
	//Création du tableau des noeud, tous sont vide pour le moment
	g.Nodes = malloc(sizeof(Node *) * size);
	for(i = 0; i < size; i++)
		g.Nodes[i] = NULL;
	return g;
}

void adjs(Graph * g, Node * n)
{
	int i;
	for(i = 0; i < g->size; i++)
	{ 
		if(g->Nodes[i] == NULL) //premier emplacement libre
		{
			g->Nodes[i] = n;
			return;
		}
	}
	printf("Erreur Graph plein (%c). \n", n->name);
}

void adja(Graph * g, Node * n1, Node * n2, int v)
{
	AddNeighboor(n1, n2, v); /*Variable g inutile mais laissé pour cohérence avec les autres type de graphe */
}

void sups(Graph * g, Node * n)
{
	int i;
	for(i = 0; i < g->size && g->Nodes[i] != NULL; i++) //on supprime toute les arrête concernant ce noeud
	{
            if(equals(g->Nodes[i], n))
                g->Nodes[i] = NULL;
            else
                supa(g, g->Nodes[i], n);
	}

}

void supa(Graph * g, Node * n1, Node * n2)
{
    delete_from_list(&n1->neighboors, n2);
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
	if(in_list(n1->neighboors, n2))
		return 1;
	return 0;
}


int exsname(Graph g, char name)
{
	int i;
	for(i = 0; i < g.size ; i++)
		if(g.Nodes[i] != NULL)
			if(g.Nodes[i]->name == name)
				return 1;
	return 0;
}

void pgraph(Graph g)
{
	int i;
	printf("\n");
	for(i = 0; i < g.size; i++)
	{
		pNode(g.Nodes[i]);
		printf("\n");
	}
	printf("\n");
}

Node * getnode(Graph g, char name)
{
	int i;
	for(i = 0; i < g.size; i++)
		if(g.Nodes[i]->name == name)
			return g.Nodes[i];
	return NULL;
}

Edge * getEdgeList(Graph g)
{
    Edge * res = createEdgeList();
    NodeElem * nodelist;
    int i;
    for(i = 0; i < g.size; i++)
    {
        nodelist = g.Nodes[i]->neighboors;
        while(nodelist != NULL)
        {
            res = addEdge(res, g.Nodes[i], nodelist->weight, nodelist->elem);
            nodelist = nodelist->next;
        }
    }
    return res;
}

Edge * getNeighboors(Graph * g)
{
    Edge * res = createEdgeList();
    NodeElem * nodelist;
    int i;
    for(i = 0; i < g->size; i++)
    {
        nodelist = g->Nodes[i]->neighboors;
        while(nodelist != NULL)
        {
            if(g->Nodes[i]->tag == 1 && nodelist->elem->tag == 0)
            	res = addEdge(res, g->Nodes[i], nodelist->weight, nodelist->elem);
            nodelist = nodelist->next;
        }
    }
    return res;
}
