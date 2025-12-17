#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
 printf("before fork\n"); // (1)
 //printf("pid %d: before fork\n", getpid()); // (2)
 //printf("pid %d (ppid %d): before fork\n", getpid(), getppid()); // (3)
 fork();
 fork();
 printf("after fork\n"); //(1)
 //printf("pid %d: after fork\n", getpid()); //(2)
 //printf("pid %d (ppid %d): after fork\n", getpid(), getppid()); // (3)
 return(0);
}
