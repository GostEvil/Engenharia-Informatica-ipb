#include <stdio.h>
#include <unistd.h>

int main()
{
 pid_t ret=-1;

 fork(); // (1)
 // ret=fork(); // (2)
 printf("ret: %d\n", ret);
 return(0);
}

