#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *aThread(void *arg){
    printf("Process %d: new thread: Hello World !\n", getpid()); // A
    pthread_exit(NULL);
}

int main(){
    pthread_t thread_opaque_id;
    int ret;
    
    printf("Process %d: main thread: creating new thread\n", getpid()); // B
    ret = pthread_create(&thread_opaque_id, NULL, aThread, NULL);
    if(ret){
       printf("ERROR; return code from pthread_create() is %d\n", ret);
       exit(ret);
    }
    
    printf("Process %d: main thread: program completed: exiting\n", getpid()); // C
    pthread_exit(NULL);    /* Last thing that main() should do */
}
