#include <stdio.h>
#include <stdlib.h>

#include "list.h"

Liste *create()
{
	return (Liste*)NULL;
}

Liste *addElmt(Liste *l, int e)
{
	Liste *new = malloc(sizeof(struct strlist));
	new->value = e;
	new->next = l;

	return new;
}

void print(Liste *l)
{
	Liste *temp;
	temp = l;

	while(temp != NULL)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
}

int main()
{
	Liste *l = create();
	l = addElmt(l,5);
	l = addElmt(l,2);
	l = addElmt(l,1);
    l = addElmt(l,4);
    l = addElmt(l,10);
    l = addElmt(l,6);

	print(l);

	return 0;
}
