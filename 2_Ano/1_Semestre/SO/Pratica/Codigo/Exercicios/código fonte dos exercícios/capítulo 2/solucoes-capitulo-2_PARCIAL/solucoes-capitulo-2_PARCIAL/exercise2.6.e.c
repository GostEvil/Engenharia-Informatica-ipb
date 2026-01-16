// 2.6.e

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/types.h>

int sum(int min, int max)
{
 int result=0, i;

 for (i=min; i<=max; i++)
     result += i;

 return(result);
}

int main()
{
 int shmid_sums, *ptr_sums;
 int i, sum_final=0, status, j;
 
 shmid_sums=shmget(IPC_PRIVATE, 10*sizeof(int), 00600);
 ptr_sums=(int*)shmat(shmid_sums, NULL, 0);
 
 for (i=0; i<10; i++) {
 	if (fork() == 0) { // i'th CHILD
 		ptr_sums[i]=sum(i*10+1, i*10+10);
 		exit(i); // note the exit status ...
    }
 }
 
 // PARENT

 for (i=0; i<10; i++){
	wait(&status); // blocking waiting
	j = WEXITSTATUS(status);
 	sum_final = sum_final + ptr_sums[j];
 }
 
 printf("%i\n", sum_final); 
 shmctl(shmid_sums, IPC_RMID, 0);

 return(0);
}
