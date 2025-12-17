// 3.6.v

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
 int i, shmid_nums, *ptr_nums;
 int semid; struct sembuf sop[1];
 union semun { int val; } arg;

 shmid_nums=shmget(IPC_PRIVATE, 2*sizeof(int), 00600);
 ptr_nums=(int*)shmat(shmid_nums, NULL, 0);
 ptr_nums[0]=ptr_nums[1]=0;

 semid=semget(IPC_PRIVATE, 1, 00600);
 arg.val=1; semctl(semid, 0, SETVAL, arg);
 sop[0].sem_flg=0;

 for (i=0; i<10; i++)
     if (fork()==0) { // Child
         sop[0].sem_num=0; sop[0].sem_op=-1; semop(semid, sop, 1);    
         ptr_nums[0] += sum( i*10+1 , i*10+10 );
         ptr_nums[1] ++;
         sop[0].sem_num=0; sop[0].sem_op=+1; semop(semid, sop, 1);    
         exit(0);
     }

 while (ptr_nums[1] != 10); // MUTUAL EXCLUSION UNNECESSARY !...

 printf("%i\n", ptr_nums[0]);
 shmctl(shmid_nums, IPC_RMID, NULL);
 semctl(semid, 0, IPC_RMID, NULL);
 
 return(0);
}
