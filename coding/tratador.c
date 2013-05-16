/* 1011141 - 1010310 */
#include <stdio.h>
#include <stdlib.h>
#include "tratador.h"
#include "list.h"
#include "glo.h"
#include "mproc.h"

#define MAX 10

struct semaphore {
	int value;
	int flag;
	List * procs;
};

Semaphore * sem[MAX];

int do_semInit (void) 
{
	 int SemaphoreID, int Value;
	 SemaphoreID= m_in.m1_i1;
	 Value=m_in.m1_i2;
	 
	if ((SemaphoreID >= 0) && (SemaphoreID <= MAX-1) && (sem[SemaphoreID]->flag == 0)) 
	{
			sem[SemaphoreID]->value = Value;
			sem[SemaphoreID]->procs = (List *) malloc(sizeof(List));
			sem[SemaphoreID]->flag = 1;
			return 0;
	}
	return -1;
}

int do_semStatus (void)
{
	message m;
	int SemaphoreID,Value,NimBlocked;
	SemaphoreID=m_in.m1_i1;
	
	if ((SemaphoreID >= 0) && (SemaphoreID <= MAX-1) && (sem[SemaphoreID]->flag == 1)) 
	{
		Value = sem[SemaphoreID]->value;
		NimBlocked = countList(SemaphoreID->procs);
		m.m1_i1=Value;
		m.m1_i2=NimBlocked;
		/*Send message(proc,endpoint,message)*/
		
		return 0;
	}
	return -1;
}

int do_semUp (void)
{
	int SemaphoreID;
	SemaphoreID= m_in.m1_i1;
	if ((SemaphoreID >= 0) && (SemaphoreID <= MAX-1) && (sem[SemaphoreID]->flag == 1)) 
	{
		sem[SemaphoreID]->value += 1;
		if (countList(SemaphoreID->procs) > 0)
		{
			int id= removeList(sem[SemaphoreID]->procs);
			mproc[id]->mp_flags = UNPAUSED;
		}
		return 0;
	}
	return -1;
}

int do_semDown (void)
{
	int SemaphoreID;
	SemaphoreID= m_in.m1_i1;
	if ((SemaphoreID >= 0) && (SemaphoreID <= MAX-1) && (sem[SemaphoreID]->flag == 1))
	{
		if (sem[SemaphoreID]->value == 0)
		{
			mproc[who_p]->mp_flags = PAUSED;
			sem[SemaphoreID]->procs=insertList(sem[SemaphoreID]->procs, who_p);
		}
		else
		{
			sem[SemaphoreID]->value -= 1;
		}
		return 0;
	}
	return -1;
}
