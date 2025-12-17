// 2.5.a

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
 int shmid, *shmaddr, sum_parent;

 shmid=shmget(IPC_PRIVATE, 2*sizeof(int), 00600);
 shmaddr=(int*)shmat(shmid, NULL, 0);
 shmaddr[1]=0;

 if ( fork()==0 ) {
    shmaddr[0]=sum(51,100);
    shmaddr[1]=1; // unblocks parent
    exit(0);
 }

 sum_parent=sum(1,50);
 while (shmaddr[1]!=1); // blocks parent
 printf("%d\n", sum_parent + shmaddr[0]);
 shmctl(shmid, IPC_RMID, 0);

 return(0);
}
