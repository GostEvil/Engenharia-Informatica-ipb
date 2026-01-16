// 1.17.a

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[])
{
 pid_t pid; int i; char *command;

 for(i=1; i<=argc-1; i++) {
        command=argv[i];
        pid=fork();
        if (pid==0) {
                printf("CHILD will exec %s\n", command);
                execlp(command, command, NULL);
                perror("execlp");
                exit(errno);
        }
 }

 printf("PARENT waiting until all CHILDREN end\n");
 while(wait(NULL)!=-1);
 printf("PARENT after all CHILDREN ended\n");
 // ... (other parent tasks)
 return(0);
}
