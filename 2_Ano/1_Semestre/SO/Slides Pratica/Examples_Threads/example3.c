#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *aThread(void *arg){
    long tid=(long)arg;
    printf("thread %ld: Hello World !\n", tid);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    long t; int ret;
    
    for(t=0;t<NUM_THREADS;t++){
        printf("thread main: creating thread %ld\n", t);
        pthread_create(&threads[t], NULL, aThread, (void *)t);
    }
    
    // wait for the other threads
    for(t=0; t<NUM_THREADS; t++){
        ret = pthread_join(threads[t], NULL);
        if(ret){
            printf("ERROR; return code from pthread_join() is %d\n", ret);
            exit(ret);
        }
        printf("thread main: joined with thread %ld\n", t);
    }
    
    printf("thread main: program completed: exiting\n"); // (*)
    pthread_exit(NULL);
}
