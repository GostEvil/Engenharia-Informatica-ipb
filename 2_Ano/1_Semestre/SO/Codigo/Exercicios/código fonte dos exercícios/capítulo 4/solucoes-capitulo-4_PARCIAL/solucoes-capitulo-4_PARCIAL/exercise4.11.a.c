// 4.11.a

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
 int fd[2]; char c;
 
 pipe(fd);
 
 if (fork() == 0) {
   close(fd[0]);
   printf("CHILD PID: %d\n", getpid());
   write(fd[1], &c, 1); // unblock PARENT if it is blocked
   exit(0);
 }
 
 close(fd[1]);
 read(fd[0], &c, 1); // if PARENT is fast it will block here
 printf("PARENT PID: %d\n", getpid());
 
 return(0);
}
