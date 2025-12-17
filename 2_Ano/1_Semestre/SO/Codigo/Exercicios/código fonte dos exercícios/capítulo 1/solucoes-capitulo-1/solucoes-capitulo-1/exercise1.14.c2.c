// 1.14.c2

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
 pid_t pid; int i;
 char *command, **parameters;

 command=argv[1]; parameters=&(argv[1]);
 pid=fork();

 if (pid==0) {
        printf("CHILD will exec \"");
        for (i=1; i<= argc-1; i++) printf(" %s", argv[i]);
        printf(" \"\n");
        execvp(command, parameters);
        perror("execvp");
        exit(errno);
 }
 
 printf("PARENT after the child creation\n");
 // ... (other parent tasks)
 return(0);
}
