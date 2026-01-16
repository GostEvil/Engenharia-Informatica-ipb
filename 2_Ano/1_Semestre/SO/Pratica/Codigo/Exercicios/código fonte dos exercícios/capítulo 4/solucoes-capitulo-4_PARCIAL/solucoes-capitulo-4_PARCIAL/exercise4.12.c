// 4.12

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void count(int min, int max) { 
 int i;
 for(i=min; i<=max; i++)
	 printf("pid = %d\t i = %d\n", getpid(), i);
}

int main() {
 int fd1[2], fd2[2]; char c;

 pipe(fd1); pipe(fd2);

 if (fork()==0) {
	 close(fd1[1]); close(fd2[0]);
	 
	 read(fd1[0], &c, 1); // self-block
	 count(4,6);
	 write(fd2[1], &c, 1); // unlock parent
	 
	 read(fd1[0], &c, 1); // self-block
	 count(10,12);
	 write(fd2[1], &c, 1); // unlock parent
	 
	 exit(0);
 }

 close(fd1[0]); close(fd2[1]);
 
 count(1,3);
 write(fd1[1], &c, 1); // unlock child

 read(fd2[0], &c, 1); // self-block
 count(7,9);
 write(fd1[1], &c, 1); // unlock child

 read(fd2[0], &c, 1); // self-block
 count(13,15);
 
 return(0);
}
