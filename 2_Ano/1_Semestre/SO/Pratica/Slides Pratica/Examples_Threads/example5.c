//5
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

long squares[NUM_THREADS]; // A
//double squares[NUM_THREADS]; // B

void *aThread(void *arg){
    long tid = (long)arg;
    squares[tid] = tid*tid;
    printf("thread %ld: Hello World !\n", tid);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    long t;

    for(t=0;t<NUM_THREADS;t++){
        printf("thread main: creating thread %ld\n", t);
        pthread_create(&threads[t], NULL, aThread, (void *)t);
    }

    for(t=0; t<NUM_THREADS; t++){
        pthread_join(threads[t], NULL);
        printf("thread main: joined with thread %ld: thread square is: %ld\n", t, squares[t]); // A
        //printf("thread main: joined with thread %ld: thread square is: %f\n", t, squares[t]); // B
    }

    printf("thread main: program completed: exiting\n");
    pthread_exit(NULL); 
}
