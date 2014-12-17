#ifndef _NODE_MATRIX_H
#define _NODE_MATRIX_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
	int index; //index dans la matrice (0->n)
	char name;
        int tag;
}Node;

Node * nnouv(char name);
int equals(Node * n1, Node * n2);

#endif