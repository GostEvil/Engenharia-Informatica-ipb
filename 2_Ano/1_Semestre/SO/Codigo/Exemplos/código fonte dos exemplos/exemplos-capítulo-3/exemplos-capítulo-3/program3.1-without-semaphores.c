#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

int main()
{
 int shmid, *shmaddr, i;
 
 // create a private shared memory zone for one integer
 shmid=shmget(IPC_PRIVATE, sizeof(int), 00600);
 
 // attach a virtual address (chosen by the OS) to the zone
 shmaddr=(int*)shmat(shmid, NULL, 0);
 
 // access (write) the zone
 *shmaddr=0;
 
 // concurrent access to the shared memory zone
 fork();
 
 for(i=1;i<=1000000;i++){
     
     (*shmaddr)++;
     
 }
 
 printf("*shmaddr = %d\n", *shmaddr);

 // removal of the shared memoory zone
 shmctl(shmid, IPC_RMID, NULL);

 return(0);
}
