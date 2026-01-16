#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
 pid_t pid1=-1, pid2=-1;

  pid1=fork();
  if (pid1 == 0) {
      printf("first CHILD before exit\n");
      exit(0);
  }

  pid2=fork();
  if (pid2 == 0) {
      printf("second CHILD before getchar\n");
      getchar(); // what would happen without getchar ?
      printf("second CHILD after getchar\n");
      exit(0);
  }

  printf("PARENT before waitpid\n");
  waitpid(pid2, NULL, 0); // PARENT blocks until second CHILD ends
  printf("PARENT after waitpid\n");
  return(0);
}
