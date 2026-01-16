// 4.15.a

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int sum(int min, int max)
{
 int result=0, i;

 for (i=min; i<=max; i++)
     result += i;

 return(result);
}

int main()
{
 int fd[2], sum_child, sum_parent;

 pipe(fd);

 if ( fork()==0 ) { // Child
    sum_child=sum(51,100);
    close(fd[0]);
    write(fd[1],&sum_child,sizeof(int));
    exit(0);
 }

 sum_parent=sum(1,50);
 close(fd[1]);
 read(fd[0],&sum_child,sizeof(int)); // blocking reading
 printf("%d\n", sum_parent + sum_child);
}
