#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
 pid_t ret;
 
 ret=fork();
 if (ret<0) { perror("fork"); exit(errno); }
 if (ret==0) {
   printf("I am the CHILD %d of the PARENT %d\n", getpid(), getppid());
   exit(0);
 }
 printf("I am the PARENT %d of the CHILD %d\n", getpid(), ret);
 return(0);
}

