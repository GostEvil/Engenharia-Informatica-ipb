// 5.9

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define N 10
#define N_THREADS 2
#define TARGET 3

int *A;
long total_count = 0;
pthread_mutex_t total_mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *arg){
    long i = (long)arg, count = 0;
    for(int j=i*(N/N_THREADS); j<(i+1)*(N/N_THREADS); j++)
        if(A[j]==TARGET) count++;
    pthread_mutex_lock(&total_mutex);
    total_count += count;
    pthread_mutex_unlock(&total_mutex);
    pthread_exit(NULL);
}

int main(){
    pthread_t tids[N_THREADS];

    A = (int *)malloc(N*sizeof(int));
    srandom(getpid());
    for(int i = 0; i < N; i++){
        A[i] = random() % 5;
        printf("%d\n", A[i]);
    }
    
    for(long i = 0; i < N_THREADS; i++)
        pthread_create(&tids[i], NULL, thread_func, (void *)i);
    
    for(int i = 0; i < N_THREADS; i++)
        pthread_join(tids[i], NULL);

    printf("count=%ld\n", total_count);

    free(A);
    pthread_mutex_destroy(&total_mutex);
    return 0;
}
