// 5.2.b

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_func(void *arg){
    int *nums = (int *)arg;
    printf("%d\t%d\n", nums[0], nums[1]);
    free(arg);
    pthread_exit(NULL);
}

int main(){
    int i, *nums;
    pthread_t tids[3];
    for(i=0; i<3; i++) {
        nums = (int *)malloc(2*sizeof(int));
        nums[0] = i; nums[1] = i+1;
        pthread_create(&tids[i], NULL, thread_func, nums);
    }
    pthread_exit(NULL);
}
