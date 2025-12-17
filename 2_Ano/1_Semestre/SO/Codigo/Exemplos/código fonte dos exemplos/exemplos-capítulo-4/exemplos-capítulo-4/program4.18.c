#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
 int fd[2], num;

 pipe(fd);
 if (fork()==0) {
     close(fd[0]); // srandom(getpid());
     do {
         scanf("%d", &num); // num = random() % 10;
         write(fd[1], &num, sizeof(int));
     } while (num != 0);
     exit(0);
 }

 close(fd[1]);
 do {
     read(fd[0], &num, sizeof(int));
     printf("%d\n", num);
 } while (num != 0);
 
 return(0);
}
