// 3.6.ii

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
 int shmid_sums, *ptr_sums;
 int i, sum_final=0;
 int semid; struct sembuf sop[1]; union semun { int val; } arg;

 shmid_sums=shmget(IPC_PRIVATE, 10*sizeof(int), 00600);
 ptr_sums=(int*)shmat(shmid_sums, NULL, 0);

 semid=semget(IPC_PRIVATE, 1, 00600);
 arg.val=10; // arg.val=0; 
 semctl(semid, 0, SETVAL, arg);
 sop[0].sem_flg=0;

 for (i=0; i<10; i++)
     if (fork()==0) { // Child
         ptr_sums[i]=sum(i*10+1, i*10+10);
         sop[0].sem_num=0; sop[0].sem_op=-1; //sop[0].sem_op=+1; 
         semop(semid, sop, 1);    
         exit(0);
     }

 sop[0].sem_num=0; sop[0].sem_op=0; semop(semid, sop, 1); 
 // sop[0].sem_num=0; sop[0].sem_op=-1; 
 // for (i=0; i<10; i++) semop(semid, sop, 1);
 for (i=0; i<10; i++) {
 	sum_final = sum_final + ptr_sums[i];
 }

 printf("%i\n", sum_final); 
 shmctl(shmid_sums, IPC_RMID, NULL);
 semctl(semid, 0, IPC_RMID, NULL);
 
 return(0);
}
