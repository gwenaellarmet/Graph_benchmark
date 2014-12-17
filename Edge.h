#ifndef _EDGE_H_
#define _EDGE_H_

#include <stdio.h>
#include <stdlib.h>
#ifdef GMATRICE
    #include "Node_Matrix.h"
#else
    #include "Node_list.h"
#endif

typedef struct Edge
{
    int weight;
    Node * from;
    Node * to;
    struct Edge * next;
}Edge;

Edge * createEdgeList();
Edge * addEdge(Edge * l, Node * from, int weight, Node * to);
void printEdge(Edge * e);
void printEdgeList(Edge * e);

#endif
