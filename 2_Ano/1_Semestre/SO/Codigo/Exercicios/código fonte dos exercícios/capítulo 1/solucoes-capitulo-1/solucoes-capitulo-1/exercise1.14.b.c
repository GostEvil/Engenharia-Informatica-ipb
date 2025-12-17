// 1.14.b

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
 pid_t pid;
 char *command;

 command=argv[1];
 pid=fork();

 if (pid==0) {
        printf("CHILD will exec \" %s \"\n", command);
        execlp(command, command, NULL);
        perror("execlp");
        exit(errno);
 }

 printf("PARENT after the child creation\n");
 // ... (other parent tasks)
 return(0);
}
