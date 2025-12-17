// 2.1.a

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
   printf("CHILD PID: %d\n", getpid());
   *flag=1; // unblock parent
   exit(0);
 }

 while (*flag != 1); // block parent
 printf("PARENT PID: %d\n", getpid());
 shmctl(shmid, IPC_RMID, NULL);
 
 return(0);
}
