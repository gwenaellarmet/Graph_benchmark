#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void print(Liste *l);

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

Liste *addElmtOrd(Liste *l, int e)
{
	Liste *tmp;
	Liste *new = malloc(sizeof(struct strlist));
	new->value = e;

	if((l == NULL) || (e <= l->value))
	{
		new->next = l;
		return new;
	}

	else
	{
		tmp = l;
		while(tmp->next != NULL && tmp->next->value <= e)
			tmp = tmp->next;

		print(l);
		//printf("elmt %d\n", tmp->value);
		//printf("'elmt after%d\n'", tmp->next->value);

		new->next = tmp->next;
		tmp->next = new;
		return l;
	}
}

void print(Liste *l)
{
	Liste *temp;
	temp = l;

	while(temp != NULL)
	{
		printf("%d\t", temp->value);
		temp = temp->next;
	}

	printf("\n");
}

int main()
{
	Liste *tmp;
	Liste *l = create();
	int tab[6];
	char c;
	int i;

	while(1)
	{
		printf("Emter a number\n");
		scanf("%d", &i);
		if(i < 0)
			break;

		l = addElmtOrd(l,i);
		printf("Sorted list so far:\n");
		print(l);
	}

	printf("-------------------------------------------------------------------------------\n");
	print(l);

	return 0;
}
