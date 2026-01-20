// 5.4

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum(int min, int max){
    int i, result = 0;
    for(i=min; i<=max; i++) result += i;
    return result;
}

int partial_sum[10];

void *thread_func(void *arg){
    long i = (long)arg;
    partial_sum[i] = sum(i*10+1, i*10+10);
    pthread_exit(NULL);
}

int main(){
    long i;
    pthread_t tids[10];
    int total_sum = 0;
    
    for(i=0; i<10; i++)
        pthread_create(&tids[i], NULL, thread_func, (void *)i);
    
    for(i=0; i<10; i++){
        pthread_join(tids[i], NULL);
        total_sum += partial_sum[i];
    }
    
    printf("totalsum: %d\n", total_sum);
    return 0;
}
