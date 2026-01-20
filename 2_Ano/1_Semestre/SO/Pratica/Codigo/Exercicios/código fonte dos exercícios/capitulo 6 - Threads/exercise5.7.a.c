// 5.7.a

#include <stdio.h>
#include <pthread.h>

unsigned long int counter=0;

void *thread_func(void *arg){
    for(unsigned long int i=0; i<1000000; i++){
        counter++;
    }
}

int main(){
    pthread_t tid;
    
    pthread_create(&tid, NULL, thread_func, NULL);
    
    thread_func(NULL);
    
    pthread_join(tid, NULL);
    
    printf("counter: %lu\n", counter);
    pthread_exit(NULL);
}
