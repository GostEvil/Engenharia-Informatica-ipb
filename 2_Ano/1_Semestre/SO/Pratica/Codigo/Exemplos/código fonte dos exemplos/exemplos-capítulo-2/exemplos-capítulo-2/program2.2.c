#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
 int shmid, *ptr;
 
 // show the virtual addresses of the pointer variable
 printf("PARENT: &ptr = %p\n", &ptr);

 // create a private shared memory zone for one integer
 shmid=shmget(IPC_PRIVATE, sizeof(int), 00600);
 
 // attach a virtual address (chosen by the OS) to the zone
 ptr=(int*)shmat(shmid, NULL, 0);
 
 // show the virtual address of the shared memory zone
 printf("PARENT: ptr = %p\n", ptr);
 
 // write something in the shared memory zone and show it
 *ptr=1; printf("PARENT (before fork): *ptr = %d\n", *ptr);
 
 // create a CHILD that is going to access the shared memory zone
 if (fork()==0) { 	
    // show that the virtual address of the pointer is still the same
    printf("CHILD: &ptr = %p\n", &ptr); 	

    // show that the virtual address of the zone is still the same
    printf("CHILD: ptr = %p\n", ptr);
    
    // write something diferent in the shared memory zone and show it
    *ptr=2; printf("CHILD (before exit): *ptr = %d\n", *ptr);

    // detach from the shared memory zone and exit
    shmdt(ptr); exit(0); 
 }
 
 // wait for the CHILD to die and then show the shared memory content
 wait(NULL); printf("PARENT (after wait): *ptr = %d\n", *ptr);
 
 // detach from the shared memory zone, ask its removal and exit
 shmdt(ptr); shmctl(shmid, IPC_RMID, 0); return(0);
}
