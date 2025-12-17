#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
 pid_t ret=-1;

 ret=fork();
 if (ret==0) {
  getchar(); // what would happen without getchar ?
  printf("CHILD %d of the PARENT %d: ending\n", getpid(), getppid());
  exit(0);
 }
 printf("PARENT %d of the CHILD %d: ending\n", getpid(), ret);
 return(0);
}
