// 3.2.b

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

void count(int min, int max)
{
 int i;
 for (i=min; i<=max; i++)
     printf("%d : %d\n", getpid(), i);
}

int main()
{
 int semid;
 struct sembuf sop[1];
 union semun { int val; } arg;

 semid=semget(IPC_PRIVATE, 2, 00600);
 // semaphore 0 : to block the Parent
 // semaphore 1 : to block the Child
 arg.val=0;
 semctl(semid, 0, SETVAL, arg);
 semctl(semid, 1, SETVAL, arg);
 sop[0].sem_flg=0;

if (fork()==0) { // Child
     sleep(1);
     sop[0].sem_num=1;sop[0].sem_op=-1; semop(semid,sop,1);    
     count(4,6);
     sop[0].sem_num=0;sop[0].sem_op=+1; semop(semid,sop,1);

     sop[0].sem_num=1;sop[0].sem_op=-1; semop(semid,sop,1);        
     count(10,12);
     sop[0].sem_num=0;sop[0].sem_op=+1; semop(semid,sop,1);

     exit(0);
 }

 count(1,3);
 sop[0].sem_num=1; sop[0].sem_op=+1; semop(semid, sop, 1);    

 sop[0].sem_num=0; sop[0].sem_op=-1; semop(semid, sop, 1);    
 count(7,9);
 sop[0].sem_num=1; sop[0].sem_op=+1; semop(semid, sop, 1);    

 sop[0].sem_num=0; sop[0].sem_op=-1; semop(semid, sop, 1);    
 count(13,15);

 semctl(semid, 0, IPC_RMID, NULL);
 
 return(0);
}
