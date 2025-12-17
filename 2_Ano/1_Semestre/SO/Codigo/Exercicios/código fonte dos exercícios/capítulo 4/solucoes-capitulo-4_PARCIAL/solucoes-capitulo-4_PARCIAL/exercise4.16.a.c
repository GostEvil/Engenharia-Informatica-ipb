// 4.16.a

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
 int fd[2], i, sum_partial, sum_final=0;
 
 pipe(fd);
 
 for (i=0; i<10; i++) {
 	if (fork() == 0) { // i'th CHILD
 		sum_partial=sum(i*10+1, i*10+10);
 		close(fd[0]); write(fd[1],&sum_partial,sizeof(int));
 		exit(0);
    }
 }
 
 // PARENT

 close(fd[1]);
 for (i=0; i<10; i++) {
     read (fd[0],&sum_partial,sizeof(int)); // blocking reading
 	sum_final = sum_final + sum_partial;
 }
 
 printf("%i\n", sum_final); 
}
