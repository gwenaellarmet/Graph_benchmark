#include "Pile.h"

Pile *pilenouv()
{
	return (Pile*)NULL;
}

/* ************************************************* */

Pile *empiler(Pile *p, int value)
{
    Pile *new = malloc(sizeof(struct strpile));
    new->value = value;
    new->next = p;

    return new;
}
/* ************************************************* */

Pile *depiler(Pile *p) 
{
    Pile *tmp;

    if(p->next == NULL)
        return NULL;

    tmp = p->next;
    free(p);
    return tmp;
}

/* ************************************************* */

int sommet(Pile *p) 
{
    if(p == NULL)
    {   
        printf("Pile vide\n");
        return -1; 
    }   

    else
        return p->value;
}

/* ************************************************** */

void printPile(Pile *p) 
{
    Pile *tmp = p;

    printf("----------PILE----------\n");
    while(tmp != NULL)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}
