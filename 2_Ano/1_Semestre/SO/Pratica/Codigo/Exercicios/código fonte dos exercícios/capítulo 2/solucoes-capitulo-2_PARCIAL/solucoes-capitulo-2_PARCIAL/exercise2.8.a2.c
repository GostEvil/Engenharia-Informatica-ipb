// 2.8.a2 correct solution; has no race conditions

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
 int N, *A, i, ret, shmid_A, shmid_flags; char *flags;
 
 scanf("%d", &N);
 
 shmid_A=shmget(IPC_PRIVATE, N*sizeof(int), 00600);
 A=(int*)shmat(shmid_A, NULL, 0);
 
 shmid_flags=shmget(IPC_PRIVATE, N*sizeof(char), 00600);
 flags=(char*)shmat(shmid_flags, NULL, 0);
 
 srandom(getpid());
 for (i=0; i<N; i++) {
	A[i] = random();
	flags[i] = (char)-1; // mark each flag as not yet changed
 }
 
 for (i=0; i<N; i++) {
	ret=fork();
	if (ret == 0) {
		if (A[i] % 2 == 0) {
			printf("A[%d]: %d : even\n", i, A[i]);
			flags[i]=0; // change flag to even detected
			exit(0);
		}
		else {
			printf("A[%d]: %d : odd\n", i, A[i]);
			flags[i]=1; // change flag to odd detected
			exit(0);
		}
	}	 
 }

 int odds=0;
 for (i=0; i<N; i++) {
	 while(flags[i] == -1); // busy waiting for flag to change
	 odds += flags[i];
 }	
 printf("odds: %d\n", odds);
 shmctl(shmid_A, IPC_RMID, NULL);	
 shmctl(shmid_flags, IPC_RMID, NULL);	
 
 return(0);	
}
