// 4.13.b

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
 int fd1[2], fd2[2], num;
 
 pipe(fd1); pipe(fd2);
 
 if (fork()==0) {
     close(fd1[0]); close(fd2[1]);
     do {
         scanf("%d", &num);
         write(fd1[1], &num, sizeof(int));
         read(fd2[0], &num, sizeof(int));
         printf("%d\n", num);
     } while (num != 1);
     exit(0);
 }

 close(fd1[1]); close(fd2[0]);
 do {
     read(fd1[0], &num, sizeof(int));
     num ++;
     write(fd2[1], &num, sizeof(int));
 } while (num != 1);

 return(0);
}
