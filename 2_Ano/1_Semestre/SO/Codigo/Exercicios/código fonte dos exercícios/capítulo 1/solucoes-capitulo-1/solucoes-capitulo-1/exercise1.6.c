// 1.6

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
 pid_t original_parent;
	
 original_parent=getpid();
	
 if (fork() == 0) {
   printf("CHILD: before getppid\n");
   
   // CHILD waits until original PARENT ends
   while(getppid()==original_parent)
     printf("CHILD: original PARENT %d is still alive\n", original_parent);
   
   printf("CHILD: after getppid: my PARENT is now %d\n", getppid());
   exit(0);
 }

 printf("PARENT: before getchar\n");
 getchar(); // what could happen without "getchar" ?
 printf("PARENT: after getchar\n");
 return(0);
}
