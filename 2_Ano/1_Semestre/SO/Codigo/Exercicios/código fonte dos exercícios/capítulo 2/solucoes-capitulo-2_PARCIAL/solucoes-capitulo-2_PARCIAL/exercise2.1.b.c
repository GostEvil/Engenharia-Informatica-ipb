// 2.1.b

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{	
 int shmid; char *flag;
 
 shmid=shmget(IPC_PRIVATE, sizeof(char), 00600);
 flag=(char*)shmat(shmid, NULL, 0);
 *flag=0;
 
 if (fork() == 0) {   
   while (*flag == 0); // block child
   printf("CHILD PID: %d\n", getpid());
   shmctl(shmid, IPC_RMID, NULL);
   exit(0);
 }

 printf("PARENT PID: %d\n", getpid());
 *flag=1; // unblock child
 
 return(0);
}
