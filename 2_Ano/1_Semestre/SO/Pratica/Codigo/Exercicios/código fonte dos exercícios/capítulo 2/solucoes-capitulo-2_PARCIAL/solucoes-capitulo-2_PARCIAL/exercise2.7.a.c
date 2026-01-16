// 2.7

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

int main()
{
 int shmid_sum, *ptr_sum;
 int shmid_flags; char *ptr_flags;
 int i;
 
 shmid_sum=shmget(IPC_PRIVATE, sizeof(int), 00600);
 ptr_sum=(int*)shmat(shmid_sum, NULL, 0);
 *ptr_sum = 0;
 
 shmid_flags=shmget(IPC_PRIVATE, 11*sizeof(char), 00600);
 ptr_flags=(char*)shmat(shmid_flags, NULL, 0);
 for (i=0; i<11; i++) ptr_flags[i]=0;
 
 for (i=0; i<10; i++) {
 	if (fork() == 0) { // i'th Child
		while (ptr_flags[i] != 1); // block this child
 		*ptr_sum=*ptr_sum+(i*i);
 		printf("%d %d\n", i, *ptr_sum); 
 		ptr_flags[i+1]=1; // unblock brother or parent
 		exit(0);
    }
 }
 
 // PARENT
 
 ptr_flags[0] = 1; // unblock child 0
 while (ptr_flags[10] != 1); // block parent
  
 printf("%d\n", *ptr_sum); 
 shmctl(shmid_sum, IPC_RMID, 0);
 shmctl(shmid_flags, IPC_RMID, 0);
 
 return(0);
}
