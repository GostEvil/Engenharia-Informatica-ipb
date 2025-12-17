// 4.19.b

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
 int num_evens=0, num_odds=0, pid, i, fd1[2], fd2[2], fd3[3]; char c;

 // pipe fd1 : to block odd Children
 // pipe fd2 : to block even Children
 // pipe fd3 : to block the Parent
 pipe(fd1); pipe(fd2); pipe(fd3);
  
 for (i=0; i<10; i++) {
     pid=fork();
     if (pid == 0) {
         close(fd3[0]);
         if (getpid() % 2 == 0) {
             close(fd2[1]); close(fd1[0]); close(fd1[1]);
             read(fd2[0], &c, sizeof(char));
         }
         else {
             close(fd1[1]); close(fd2[0]); close(fd2[1]);
             read(fd1[0], &c, sizeof(char));
         }
         printf("%d\n", getpid());
         write(fd3[1], &c, sizeof(char));
         exit(0);
     }
     if (pid % 2 == 0) num_evens++; else num_odds++;
 }

 close(fd1[0]); close(fd2[0]); close(fd3[1]);
 
 for (i=0; i<num_evens; i++) { // unblock children with even PID
     write(fd2[1], &c, sizeof(char));
 }
 
 for (i=0; i<num_evens; i++) { // await for children with even PID
     read(fd3[0], &c, sizeof(char));
 }

 for (i=0; i<num_odds++; i++) { // unblock children with odd PID
     write(fd1[1], &c, sizeof(char));
 }
 
 for (i=0; i<num_odds++; i++) { // await for children with odd PID
     read(fd3[0], &c, sizeof(char));
 }
 
 printf("parent: done\n");
 return(0);	
}
