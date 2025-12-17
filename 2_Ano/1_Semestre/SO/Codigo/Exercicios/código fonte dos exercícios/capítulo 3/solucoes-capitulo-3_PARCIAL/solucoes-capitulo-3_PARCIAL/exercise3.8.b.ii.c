// 3.8.b.ii

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

int main() {
 int N, *A, i, ret, shmid_A, shmid_odds, *odds;
 int semid; struct sembuf sop[1]; union semun { int val; } arg;
 
 scanf("%d", &N);
 
 shmid_A=shmget(IPC_PRIVATE, N*sizeof(int), 00600);
 A=(int*)shmat(shmid_A, NULL, 0);
 
 shmid_odds=shmget(IPC_PRIVATE, sizeof(int), 00600);
 odds=(int*)shmat(shmid_odds, NULL, 0);
 *odds=0;

 semid=semget(IPC_PRIVATE, 2, 00600);
 // semaphore 0 : to block the Children and the Parent
 // semaphore 1 : to protect the counter
 arg.val=N; semctl(semid, 0, SETVAL, arg);
 arg.val=1; semctl(semid, 1, SETVAL, arg);
 sop[0].sem_flg=0; 
 
 for (i=0; i<N; i++) {
	ret=fork();
	if (ret == 0) {
		sop[0].sem_num=0; sop[0].sem_op=0; semop(semid, sop, 1);
		if (A[i] % 2 != 0) {
			printf("A[%d]: %d : odd\n", i, A[i]);
			sop[0].sem_num=1; sop[0].sem_op=-1; semop(semid, sop, 1);
			(*odds)++;
			sop[0].sem_num=1; sop[0].sem_op=+1; semop(semid, sop, 1);
		}
		sop[0].sem_num=0; sop[0].sem_op=1; semop(semid, sop, 1);
		exit(0);		
	}	 
 }

 srandom(getpid());
 for (i=0; i<N; i++)
	A[i] = random();

 for (i=0; i<N; i++) {
	sop[0].sem_num=0; sop[0].sem_op=-1; semop(semid, sop, 1);
 }	
	 
 for (i=0; i<N; i++) {
	sop[0].sem_num=0; sop[0].sem_op=-1; semop(semid, sop, 1);
 }
 printf("odds: %d\n", *odds);
 shmctl(shmid_A, IPC_RMID, NULL);	
 shmctl(shmid_odds, IPC_RMID, NULL);	
 semctl(semid, 0, IPC_RMID, NULL);

 return(0);	
}
