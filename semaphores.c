/************************** | Objetivos | ***************************
*                                                                   *
* - Chamadas devem ser feitas no Process Manager.	                *
* - Gerenciar até 10 semáforos (SemaphoreID 0,9).	                *
* - Semáforos devem ser nicializados com semInit.	                *
* - semStatus retorna o valor atual do semáforo passado             *
*   (1o parâmetro) e o número de processos bloqueados por ele.      *
* - Tratamento de erro, verificar se SemaphoreID [0,9],             *
*   senão, systemcall deve retornar -1 e setar errno com EINVAL.    *
*												                    *
*********************************************************************
*												                    *
* - Todo o gerenciamento de semáforos deve ser implementado         *
*   através de envio de mensagens entre processos, ou seja, usando  *
*   as funções mini_send, mini_rec e mini_notify (kernel/proc.c).   *
*												                    *
********************************************************************/

#include <stdio.h>
#include <sys/sem.h>

/* int semaforoP(int semId); */
int semDown (int SemaphoreID) {
	struct sembuf semB;
	semB.sem_num = 0;
	semB.sem_op = 1;
	semB.sem_flg = SEM_UNDO;
	semop(SemaphoreID, &semB, 1);
	return 0;
}

/* int semaforoP(int semId); */
int semUp (int SemaphoreID) {
	struct sembuf semB;
	semB.sem_num = 0;
	semB.sem_op = -1;
	semB.sem_flg = SEM_UNDO;
	semop(SemaphoreID, &semB, 1);
	return 0;
}

/* int setSemValue(int semId); */
int semInit (int SemaphoreID, int Value) {
	union semun semUnion;
	semUnion.val = Value;
	return semctl(SemaphoreID, 0, SETVAL, semUnion);
}

int semStatus (int SemaphoreID, int* Value, int* NimBlocked) {

}
