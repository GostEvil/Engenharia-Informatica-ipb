// 2.3

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

int main() {
 int num, shmid, *shmaddr;

 shmid=shmget(IPC_PRIVATE, 2*sizeof(int), 00600);
 shmaddr=(int*)shmat(shmid, NULL, 0);
 shmaddr[1]=0; // 0: child turn; 1: parent turn
 
 if (fork()==0) {
     do {
         scanf("%d", &num);
         shmaddr[0]=num;
         shmaddr[1]=1; // unblock parent
         while (shmaddr[1]!=0); // block child
         num=shmaddr[0];
         printf("%d\n", num);
     } while (num!=1);
     shmctl(shmid, IPC_RMID, 0);
     exit(0);
 }

 do {
     while(shmaddr[1]!=1); // block parent
     num=shmaddr[0];
     num=num+1;
     shmaddr[0]=num;
     shmaddr[1]=0; // unblock child
 } while (num!= 1);

 return(0);
}
