#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list {
	int PID;
	struct list * next;
};

int insertList (List * lst, int PID)
{
	List * new_element = (List *) malloc(sizeof(List));
	if (new_element!=NULL)
	{
		new_element->PID = PID;
		new_element->next = lst;
		return 0;
	}
	return -1;
}

int removeList (List * lst)
{
	if (lst != NULL)
	{
		// Retira do final ou do início? Se retirar
		// do final, os processos mais antigos podem
		// nunca serem executados.
	}
	return -1;
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