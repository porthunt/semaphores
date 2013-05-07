#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list {
	int PID;
	struct list * next;
};

List * insertList (List * lst, int PID)
{
	List * new_element = (List *) malloc(sizeof(List));
	if (new_element!=NULL)
	{
		new_element->PID = PID;
		new_element->next = lst;
		return new_element;
	}
	return NULL;
}

List * removeList (List * lst, int PID)
{
	List * kill_element = (List *) malloc(sizeof(List));
	List * tmp = lst;
	List * nav;
	
	if (lst != NULL && kill_element != NULL)
	{
		while (tmp->prox->PID != PID)
		{
			nav = tmp;
			tmp = tmp->prox;
		}
		//RETIRA
	}
	
	return kill_element;
}

int countList (List * lst)
{
	int count=0;
	
	if (lst!=NULL)
	{
		List * pt = lst;
		while (pt->next != NULL)
		{
			count++;
			pt = pt->next;
		}
	}
	
	return ++count;
}
