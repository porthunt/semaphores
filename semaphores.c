/************************** | Objetivos | ****************************
*												                  *
* - Chamadas devem ser feitas no Process Manager.	                  *
* - Gerenciar até 10 semáforos (SemaphoreID 0,9).	                  *
* - Semáforos devem ser nicializados com semInit.	                  *
* - semStatus retorna o valor atual do semáforo passado              *
*   (1o parâmetro) e o número de processos bloqueados por ele.       *
* - Tratamento de erro, verificar se SemaphoreID [0,9],              *
*   senão, systemcall deve retornar -1 e setar errno com EINVAL.     *
*												                  *
**********************************************************************
*												                  *
* - Todo o gerenciamento de semáforos deve ser implementado          *
*   através de envio de mensagens entre processos, ou seja, usando   *
*   as funções mini_send, mini_rec e mini_notify (kernel/proc.c).    *
*												                  *
*********************************************************************/

int semDown (int SemaphoreID) {

}

int semUp (int SemaphoreID) {

}

int semInit (int SemaphoreID, int Value) {

}

int semStatus (int SemaphoreID, int* Value, int* NimBlocked) {

}