#include "Arbre.h"

Arbre *creerFeuille(Edge *elt)
{
    Arbre *a;
    a = (Arbre*)malloc(sizeof(struct strarbre));
    a->ag = NULL;
    a->ad = NULL;
    a->pere = NULL;
    a->elt = elt;

    return a;
}

/* **************************************************** */

void afficherArbre(Arbre *a)
{
    if(!a)
        return;

    if(a->ag)
        afficherArbre(a->ag);

    printf("weight: %d\n", a->elt->weight);

    if(a->ad)
        afficherArbre(a->ad);
}
