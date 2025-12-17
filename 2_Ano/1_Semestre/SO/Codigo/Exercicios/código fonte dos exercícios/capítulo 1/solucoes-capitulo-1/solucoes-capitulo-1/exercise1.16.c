// 1.6

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
 pid_t pid; char *command;

 command=argv[1];
 pid=fork();

 if (pid==0) {
        printf("CHILD will exec %s\n", command);
        execlp(command, command, NULL);
        perror("execlp");
        exit(errno);
 }

 printf("PARENT waiting until CHILD ends\n");
 wait(NULL); // or waitpid(pid, NULL, 0);
 printf("PARENT after CHILD ended\n");
 // ... (other parent tasks)
 return(0);
}
