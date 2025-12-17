#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHM_KEY 0x00007564
#define SEM_KEY 0x00007564

int main()
{
 int semid, shmid, *shmaddr;
 union semun { int val; } arg;
 
 // create a non-private shared memory zone for one integer
 shmid=shmget(SHM_KEY, sizeof(int), 00600 | IPC_CREAT | IPC_EXCL);
 
 // attach a virtual address (chosen by the OS) to the zone
 shmaddr=(int*)shmat(shmid, NULL, 0);
 
 // access (write) the zone
 *shmaddr=0;
 
 // create a non-private semaphore array with one semaphore
 semid=semget(SEM_KEY, 1, 00600 | IPC_CREAT | IPC_EXCL);
 
 // initialize the semaphore counter to 1
 arg.val=1; semctl(semid, 0, SETVAL, arg);

 return(0);
}
