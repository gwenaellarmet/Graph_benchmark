#include "Edge.h"



Edge * createEdgeList()
{
    return (Edge *) NULL;
}

Edge * addEdge(Edge * l, Node * from, int weight, Node * to)
{
    Edge * new = malloc(sizeof(Edge));
    new->from = from;
    new->to = to;
    new->weight = weight;
    new->next = l;
    return new;
}

void printEdge(Edge * e) //FIXME don't print node name when using graph_list structure 
{
    printf("'%c' -- %d -- '%c'\n", e->from->name, e->weight, e->to->name);
}

void printEdgeList(Edge * e)
{
    Edge * tmp = e;
    while(tmp != NULL)
    {
        printEdge(tmp);
        tmp = tmp->next;    
    }
}