// 1.1.b

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
 int i=0;

 fork();

 while (1) {
        printf("pid:%d i:%d\n", getpid(), i++); 
        sleep(1);
 }
 
 return(0);
}
