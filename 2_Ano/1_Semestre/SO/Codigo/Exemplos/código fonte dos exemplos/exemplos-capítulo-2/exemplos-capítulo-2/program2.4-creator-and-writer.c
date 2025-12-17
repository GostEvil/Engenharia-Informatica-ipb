#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#define MYKEY 0x00000001

int main()
{
 int shmid, *ptr;
 
 // create a non-private shared memory zone for one integer
 // note: this will fail if the key MYKEY is already in use
 shmid=shmget(MYKEY, sizeof(int), 00600 | IPC_CREAT | IPC_EXCL );

 // attach a virtual address (chosen by the OS) to the zone
 ptr=(int*)shmat(shmid, NULL, 0);

 // write into the shared zone
 *ptr=1;
 
 return(0);
}
