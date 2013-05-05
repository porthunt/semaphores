/* 1011141 - 1010310 */

#include <stdio.h>
#include <stdlib.h>

typedef struct semaphore {
	int value;
	int flag;
	List * procs;
} Sem;

Sem * police[10];

int do_semInit (int SemaphoreID, int Value) 
{
	if (SemaphoreID >= 0 && SemaphoreID <= 9 && police[SemaphoreID]->flag == 0) 
	{
			police[SemaphoreID]->value = Value;
			police[SemaphoreID]->procs = (List *) malloc(sizeof(List));
			police[SemaphoreID]->flag = 1;
			return 0;
	}
	return -1;
}

int do_semStatus (int SemaphoreID, int * Value, int * NimBlocked)
{
	if (SemaphoreID >= 0 && SemaphoreID <= 9 && police[SemaphoreID]->flag == 0) 
	{
		Value = police[SemaphoreID]->value;
		NimBlocked = /*count_list(SemaphoreID->procs);*/
		return 0;
	}
	return -1;
}

int do_semUp (int SemaphoreID)
{
	if (SemaphoreID >= 0 && SemaphoreID <= 9 && police[SemaphoreID]->flag == 0) 
	{
		police[SemaphoreID]->value += 1;
		if (/*count_list(SemaphoreID->procs)*/ > 0)
		{
			/* WAKEUP(police[SemaphoreID->procs->first) */
		}
		return 0;
	}
	return -1;
}

int do_semDown (int SemaphoreID)
{
	if (SemaphoreID >= 0 && SemaphoreID <= 9 && police[SemaphoreID]->flag == 0) 
	{
		if (police[SemaphoreID]->value == 0)
		{
			/* SLEEP(GETPID) */
		}
		else
		{
			police[SemaphoreID]->value -= 1;
			/* EXEC */
		}
		return 0;
	}
	return -1;
}
