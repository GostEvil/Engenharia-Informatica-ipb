#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

int main()
{
 int semid, shmid, *shmaddr, i;
 struct sembuf sop[1];
 union semun { int val; } arg;
 
 // create a private shared memory zone for one integer
 shmid=shmget(IPC_PRIVATE, sizeof(int), 00600);
 
 // attach a virtual address (chosen by the OS) to the zone
 shmaddr=(int*)shmat(shmid, NULL, 0);
 
 // access (write) the zone
 *shmaddr=0;
 
 // create a private semaphore array with one semaphore
 semid=semget(IPC_PRIVATE, 1, 00600);
 
 // initialize the semaphore counter to 1
 arg.val=1; semctl(semid, 0, SETVAL, arg);
 
 // concurrent access to the shared memory zone
 fork();
 // fork(); // hint: uncomment and check if mutual exclusion is ensured
 
 for(i=1;i<=1000000;i++){
     // entry section (down)
     sop[0].sem_num=0; sop[0].sem_op=-1; sop[0].sem_flg=0; semop(semid, sop, 1);
     // critical section
     (*shmaddr)++;
     // exit section (up)
     sop[0].sem_num=0; sop[0].sem_op=1; sop[0].sem_flg=0; semop(semid, sop, 1);
 }
 
 printf("*shmaddr = %d\n", *shmaddr);

 // removal of the shared memory zone
 shmctl(shmid, IPC_RMID, NULL);

 // removal of the semaphore array (hint: comment and practice ipcs and ipcrm)
 semctl(semid, 0, IPC_RMID, NULL);

 return(0);
}
