#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
 int n=2, i=1;

 while (i<=n) {
     fork();
     printf("i=%d \t pid=%d\n", i, getpid()); // (1)
     //printf("i=%d \t pid=%d \t ppid=%d\n", i, getpid(), getppid()); // (2)
     i++;
 }
 return(0);
}

