#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define NUM_THREADS 5

void *aThread(void *arg){
    long tid=(long)arg;
    printf("Process %d: thread %ld: Hello World !\n", getpid(), tid);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    long t;

    for(t=0; t<NUM_THREADS; t++){
        printf("Process %d: thread main: creating thread %ld\n", getpid(), t);
        pthread_create(&threads[t], NULL, aThread, (void *)t);
    }
    
    printf("Process %d: thread main: program completed: exiting\n",getpid());
    pthread_exit(NULL);
}
