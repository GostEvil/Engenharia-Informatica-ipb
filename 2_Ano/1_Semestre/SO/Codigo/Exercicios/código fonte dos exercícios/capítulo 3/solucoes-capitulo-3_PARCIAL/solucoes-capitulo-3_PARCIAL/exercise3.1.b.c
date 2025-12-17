// 3.1.b

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {	
 int semid; struct sembuf sop[1];
 union semun { int val; } arg;
 
 semid=semget(IPC_PRIVATE, 1, 00600);
 // semaphore 0 : to block the Child
 arg.val=0; // arg.val=1; 
 semctl(semid, 0, SETVAL, arg);
 sop[0].sem_flg=0;
 
 if (fork() == 0) {
   sop[0].sem_num=0; sop[0].sem_op=-1; // sop[0].sem_op=0;
   semop(semid, sop, 1);
   printf("CHILD PID: %d\n", getpid());
   semctl(semid, 0, IPC_RMID, NULL);
   exit(0);
 }

 printf("PARENT PID: %d\n", getpid());
 sop[0].sem_num=0; sop[0].sem_op=+1; // sop[0].sem_op=-1;
 semop(semid, sop, 1);
 
 return(0);
}
