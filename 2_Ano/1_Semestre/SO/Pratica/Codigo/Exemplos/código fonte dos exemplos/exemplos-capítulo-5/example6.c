#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define NUM_INCREMENTS 10000000
int counter=0;

pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

void *aThread(void *arg){
    for(int i=0; i<NUM_INCREMENTS; i++){
        pthread_mutex_lock(&counter_mutex);
        counter ++;
        pthread_mutex_unlock(&counter_mutex);
    }
    pthread_exit(NULL);
}

int main(){
    long t;
    pthread_t threads[NUM_THREADS];
    
    /* Create worker threads to perform the increments */
    for(t=0; t<NUM_THREADS; t++)
        pthread_create(&threads[t], NULL, aThread, NULL);
    
    /* Wait for the worker threads to end */
    for(t=0; t<NUM_THREADS; t++)
        pthread_join(threads[t], NULL);
    
    /* Show value of the counter */
    printf("counter is %d: should be %d\n", counter, NUM_THREADS*NUM_INCREMENTS);
    
    pthread_mutex_destroy(&counter_mutex);
    pthread_exit(NULL);
}
