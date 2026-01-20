// 5.1.b

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 1000

void *thread_func(void *arg){pthread_exit(NULL);}

int main(){
    int ret;
    pthread_t tids[N];
    
    for(int i=0; i<N; i++){
        ret = pthread_create(&tids[i], NULL, thread_func, NULL);
        if(ret!=0){
            printf("Failed to create thread %d (error %d)\n", i, ret);
            exit(ret);
        }
    }
    
    pthread_exit(NULL);
}
