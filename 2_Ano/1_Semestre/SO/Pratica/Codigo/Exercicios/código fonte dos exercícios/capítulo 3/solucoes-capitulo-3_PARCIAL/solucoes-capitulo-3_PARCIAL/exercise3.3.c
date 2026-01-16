// 3.3

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/types.h>

int main() {
 int shmid, *shmaddr;
 int semid; struct sembuf sop[1];
 union semun { int val; } arg;

 shmid=shmget(IPC_PRIVATE, sizeof(int), 00600);
 shmaddr=(int*)shmat(shmid, NULL, 0);

 semid=semget(IPC_PRIVATE, 2, 00600);
 // semaphore 0 : to block the Parent
 // semaphore 1 : to block the Child
 arg.val=0; // arg.val=1; 
 semctl(semid, 0, SETVAL, arg);
 semctl(semid, 1, SETVAL, arg);
 sop[0].sem_flg=0; 
 
 if (fork()==0) {
     do {
         scanf("%d", shmaddr);
         // unblock parent
         sop[0].sem_num=0; sop[0].sem_op=+1; semop(semid, sop, 1);
         // block child
         sop[0].sem_num=1; sop[0].sem_op=-1; semop(semid, sop, 1);
         printf("%d\n", *shmaddr);
     } while (*shmaddr!=1);
     shmctl(shmid, IPC_RMID, 0);
     semctl(semid, 0, IPC_RMID, NULL);
     exit(0);
 }

 do {
	 // block parent
     sop[0].sem_num=0; sop[0].sem_op=-1; semop(semid, sop, 1);
     (*shmaddr)++;
     // unblock child
     sop[0].sem_num=1; sop[0].sem_op=+1; semop(semid, sop, 1);
 } while (*shmaddr!=1);

 return(0);
}
