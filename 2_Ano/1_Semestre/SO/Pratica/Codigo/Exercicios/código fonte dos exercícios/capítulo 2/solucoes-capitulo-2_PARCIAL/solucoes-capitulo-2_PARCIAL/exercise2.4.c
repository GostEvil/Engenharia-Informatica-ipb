// 2.4

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
 shmaddr[1]=0; // 0: 1st child turn
               // 1: 2nd child turn
               // 2: parent turn
 
 if (fork()==0) { // 1st child
     do {
         scanf("%d", &num);
         shmaddr[0]=num;
         shmaddr[1]=1; // unblock 2nd child
         while (shmaddr[1]!=0); // block 1st child
         num=shmaddr[0];
         printf("%d\n", num);
     } while (num!=2);
     shmctl(shmid, IPC_RMID, 0);
     exit(0);
 }

 if (fork()==0) { // 2nd child
     do {
         while (shmaddr[1]!=1); // block 2nd child
         num=shmaddr[0];
         num=num+1;
         shmaddr[0]=num;
         shmaddr[1]=2; // unblock parent
     } while (num!=1);     
     exit(0);
 }
 
 do { // parent
     while(shmaddr[1]!=2); // block parent
     num=shmaddr[0];
     num=num+1;
     shmaddr[0]=num;
     shmaddr[1]=0;
 } while (num!=2); // unblock 1st child

}
