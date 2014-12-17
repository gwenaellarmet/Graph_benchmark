#ifndef _NODE_LIST_H
#define _NODE_LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
	char name; 
	struct NodeElem * neighboors;
        int tag;
}Node;

/* Commun à tout les types de node */
Node * nnouv(char name);
int equals(Node * n1, Node * n2);
void AddNeighboor(Node * n, Node * v, int weight);
void pNode(Node * n);

typedef struct NodeElem
{
    Node * elem; //pointeur sur le voisins.
    int weight; // poids de l'arrete
    struct NodeElem * next;
}NodeElem;

/* Fonctions d'un élément de la liste chainée */
NodeElem * init_NodeElem(Node *dest, int weight);
NodeElem * add_list(NodeElem * l, NodeElem * e); /* retourne la nouvelle tête de liste, ajoute e en tete de liste */
void delete_from_list(NodeElem ** l, Node * n); /* Supprime l'elem de la liste l s'il existe, ne fais rien sinon. */
int in_list(NodeElem * l, Node * n); /* Renvoi 1 si n est dans la liste l */
void print_list(NodeElem * tete); /* imprime toute la liste */


#endif