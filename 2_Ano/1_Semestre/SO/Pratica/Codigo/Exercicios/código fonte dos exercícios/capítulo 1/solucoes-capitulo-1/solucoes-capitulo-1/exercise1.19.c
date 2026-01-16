// 1.19

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
 pid_t pid; int i;
 char *command;

 for(i=1; i<=argc-1; i++) {
        command=argv[i];
        pid=fork();
        if (pid==0) {
                printf("CHILD will exec %s\n", command);
                execlp(command, command, NULL);
                perror("execlp");
                exit(errno);
        }
        wait(NULL); // or waitpid(pid, NULL, 0);
 }

 printf("PARENT after all CHILDREN ended\n");
 // ... (other parent tasks)
 return(0);
}
