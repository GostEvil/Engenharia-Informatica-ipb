// 1.14.a

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
 pid_t pid;
 char command[256];

 scanf("%s", command);
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
