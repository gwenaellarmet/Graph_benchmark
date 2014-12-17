#include "Node_list.h"

Node * nnouv(char name)
{
	Node * res = malloc(sizeof(Node));
	res->name = name;
	res->neighboors = NULL;
        res->tag = 0;
	return res;
}

int equals(Node * n1, Node * n2)
{
	return (n1->name == n2->name);
}

void AddNeighboor(Node * n, Node * dest, int weight)
{
	NodeElem * dest_elem = init_NodeElem(dest, weight);
	n->neighboors = add_list(n->neighboors, dest_elem);
}

void pNode(Node * n)
{
	printf("| %c | ", n->name);
	print_list(n->neighboors);
}

NodeElem * init_NodeElem(Node * dest, int weight)
{
	NodeElem * res = malloc(sizeof(NodeElem));
	res->elem = dest;
	res->weight = weight;
	res->next = NULL;
}

NodeElem * add_list(NodeElem * l, NodeElem * e)
{
	e->next = l;
	return e;
}

void delete_from_list(NodeElem ** l, Node * n)
{
    NodeElem * current = *l;
    NodeElem * previous = NULL;

 	while(current != NULL)
 	{
 		printf("parcours de liste %c \n", current->elem->name);
 		if(equals(current->elem, n))
		{
			printf("Nodeelem detected\n");
			if(previous != NULL)
				previous->next = current->next;
			else
				*l = current->next;
		}
		previous = current;
		current = current->next;
 	}
}

int in_list(NodeElem * l, Node * n)
{
	NodeElem * tmp = l;
	while(tmp != NULL)
	{
		if(equals(tmp->elem, n))
			return 1;
		tmp = tmp->next;
	}
	return 0;
}

void print_list(NodeElem * tete)
{
	if(tete != NULL)
	{
		printf("-> [%c] ",tete->elem->name);
		print_list(tete->next);
	}
}