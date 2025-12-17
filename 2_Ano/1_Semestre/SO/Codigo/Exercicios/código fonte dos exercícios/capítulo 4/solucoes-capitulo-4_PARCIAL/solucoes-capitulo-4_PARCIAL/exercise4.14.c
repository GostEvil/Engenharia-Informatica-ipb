// 4.14

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
 int fd1[2], fd2[2], fd3[2], num;

 // pipe fd1 : to block the 1st Child
 // pipe fd2 : to block the 2nd Child
 // pipe fd3 : to block the Parent
 pipe(fd1); pipe(fd2); pipe(fd3);
 
 if (fork()==0) { // 1st child
     close(fd1[1]); close(fd2[0]); close(fd3[0]); close(fd3[1]);
     do {
         scanf("%d", &num);
         write(fd2[1], &num, sizeof(int)); // unblock 2nd child
         read(fd1[0], &num, sizeof(int));  // block 1st child
         printf("%d\n", num);
     } while (num!=2);
     exit(0);
 }

 if (fork()==0) { // 2nd child
     close(fd2[1]); close(fd3[0]); close(fd1[0]); close(fd1[1]);
     do {		 
         read(fd2[0], &num, sizeof(int));  // block 2nd child
         num++;         
         write(fd3[1], &num, sizeof(int)); // unblock parent
     } while (num!=1);     
     exit(0);
 }
 
 close(fd3[1]); close(fd1[0]); close(fd2[0]); close(fd2[1]);
 do { // parent	 
     read(fd3[0], &num, sizeof(int));  // block parent
     num++;     
     write(fd1[1], &num, sizeof(int)); // unblock 1st child
 } while (num!=2);
 
 return(0);
}
