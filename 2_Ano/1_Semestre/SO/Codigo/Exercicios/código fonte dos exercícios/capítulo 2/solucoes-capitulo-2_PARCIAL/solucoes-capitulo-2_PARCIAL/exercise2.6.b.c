// 2.6.b

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
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
 int shmid_flags; char *ptr_flags;
 int i, sum_final=0;
 
 shmid_sums=shmget(IPC_PRIVATE, 10*sizeof(int), 00600);
 ptr_sums=(int*)shmat(shmid_sums, NULL, 0);
 
 shmid_flags=shmget(IPC_PRIVATE, 10*sizeof(char), 00600);
 ptr_flags=(char*)shmat(shmid_flags, NULL, 0);
 for (i=0; i<10; i++) ptr_flags[i]=0;
 
 for (i=0; i<10; i++) {
 	if (fork() == 0) { // i'th Child
 		ptr_sums[i]=sum(i*10+1, i*10+10);
 		ptr_flags[i]=1; // unblock parent
 		exit(0);
    }
 }
 
 // PARENT

 for (i=0; i<10; i++) {
	while (ptr_flags[i] != 1); // block parent
 	sum_final = sum_final + ptr_sums[i];
 }
 
 printf("%i\n", sum_final); 
 shmctl(shmid_sums, IPC_RMID, 0);
 shmctl(shmid_flags, IPC_RMID, 0);
 
 return(0);
}
