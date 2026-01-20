// 5.2.c

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct{float f; char c;} thread_param;

void *thread_func(void *arg){
    thread_param *param = (thread_param *)arg;
    printf("%f\t%c\n", param->f, param->c);
    free(arg);
    pthread_exit(NULL);
}

int main(){
    pthread_t tids[3];
    
    for(int i=0; i<3; i++){
        thread_param *arg = (thread_param *)malloc(sizeof(thread_param));
        arg->f=(float)i;
        arg->c='a'+(int)i;
        pthread_create(&tids[i], NULL, thread_func, arg);
    }
    
    pthread_exit(NULL);
}
