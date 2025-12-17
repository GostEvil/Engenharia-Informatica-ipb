// 1.1.a

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
 int i=0;

 fork();

 while (1) {
        printf("pid:%d i:%d\n", getpid(), i++); 
 }
 
 return(0);
}
