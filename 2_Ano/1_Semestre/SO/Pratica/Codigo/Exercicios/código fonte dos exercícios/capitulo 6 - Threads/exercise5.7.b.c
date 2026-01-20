// 5.7.b

#include <stdio.h>
#include <pthread.h>

unsigned long int counter=0;
pthread_mutex_t counter_mutex=PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *arg){
    for(unsigned long int i=0; i<1000000; i++){
        pthread_mutex_lock(&counter_mutex);
        counter++;
        pthread_mutex_unlock(&counter_mutex);
    }
}

int main(){
    pthread_t tid;
    
    pthread_create(&tid, NULL, thread_func, NULL);
    
    thread_func(NULL);
    
    pthread_join(tid, NULL);
    
    printf("counter: %lu\n", counter);
    pthread_mutex_destroy(&counter_mutex);
    pthread_exit(NULL);
}
