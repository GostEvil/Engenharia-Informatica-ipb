// 5.3.b

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum(int min, int max){
    int i, result = 0;
    for(i=min; i<=max; i++) result += i;
    return result;
}

void *thread_func(void *arg){
    long partial_sum = sum(51, 100);
    pthread_exit((void *)partial_sum);
}

int main(){
    pthread_t tid;
    void *retval;
    long total_sum;
    pthread_create(&tid, NULL, thread_func, NULL);
    total_sum = sum(1, 50);
    pthread_join(tid, &retval);
    total_sum += (long)retval;
    printf("total sum: %ld\n", total_sum);
    pthread_exit(NULL);
}
