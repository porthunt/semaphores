typedef struct semaphore Semaphore;

int do_semInit (int SemaphoreID, int Value);
int do_semStatus (int SemaphoreID, int * Value, int * NimBlocked);
int do_semUp (int SemaphoreID);
int do_semDown (int SemaphoreID);