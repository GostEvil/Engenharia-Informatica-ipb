// 2.2

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void count(int min, int max)
{
 for (int i=min; i<=max; i++) {
     printf("%d : %d\n", getpid(), i);
     sleep(1);
 }
}

int main()
{
 int shmid; char *flag;
 
 shmid=shmget(IPC_PRIVATE, sizeof(char), 00600);
 flag=(char*)shmat(shmid, NULL, 0);
 *flag=0; // 0 => parent turn; 1 => child turn

 if (fork()==0) { // Child
     
     while(*flag != 1); // wait for my turn
     count(4,6);
     *flag = 0; // pass turn to parent

     while(*flag != 1); // wait for my turn
     count(10,12);
     *flag = 0; // pass turn to parent

     exit(0);
 }

 count(1,3);
 *flag = 1; // pass turn to child

 while(*flag != 0); // wait for my turn
 count(7,9);
 *flag = 1; // pass turn to child

 while(*flag != 0); // wait for my turn
 count(13,15);

 shmctl(shmid, IPC_RMID, NULL);	
 
 return(0);
}
