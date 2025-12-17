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
 int shmid_flag; char *ptr_flag;
 int i;
 
 shmid_sum=shmget(IPC_PRIVATE, sizeof(int), 00600);
 ptr_sum=(int*)shmat(shmid_sum, NULL, 0);
 *ptr_sum = 0;
 
 shmid_flag=shmget(IPC_PRIVATE, 1*sizeof(char), 00600);
 ptr_flag=(char*)shmat(shmid_flag, NULL, 0);
 *ptr_flag = -1;
 
 for (i=0; i<10; i++) {
 	if (fork() == 0) { // i'th Child
		while (*ptr_flag != i); // block this child
 		*ptr_sum=*ptr_sum+(i*i);
 		printf("%d %d\n", i, *ptr_sum); 
 		(*ptr_flag)++; // unblock brother or parent
 		exit(0);
    }
 }
 
 // PARENT
 
 *ptr_flag = 0; // unblock child 0
 while (*ptr_flag != 10); // block parent
  
 printf("%d\n", *ptr_sum); 
 shmctl(shmid_sum, IPC_RMID, 0);
 shmctl(shmid_flag, IPC_RMID, 0);
 
 return(0);
}
