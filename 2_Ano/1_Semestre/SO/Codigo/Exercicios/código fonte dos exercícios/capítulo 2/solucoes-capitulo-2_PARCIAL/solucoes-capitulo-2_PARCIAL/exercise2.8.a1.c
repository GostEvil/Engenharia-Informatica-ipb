// 2.8.a1 incorrect solution; has several race conditions

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
//#include <sys/wait.h>

int main()
{
 int N, *A, i, ret, shmid_A, shmid_counter, *counter;
  
 scanf("%d", &N);
 
 shmid_A=shmget(IPC_PRIVATE, N*sizeof(int), 00600);
 A=(int*)shmat(shmid_A, NULL, 0);
 
 shmid_counter=shmget(IPC_PRIVATE, sizeof(int), 00600);
 counter=(int*)shmat(shmid_counter, NULL, 0);
 *counter=0;
 
 srandom(getpid());
 for (i=0; i<N; i++)
	A[i] = random();
 
 for (i=0; i<N; i++) {
	ret=fork();
	if (ret == 0) {
		if (A[i] % 2 == 0) {
			printf("A[%d]: %d : even\n", i, A[i]);
			exit(0);
		}
		else {
			printf("A[%d]: %d : odd\n", i, A[i]);
			(*counter)++;        // RACE-CONDITION 1
			exit(0);
		}
	}	 
 }

 while (*counter == 0);          // RACE-CONDITION 2
 //while (wait(NULL)!=-1);       // solution to RACE-CONDITION 2
 printf("odds: %d\n", *counter); // RACE-CONDITION 3
 
 shmctl(shmid_A, IPC_RMID, NULL);	
 shmctl(shmid_counter, IPC_RMID, NULL);	
 
 return(0);	
}
