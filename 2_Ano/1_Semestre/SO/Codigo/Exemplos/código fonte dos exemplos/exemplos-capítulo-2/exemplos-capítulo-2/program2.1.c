#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
 int *ptr;
 
 // show the virtual address of the pointer variable
 printf("PARENT: &ptr = %p\n", &ptr);

 // reserve a dynamic memory block for one integer, and get a pointer to it
 ptr=(int*)malloc(sizeof(int));
  
 // show the virtual address of the dynamic memory block
 printf("PARENT: ptr = %p\n", ptr);
 
 // write something in the dynamic memory block and show it
 *ptr=1; printf("PARENT (before fork): *ptr = %d\n", *ptr);
 
 // create a CHILD that is going to access its own copy of the block
 if (fork()==0) {
    // show that the virtual address of the pointer is still the same
    printf("CHILD: &ptr = %p\n", &ptr);
	 
    // show that the virtual address of the block is still the same
    printf("CHILD: ptr = %p\n", ptr);
	
    // write something diferent in the dynamic memory block and show it
    *ptr=2; printf("CHILD (before exit): *ptr = %d\n", *ptr);
	
    // free the dynamic memory block and exit
    free(ptr); exit(0);
 }
 
 // wait for the CHILD to die and then show the block content
 wait(NULL); printf("PARENT (after wait): *ptr = %d\n", *ptr);
 	
 // free the dynamic memory block and exit
 free(ptr); return(0);
}
