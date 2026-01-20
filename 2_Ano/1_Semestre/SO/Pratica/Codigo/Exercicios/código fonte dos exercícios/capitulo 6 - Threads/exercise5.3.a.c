// 5.3.a

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum(int min, int max){
    int i, result = 0;
    for(i=min; i<=max; i++) result += i;
    return result;
}

int partial_sum;

void *thread_func(void *arg){
    partial_sum = sum(51, 100);
    pthread_exit(NULL);
}

int main(){
    pthread_t tid;
    int total_sum;
    pthread_create(&tid, NULL, thread_func, NULL);
    total_sum = sum(1, 50);
    pthread_join(tid, NULL);
    total_sum += partial_sum;
    printf("total sum: %d\n", total_sum);
    pthread_exit(NULL);
}
