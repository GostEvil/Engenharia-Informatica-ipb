// 1.15

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
 pid_t pid; int i; char *command;

 for(i=1; i<=argc-1; i++) {
        printf("PARENT is going to create a CHILD\n");
        command=argv[i];
        pid=fork();
        if (pid==0) {
                printf("CHILD will exec %s\n", command);
                execlp(command, command, NULL);
                perror("execlp");
                exit(errno);
        }
 }

 printf("PARENT after the child(s) creation\n");
 // ... (other parent tasks)
 return(0);
}
