// 4.15.b

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
 int fd[2]; char c;

 shmid=shmget(IPC_PRIVATE, sizeof(int), 00600);
 shmaddr=(int*)shmat(shmid, NULL, 0);

 pipe(fd);

 if ( fork()==0 ) { // Child
    shmaddr[0]=sum(51,100);
    close(fd[0]);
    write(fd[1],&c,1);
    exit(0);
 }

 sum_parent=sum(1,50);
 close(fd[1]);
 read(fd[0],&c,1); // blocking waiting
 printf("%d\n", sum_parent + shmaddr[0]);
 shmctl(shmid, IPC_RMID, 0);
}
