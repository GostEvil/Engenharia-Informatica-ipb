// 5.6

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define N 10
#define N_THREADS 2
#define TARGET 3

int *A;

void *thread_func(void *arg) {
    long i = (long)arg, count = 0;
    for(int j=i*(N/N_THREADS); j<(i+1)*(N/N_THREADS); j++)
        if(A[j]==TARGET) count++;
    pthread_exit((void *)count);
}

int main() {
    pthread_t tids[N_THREADS];
    void *retval;
    long total = 0;

    A = (int *)malloc(N*sizeof(int));
    srandom(getpid());
    for (int i = 0; i < N; i++) {
        A[i] = random() % 5;
        printf("%d\n", A[i]);
    }
    
    for (long i = 0; i < N_THREADS; i++)
        pthread_create(&tids[i], NULL, thread_func, (void *)i);
    
    for (int i = 0; i < N_THREADS; i++) {
        pthread_join(tids[i], &retval);
        total += (long)retval;
    }

    printf("count=%ld\n", total);

    free(A);
    return 0;
}
