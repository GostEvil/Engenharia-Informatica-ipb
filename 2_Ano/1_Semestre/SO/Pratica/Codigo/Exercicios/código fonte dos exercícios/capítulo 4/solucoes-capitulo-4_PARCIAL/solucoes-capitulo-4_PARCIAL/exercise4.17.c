// 4.17

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int fd[11][2];

void close_fds_not_needed(int i) {
 int j;
 
 for (j=0; j<11; j++) {
     if (j == i) close(fd[j][1]);
     else if (j == (i+1)%11) close(fd[j][0]);
     else { close(fd[j][0]); close(fd[j][1]); }
 }
}

int main()
{
 int i, sum=0;

 for (i=0; i<11; i++)
     pipe(fd[i]);

 for (i=1; i<11; i++)
     if (fork()==0) { // Child
         close_fds_not_needed(i);
         read(fd[i][0], &sum, sizeof(int));
         sum = sum + (i*i);
         //printf("Child %d: sum = %d\n", i, sum);    
         write(fd[(i+1)%11][1], &sum, sizeof(int));
         exit(0);
     }

 close_fds_not_needed(0);
 write(fd[1][1], &sum, sizeof(int));
 read(fd[0][0], &sum, sizeof(int));
 printf("%d\n", sum);
 
 return(0);
}
