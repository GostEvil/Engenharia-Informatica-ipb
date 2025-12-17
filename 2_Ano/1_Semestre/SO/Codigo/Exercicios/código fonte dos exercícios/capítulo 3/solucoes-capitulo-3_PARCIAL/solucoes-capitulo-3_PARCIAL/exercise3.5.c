// 3.5

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#include <sys/sem.h>

int sum(int min, int max)
{
 int result=0, i;

 for (i=min; i<=max; i++) result += i;

 return(result);
}

int main()
{
 int shmid, *shmaddr, sum_parent;
 
 int semid;
 struct sembuf sop[1];
 union semun { int val; } arg;

 shmid=shmget(IPC_PRIVATE, sizeof(int), 00600);
 shmaddr=(int*)shmat(shmid, NULL, 0);
 shmaddr[0]=0;
 
 semid=semget(IPC_PRIVATE, 1, 00600);
 // semaphore 0 : to block the Parent
 arg.val=0; // arg.val=1; 
 semctl(semid, 0, SETVAL, arg);
 sop[0].sem_flg=0;

 if ( fork()==0 ) { // Child
    shmaddr[0]=sum(51,100);
    sop[0].sem_num=0; sop[0].sem_op=+1; // sop[0].sem_op=-1;
    semop(semid, sop, 1);
    exit(0);
 }

 sum_parent=sum(1,50);
 sop[0].sem_num=0; sop[0].sem_op=-1; // sop[0].sem_op=0;
 semop(semid, sop, 1);
 printf("%d\n", sum_parent + shmaddr[0]);
 shmctl(shmid, IPC_RMID, 0);
 semctl(semid, 0, IPC_RMID, NULL);

 return(0);
}
