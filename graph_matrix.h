#ifndef _GRAPH_MATRIX_H_
#define _GRAPH_MATRIX_H_

#include <stdlib.h>
#include <stdio.h>
#include "Node_Matrix.h"
#include "Edge.h"

typedef struct Graph
{
	int size;
	Node ** Nodes; //Garde la liste des noeud, dans l'ordre des index.
	int ** matrix; //matrix[Node1.name][Node2.name] = x : x est le poids de l'arc entre node1 et node2; -1 si inexistant ? 
}Graph;


/* Fonction commune à tout les types Graph existant */
Graph grnouv(int size); 							/* Graphe Vide */
void adjs(Graph * g, Node * n);						/* Adjonction d'un sommet */
void adja(Graph * g, Node * n1, Node * n2, int v); 	/* Adjonction d'un arc (v : poid de l'arc)*/
void sups(Graph * g, Node * n); 					/* Suppression d'un sommet */
void supa(Graph * g, Node * n1, Node * n2); 		/* Suppression d'un arc */
int exs(Graph * g, Node * n); 						/* Existence d'un sommet */
int exa(Graph * g, Node * n1, Node * n2);			/* Existence d'un arc */
int exsname(Graph g, char name); 					/* Renvoi vrai si un sommet du nom name existe dans g */
void pgraph(Graph g); 								/* Impression du Graphe sur stdout */
Node * getnode(Graph g, char name); 				/* Renvoi le sommet portant le nom name */
Edge * getEdgeList(Graph g); 						/* renvoi la liste de toutes les arrêtes  */
Edge * getNeighboors(Graph *ng); 		    			/* renvoi toutes les arrêtes partant des noeuds déjà ajouter vers de nouveaux noeuds */

#endif