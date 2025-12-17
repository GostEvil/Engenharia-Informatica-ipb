// 3.9.i

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main()
{
 int pids[10], i;
 int semid; struct sembuf sop[1]; union semun { int val; } arg;

 semid=semget(IPC_PRIVATE, 11, 00600);
 // semaphore 0..9 : to block the Children
 // semaphore 10 : to block the Parent
 arg.val=0; for (i=0; i<11; i++) semctl(semid, i, SETVAL, arg);
 sop[0].sem_flg=0; 
  
 for (i=0; i<10; i++) {
	pids[i]=fork();
	if (pids[i] == 0) {
                // await for parent
		sop[0].sem_num=i; sop[0].sem_op=-1; semop(semid, sop, 1);
		printf("%d\n", getpid());
                // unblock parent
		sop[0].sem_num=10; sop[0].sem_op=+1; semop(semid, sop, 1);
		exit(0);
	}	 
 }

 for (i=0; i<10; i++) { // unblock children with even PID
	if (pids[i] % 2 == 0) {
		sop[0].sem_num=i; sop[0].sem_op=+1; semop(semid, sop, 1);
	}
 }
 
 for (i=0; i<10; i++) { // await for children with even PID
	if (pids[i] % 2 == 0) {
		sop[0].sem_num=10; sop[0].sem_op=-1; semop(semid, sop, 1);
	}
 }

 for (i=0; i<10; i++) { // unblock children with odd PID
	if (pids[i] % 2 != 0) {
		sop[0].sem_num=i; sop[0].sem_op=+1; semop(semid, sop, 1);
	}
 }
 
 for (i=0; i<10; i++) { // await for children with odd PID
	if (pids[i] % 2 != 0) {
		sop[0].sem_num=10; sop[0].sem_op=-1; semop(semid, sop, 1);
	}
 }
 
 printf("parent: done\n");
 semctl(semid, 0, IPC_RMID, NULL);
 return(0);	
}
