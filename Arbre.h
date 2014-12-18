#ifndef _ARBRE_H_
#define _ARBRE_H_

#include "whatever.h"
#include "Edge.h"

typedef struct strarbre
{
    struct strarbre *ag;
    struct strarbre *ad;
    struct strarbre *pere;
    struct Edge *elt;
}Arbre;

Arbre *creerFeuille(Edge *elt);
void afficherArbre(Arbre *a);

#endif
