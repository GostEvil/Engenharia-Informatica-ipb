// mysyscalls-test.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include <mysyscalls/mysyscalls.h>

#define NCHILDREN 10

int main()
{
 long a, b, c;
 scanf("%ld", &a); scanf("%ld", &b);
 printf("lcm(%ld,%ld,1)=%ld\n", a, b, lcm(a,b,1));

 int i, shmid, *ptr;
 shmid=shmget(IPC_PRIVATE, sizeof(int), 00600);
 ptr=(int*)shmat(shmid, NULL, 0); *ptr=0;
 for (i=0; i<NCHILDREN; i++) {
     if (fork()==0) {
         while(*ptr==0); // wait for all siblings to be created
         printf("child %d has %ld siblings\n", getpid(), get_num_siblings(1));
         sleep(1); // postpone termination to allow others to detect me
         exit(0);
     }
 }
 *ptr=1; // tell children all siblings have been created
 while(wait(NULL)!=-1); // wait for all children to die
 return 0;
}
