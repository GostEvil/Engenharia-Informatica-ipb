// 5.8

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum(int min, int max){
    int i, result = 0;
    for(i=min; i<=max; i++) result += i;
    return result;
}

int total_sum = 0;
pthread_mutex_t sum_mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *arg){
    long i = (long)arg;
    int partial_sum = sum(i*10+1, i*10+10);
    pthread_mutex_lock(&sum_mutex);
    total_sum += partial_sum;
    pthread_mutex_unlock(&sum_mutex);
    pthread_exit(NULL);
}

int main(){
    long i;
    pthread_t tids[10];
    
    for(i=0; i<10; i++)
        pthread_create(&tids[i], NULL, thread_func, (void *)i);
    
    for(i=0; i<10; i++){
        pthread_join(tids[i], NULL);
    }
    
    printf("total sum: %d\n", total_sum);
    pthread_mutex_destroy(&sum_mutex);
    return 0;
}
