#ifndef _LIST_H_
#define _LIST_H_

typedef struct strlist
{
	int value;
	struct strlist *next;
}Liste;

Liste *create();
Liste *addElmt(Liste *l, int e);

#endif
