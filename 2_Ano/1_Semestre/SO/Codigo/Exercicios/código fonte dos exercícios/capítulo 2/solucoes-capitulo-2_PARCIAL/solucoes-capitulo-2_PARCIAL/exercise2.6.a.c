// 2.6.a

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
 int shmid_counter, *ptr_counter;
 int i, sum_final=0;
 
 shmid_sums=shmget(IPC_PRIVATE, 10*sizeof(int), 00600);
 ptr_sums=(int*)shmat(shmid_sums, NULL, 0);
 
 shmid_counter=shmget(IPC_PRIVATE, sizeof(int), 00600);
 ptr_counter=(int*)shmat(shmid_counter, NULL, 0);
 *ptr_counter=0;
 
 for (i=0; i<10; i++) {
 	if (fork() == 0) { // i'th Child
 		ptr_sums[i]=sum(i*10+1, i*10+10);
 		(*ptr_counter)++; // RACE CONDITION
 		exit(0);
    }
 }
 
 // PARENT

 while (*ptr_counter != 10); // busy waiting
 
 for (i=0; i<10; i++)
 	sum_final = sum_final + ptr_sums[i];
 
 printf("%i\n", sum_final); 
 shmctl(shmid_sums, IPC_RMID, 0);
 shmctl(shmid_counter, IPC_RMID, 0);
 
 return(0);
}
