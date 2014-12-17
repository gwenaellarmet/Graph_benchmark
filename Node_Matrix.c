#include "Node_Matrix.h"

Node * nnouv(char name)
{
	Node * n = malloc(sizeof(Node));
	n->index = 0;
	n->name = name;
        n->tag = 0;
	return n;
}

int equals(Node * n1, Node * n2)
{
	return (n1->name == n2->name && n1->index == n2->index);
}
