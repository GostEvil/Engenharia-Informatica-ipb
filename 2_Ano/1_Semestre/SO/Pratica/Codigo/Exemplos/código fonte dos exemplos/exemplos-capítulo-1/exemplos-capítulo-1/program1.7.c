#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
 pid_t ret=-1; int i=1, n=2;

 while (i<=n) {
     ret=fork();
     if (ret== 0) {
         printf("CHILD %d ends\n", getpid());
         exit(0);
     }
     printf("PARENT %d continues\n", getpid());
     i++;
 }
 return(0);
}

