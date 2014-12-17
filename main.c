#include <stdlib.h>
#include <stdio.h>

#include "generic.h"
#include "Edge.h"

#ifdef GMATRICE
	#include "Node_Matrix.h"
	#include "graph_matrix.h"
#else
	#include "Node_list.h"
	#include "graph_list.h"
#endif


/* union set pour kruskal */
/* afficher complexité, pseudo code prim/kruskal/tri */
/* schéma etc.. */
/* mesures de perfs, 10 grpahes avec n noeuds (densité de 10%->100%) */
/* n entre 10 et cequ'ilfaut pour que ça se chevauche etc... */

int testGraph()
{
	Graph g = grnouv(3);
	Graph g2;
        Graph g3;
	Node * n1;
	Node * n2;
	Node * n3;
	Node * n4;
        
	n1 = nnouv('a');
	n2 = nnouv('b');
	n3 = nnouv('c');
	n4 = nnouv('x');

	adjs(&g, n1);
	adjs(&g, n2);
	adjs(&g, n3);

	adja(&g, n1, n2, 1); //suppr
	adja(&g, n2, n3, 1); //suppr
	adja(&g, n3, n1, 1);

	pgraph(g);
	printf("\n");
	//suppression de n2, ajout d'arrete depuis n4 (nouveau sommet)
	sups(&g, n2);
	adjs(&g, n4);
	adja(&g, n1, n4, 1);
	adja(&g, n4, n3, 1);
	supa(&g, n4, n3);

	printf("Node b exist ? : %d\n", exs(&g, n2));
	printf("Node x exist ? : %d\n", exs(&g, n4));
	printf("\n");

	printf("Vertex a->c exist ? : %d\n", exa(&g, n1, n3));
	printf("Vertex c->a exist ? : %d\n", exa(&g, n3, n1));
	printf("\n");
	pgraph(g);

	printf("\nGraphe lu depuis le fichier ./graphFile/test.mygraph : \n");
	g2 = ReadFromfile("./graphFile/test.mygraph");
	pgraph(g2);
	g3 = Kruskal(g2);
	pgraph(g3);
	resetTag(&g2);
	g3 = Prim(&g2);
	printf("size of res %d\n",g3.size);
	pgraph(g3);
	resetTag(&g2);
	return 0;
}

void error_choose()
{
	printf("Veuilliez recompiler avec la structure de graphe choisi.\n");
	printf("====== Choix de structure de graphe possible ======\n");
	printf("\"make List  \" => listes  d'adjacence\n");
	printf("\"make Matrix\" => matrice d'adjacence\n");
}

int main()
{

	#if defined(GMATRICE)
		printf("matrice\n");
                testGraph();
	#elif defined(GLISTE) 
		printf("liste\n");
                testGraph();
	#else
		error_choose(); //non atteignable si le makefile est utilisé.
	#endif

	return 0;
}