// 3.9.iii

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main()
{
 int pid, num_pids_even=0, num_pids_odd=0, i;
 int semid; struct sembuf sop[1]; union semun { int val; } arg;

 semid=semget(IPC_PRIVATE, 3, 00600);
 // semaphore 0 : to block even Children
 // semaphore 1 : to block odd Children
 // semaphore 2: to block the Parent
 arg.val=0; for (i=0; i<2; i++) semctl(semid, i, SETVAL, arg);
 sop[0].sem_flg=0; 
  
 for (i=0; i<10; i++) {
	pid=fork();
	if (pid == 0) {
                // await for parent
		if (getpid() % 2 == 0) {
			sop[0].sem_num=0; sop[0].sem_op=-1; semop(semid, sop, 1);
		}
		else {
			sop[0].sem_num=1; sop[0].sem_op=-1; semop(semid, sop, 1);
		}
		printf("%d\n", getpid());
                // unblock parent
		sop[0].sem_num=2; sop[0].sem_op=-1; semop(semid, sop, 1);
		exit(0);
	}
	if (pid % 2 == 0) num_pids_even ++; else num_pids_odd ++;
 }

 // set parent semaphore to the number of children with even PID
 arg.val=num_pids_even; semctl(semid, 2, SETVAL, arg);
 for (i=0; i<num_pids_even; i++) { // unblock children with even PID
		sop[0].sem_num=0; sop[0].sem_op=+1; semop(semid, sop, 1);
 }
 // await for children with even PID
 sop[0].sem_num=2; sop[0].sem_op=0; semop(semid, sop, 1);

 arg.val=num_pids_odd; semctl(semid, 2, SETVAL, arg);
 for (i=0; i<num_pids_odd; i++) { // unblock children with odd PID
		sop[0].sem_num=1; sop[0].sem_op=+1; semop(semid, sop, 1);
 } 
 // await for children with even PID
 sop[0].sem_num=2; sop[0].sem_op=0; semop(semid, sop, 1);

 printf("parent: done\n");
 semctl(semid, 0, IPC_RMID, NULL);
 return(0);	
}
