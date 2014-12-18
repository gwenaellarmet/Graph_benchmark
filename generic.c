#include "generic.h"

Graph ReadFromfile(char * nom)
{
    int end = 0;
    char line[15];
    int size, weight;
    char name1, name2;
    Graph res;
    Node * n1;
    Node * n2;
    FILE * fd = fopen(nom, "r");
    //lecture de la taille du graphe
    if(fscanf(fd, "%d ", &size) != 1)
    {
        perror("Erreur lors de la lecture");
        exit(1);
    }
    res = grnouv(size);
    
    //lecture des arcs
    while(fscanf(fd, "%c %c %d ", &name1, &name2, &weight) == 3)
    {
        //On récupère n1
        if(!exsname(res, name1))
        {
            n1 = nnouv(name1);
            adjs(&res, n1);
        }
        else
        {
            n1 = getnode(res, name1);
        }
        //on récupère n2
        if(!exsname(res, name2))
        {
            n2 = nnouv(name2);
            adjs(&res, n2);
        }
        else
        {
            n2 = getnode(res, name2);
        }
        adja(&res, n1, n2, weight);
    }
    fclose(fd);
    return res;
}

void resetTag(Graph * g)
{
    int i;
    for(i = 0; i < g->size; i++)
        g->Nodes[i]->tag = 0;
}

Graph Kruskal(Graph g,int sort)
{
    int Nodeadded = 0;
    int i, ens1, ens2;
    int numEnsemble =0;
    Graph res = grnouv(g.size);
    Edge * edges = createEdgeList();
    edges = getEdgeList(g); 
    Node * n1;
    Node * n2;

    //TODO
    if(sort == 1)
        printf("heap\n");//edges = heap(edges);
    else if(sort == 2)
        printf("counting\n");//edges = counting(edges);
    else
        printf("insert\n");//edges = insertion(edges);
    
    while(Nodeadded < g.size && edges != NULL)
    {
        n1 = edges->from;
        n2 = edges->to;
        if(edges->to->tag == 0 && edges->from->tag == 0)//aucun des noeuds n'a été ajouté.
        {
            numEnsemble++;
            edges->from->tag = numEnsemble;
            edges->to->tag = numEnsemble;
            n1 = nnouv(edges->from->name);
            n2 = nnouv(edges->to->name);
            adjs(&res, n1);
            adjs(&res, n2);
            adja(&res, n1, n2, edges->weight);
            Nodeadded += 2;
//             printf("Ajout de 2 noeud\n");
        }
        else if(edges->to->tag == 0)//le noeud to n'est pas dans l'ARPM
        {
            edges->to->tag = edges->from->tag;
            n1 = getnode(res, edges->from->name); //on récupère le noeud ajouté précedemment
            n2 = nnouv(edges->to->name);
            adjs(&res, n2);
            adja(&res, n1, n2, edges->weight);
            Nodeadded++;
//                 printf("Ajout de 1 noeud\n");
        }
        else if(edges->from->tag == 0)// le noeud from n'est pas dans l'ARPM
        {
            edges->from->tag = edges->to->tag;
            n1 = nnouv(edges->from->name);
            n2 = getnode(res, edges->to->name); //on récupère le noeud ajouté précedemment
            adjs(&res, n1);
            adja(&res, n1, n2, edges->weight);
            Nodeadded++;
//                 printf("Ajout de 1 noeud\n");
        }
        else //les deux noeuds appartiennent à des ensemble de noeux ajouté différents.
        {
            n1 = getnode(res, edges->from->name); //on récupère le noeud ajouté précedemment
            n2 = getnode(res, edges->to->name); //on récupère le noeud ajouté précedemment
            ens1 = n1->tag;
            ens2 = n2->tag;
            for(i = 0; i < res.size; i++)
                if(res.Nodes[i]->tag == ens1)
                    res.Nodes[i]->tag = ens2;
            adja(&res, n1, n2, edges->weight);
        }
        edges = edges->next;
    }
    
    if(Nodeadded != g.size)
        printf("Erreur lors de l'algo de kruskal\n"); 
    return res;
}

Graph Prim(Graph * g, int sort) //FIXME graphe de test avec list d'adjacence : |a| -> b -> b ?? problème à l'afficjage seulement
{
    Graph res = grnouv(g->size);
    adjs(&res, g->Nodes[0]);
    g->Nodes[0]->tag = 1; //on marque le noeud ajouté
    Edge * edges;
    Node * n1;
    Node * n2;
    int Nodeadded = 1;

    while(Nodeadded < g->size)
    {
        edges = getNeighboors(g);
        //TODO
        if(sort == 1)
            printf("heap\n");//edges = heap(edges);
        else if(sort == 2)
            printf("counting\n");//edges = counting(edges);
        else
            printf("insert\n");//edges = insertion(edges);

        n1 = getnode(res, edges->from->name);
        n2 = nnouv(edges->to->name);
        edges->to->tag = 1; //on marque le noeud ajouté
        adjs(&res, n2);
        adja(&res, n1, n2, edges->weight);
        Nodeadded++;
    }

    if(Nodeadded != g->size)
        printf("Erreur lors de l'algo de prim\n"); 
    return res;
}
