// 5.1.a

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

#define N 1000

int main(){
    pid_t pid;
    
    for(int i=0; i<N; i++){
        pid=fork();
        if(pid==0){exit(0);}
        else if(pid==-1){
            printf("Failed to create process %d\n",i);
            perror("fork"); exit(errno);
        }
    }
    
    while(wait(NULL)!=-1);
    
    return 0;
}
