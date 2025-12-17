// 3.6.iii

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
 int i, shmid_sum, *ptr_sum;
 int semid; struct sembuf sop[1];
 union semun { int val; } arg;

 shmid_sum=shmget(IPC_PRIVATE, sizeof(int), 00600);
 ptr_sum=(int*)shmat(shmid_sum, NULL, 0);
 *ptr_sum=0;

 semid=semget(IPC_PRIVATE, 1, 00600);
 arg.val=10; semctl(semid, 0, SETVAL, arg);
 sop[0].sem_flg=0;

 for (i=0; i<10; i++)
     if (fork()==0) { // Child
         (*ptr_sum)+=sum( i*10+1 , i*10+10 ); // RACE-CONDITION
         sop[0].sem_num=0; sop[0].sem_op=-1; semop(semid, sop, 1);    
         exit(0);
     }

 sop[0].sem_num=0; sop[0].sem_op=0; semop(semid, sop, 1); 

 printf("%i\n", *ptr_sum);
 shmctl(shmid_sum, IPC_RMID, NULL);
 semctl(semid, 0, IPC_RMID, NULL);
 
 return(0);
}
