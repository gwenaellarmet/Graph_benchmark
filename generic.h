#ifndef _GENERIC_H_
#define _GENERIC_H_


#define HEAPSORT  1
#define COUNTING  2
#define INSERTION 3


#ifdef GMATRICE
    #include "Node_Matrix.h"
    #include "graph_matrix.h"
#else
    #include "Node_list.h"
    #include "graph_list.h"
#endif

Graph ReadFromfile(char * nom); /* Creer le graphe décrit dans le fichier "nom" */
void resetTag(Graph * g);
Graph Kruskal(Graph g, int sort);
Graph Prim(Graph * g, int sort);


#endif