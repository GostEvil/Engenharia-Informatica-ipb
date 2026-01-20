// 5.2.a

#include <stdio.h>
#include <pthread.h>

void *thread_func(void *arg){
    long num = (long)arg;
    printf("%ld\n", num);
    pthread_exit(NULL);
}

int main(){
    long i;
    pthread_t tids[3];
    for(i=0; i<3; i++)
        pthread_create(&tids[i], NULL, thread_func, (void*)i);
    pthread_exit(NULL);
}
