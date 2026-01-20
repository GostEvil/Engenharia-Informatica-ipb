// 5.5

#include <stdio.h>
#include <pthread.h>

int square_sum = 0; // square_sum will be accessed sequentially, one thread at a time

void *thread_func(void *arg){
    long i = (long)arg;
    square_sum += i * i;
    if(i<10) { // create next thread if n < 10
        pthread_t tid;
        pthread_create(&tid, NULL, thread_func, (void*)(i+1));
        pthread_join(tid, NULL);
    }
    pthread_exit(NULL);
}

int main(){
    long i = 1;
    pthread_t tid;
    pthread_create(&tid, NULL, thread_func, (void*)i); // start the chain with thread 1
    pthread_join(tid, NULL);
    printf("square sum: %d\n", square_sum);
    pthread_exit(NULL);
}
