// 1.14.c1

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
 pid_t pid; int i;
 char *command;

 command=argv[1];
 pid=fork();

 if (pid==0) {
        printf("CHILD will exec \"");
        for (i=1; i<= argc-1; i++) printf(" %s", argv[i]);
        printf(" \"\n");
        switch(argc) {
            case 2: execlp(command, argv[1], NULL);
                    break;
            case 3: execlp(command, argv[1], argv[2], NULL);
                    break;
            case 4: execlp(command, argv[1], argv[2], argv[3], NULL);
                    break;
            //. . .
        }        
        perror("execlp");
        exit(errno);
 }
 
 printf("PARENT after the child creation\n");
 // ... (other parent tasks)
 return(0);
}
