#ifndef _PILE_H_
#define _PILE_H_

#include "whatever.h"

typedef struct strpile
{
    struct strpile *next;
    int value;
}Pile;

Pile *pilenouv();
Pile *empiler(Pile *p, int value);
Pile *depiler(Pile *p);
int sommet(Pile *p);
void printPile(Pile *p);

#endif
