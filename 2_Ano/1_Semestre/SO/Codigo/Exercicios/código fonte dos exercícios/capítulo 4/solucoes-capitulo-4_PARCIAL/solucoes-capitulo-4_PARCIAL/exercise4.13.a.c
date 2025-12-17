// 4.13.a

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
 int fd[2], num;
 
 pipe(fd);
 if (fork()==0) {
     do {
         scanf("%d", &num);
         write(fd[1], &num, sizeof(int));
         read(fd[0], &num, sizeof(int));
         printf("%d\n", num);
     } while (num != 1);
     exit(0);
 }
 
 do {
     read(fd[0], &num, sizeof(int));
     num ++;
     write(fd[1], &num, sizeof(int));
 } while (num != 1);

return(0);
}
