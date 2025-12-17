// 1.17.b

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[])
{
 pid_t *pids; int i; char *command;
 
 pids=(pid_t*)malloc((argc-1)*sizeof(pid_t));

 for(i=1; i<=argc-1; i++) {
        command=argv[i];
        pids[i-1]=fork();
        if (pids[i-1]==0) {
                printf("CHILD will exec %s\n", command);
                execlp(command, command, NULL);
                perror("execlp");
                exit(errno);
        }
 }

 printf("PARENT waiting until all CHILDREN end\n");
 for(i=1; i<=argc-1; i++) waitpid(pids[i-1], NULL, 0);
 printf("PARENT after all CHILDREN ended\n");
 // ... (other parent tasks)
 free(pids);
 return(0);
}
