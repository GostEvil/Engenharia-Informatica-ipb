// 1.18.b

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
 pid_t pid; int i; pid_t pid_penultimate; char *command;

 for(i=1; i<=argc-1; i++) {
        command=argv[i];
        pid=fork();
        if (pid==0) {
                printf("CHILD will exec %s\n", command);
                execlp(command, command, NULL);
                perror("execlp");
                exit(errno);
        }
        if (i==argc-2)
                pid_penultimate=pid;
 }

 printf("PARENT waiting until penultimate CHILD ends\n");
 waitpid(pid_penultimate, NULL, 0);
 printf("PARENT after penultimate CHILD ended\n");
 // ... (other parent tasks)
 return(0);
}
