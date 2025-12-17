// 1.20
// the behavior of "mysystem" tries to be similar,
// as much as possible, to the behavior of "system",
// accordingly with the man page of this primitive

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

int mysystem (char *command)
{
 pid_t pid; int state;

 pid=fork();
 if (pid<0) return(errno);
 if (pid == 0) {
	execl("/bin/sh", "sh", "-c", command, NULL);
     exit(127);
 }
 waitpid(pid, &state, 0);
 return(WEXITSTATUS(state));
}

int main()
{
 mysystem("ls -la");
 printf("after mysystem\n");
 return(0);
}
