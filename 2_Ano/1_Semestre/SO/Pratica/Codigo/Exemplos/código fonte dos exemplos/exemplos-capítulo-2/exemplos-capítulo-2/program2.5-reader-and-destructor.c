#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#define MYKEY 0x00000001

int main()
{
 int shmid, *ptr;
 
 // get the identifier of the shared memory zone with key MYKEY
 shmid=shmget(MYKEY, sizeof(int), 0);

 // attach a virtual address (chosen by the OS) to the zone
 ptr=(int*)shmat(shmid, NULL, 0);

 // read the shared zone and show its content
 printf("%d\n", *ptr); 

 // remove the zone (hint: comment shcmtl and practice ipcs and ipcrm)
 shmctl(shmid, IPC_RMID, 0);
 
 return(0);
}
