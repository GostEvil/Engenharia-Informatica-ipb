#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

int main()
{
 int shmid, *ptr1, *ptr2;
 
 // show the virtual addresses of the pointer variables
 printf("&ptr1 = %p\n", &ptr1);
 printf("&ptr2 = %p\n", &ptr2);

 // create a private shared memory zone for one integer
 shmid=shmget(IPC_PRIVATE, sizeof(int), 00600);
 
 // show the zone identifier (usefull to be later used with ipcrm)
 printf("shmid = %d\n", shmid);
 
 // attach two different virtual addresses (chosen by the OS) to the zone
 ptr1=(int*)shmat(shmid, NULL, 0);
 ptr2=(int*)shmat(shmid, NULL, 0);

 // show that the virtual addresses are really different
 printf("ptr1 = %p\n", ptr1);
 printf("ptr2 = %p\n", ptr2);
 
 // access (write+read) the zone with both virtual addresses 
 *ptr1=1000;
 printf("*ptr2 = %d\n", *ptr2);
 
 // detach the virtual addresses from the zone (allows reusing the pointers)
 //shmdt(ptr1); shmdt(ptr2); 
 
 // remove the zone (hint: comment shcmtl and practice ipcs and ipcrm)
 shmctl(shmid, IPC_RMID, 0);

 return(0);
}
