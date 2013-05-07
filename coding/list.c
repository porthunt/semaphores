#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/****************************************************************
*																*
*	Estrutura da lista de processos:							*
*	PID: guarda o ID do projeto.								*
*	next: guarda o ponteiro para o próximo elemento da lista.	*
*																*
****************************************************************/

struct list {
	int PID;
	struct list * next;
};

/****************************************************************
*																*
*	Função: insertList											*
*	Retorno: ponteiro para o novo final da lista.				*
*	Parâmetros:													*
*	lst: lista onde vai ser inserido.							*
*	PID: ID do projeto a ser inserido na lista.					*
*																*
****************************************************************/

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

/****************************************************************
*																*
*	Função: removeList											*
*	Retorno: PID do processo que saiu da lista.					*
*	Parâmetros:													*
*	lst: lista de onde precisa ser retirado.					*
*																*
****************************************************************/

int removeList (List * lst)
{
	List * tmp = lst;
	List * nav = tmp;
	int PID=-1;
	
	if (lst != NULL)
	{
		while (tmp->next != NULL)
		{
			nav = tmp;
			tmp = tmp->next;
		}
		nav->next = tmp->next;
		PID = tmp->PID;
		free(tmp);
		return PID;
	}
	return PID;
}

/****************************************************************
*																*
*	Função: countList											*
*	Retorno: número de processos dentro da lista.				*
*	Parâmetros:													*
*	lst: lista onde vai ser inserido.							*
*																*
****************************************************************/

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
