// 3.7.a

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/types.h>

int main()
{
 int i, shmid, *shmaddr;
 int semid; struct sembuf sop[1];
 union semun { int val; } arg;

 shmid=shmget(IPC_PRIVATE, sizeof(int), 00600);
 shmaddr=(int*)shmat(shmid, NULL, 0);
 *shmaddr=0;

 semid=semget(IPC_PRIVATE, 11, 00600);
 arg.val=0;
 for (i=0; i<11; i++)
     semctl(semid, i, SETVAL, arg);
 sop[0].sem_flg=0;

 for (i=1; i<11; i++)
     if (fork()==0) { // Child
        sop[0].sem_num=i; sop[0].sem_op=-1;
		semop(semid, sop, 1);
		// printf("Child %d\n", i-1);    
        (*shmaddr) = (*shmaddr) + (i*i);
        sop[0].sem_num=(i+1)%11; sop[0].sem_op=+1;
		semop(semid, sop, 1);
        exit(0);
     }

 sop[0].sem_num=1; sop[0].sem_op=+1; semop(semid, sop, 1);    
 sop[0].sem_num=0; sop[0].sem_op=-1; semop(semid, sop, 1);    
 printf("%d\n", *shmaddr);
 shmctl(shmid, IPC_RMID, NULL);
 semctl(semid, 0, IPC_RMID, NULL);
 
 return(0);
}
