// 5.7.c

#include <stdio.h>
#include <pthread.h>

unsigned long int counter=0;
pthread_mutex_t mutex_main=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_sec=PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *arg){
    for(unsigned long int i=0; i<1000000; i++){
        pthread_mutex_lock(&mutex_sec);
        counter++;
        printf("sec: %ld\n", counter);
        pthread_mutex_unlock(&mutex_main);
    }
}

int main(){
    pthread_t tid;
    
    pthread_mutex_lock(&mutex_sec);
    
    pthread_create(&tid, NULL, thread_func, NULL);
    
    for(unsigned long int i=0; i<1000000; i++){
        pthread_mutex_lock(&mutex_main);
        counter++;
        printf("main: %ld\n", counter);
        pthread_mutex_unlock(&mutex_sec);
    }
    
    pthread_join(tid, NULL);
    
    printf("counter: %lu\n", counter);
    pthread_mutex_destroy(&mutex_main);
    pthread_mutex_destroy(&mutex_sec);
    pthread_exit(NULL);
}
