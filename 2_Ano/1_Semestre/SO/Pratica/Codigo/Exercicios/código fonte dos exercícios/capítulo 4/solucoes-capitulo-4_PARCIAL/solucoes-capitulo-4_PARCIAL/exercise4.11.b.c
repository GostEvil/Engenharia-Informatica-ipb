// 4.11.b

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
 int fd[2]; char c;
 
 pipe(fd);
 
 if (fork() == 0) {
   close(fd[1]);
   read(fd[0], &c, 1); // if CHILD is fast it will block here
   printf("CHILD PID: %d\n", getpid());   
   exit(0);
 }
 
 close(fd[0]);
 printf("PARENT PID: %d\n", getpid());
 write(fd[1], &c, 1); // unblock CHILD if it is blocked
 
 return(0);
}
