#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main() {
 int fd, i; char c='a';
 int ret;

 fd=creat("myfile", 00600);
 if (fork()==0) c='b';
 ret=lockf(fd, F_TLOCK, 0);
 if (ret == -1 && (errno == EACCES || errno == EAGAIN)) {
     perror("lockf"); exit(ret);
 }
 for (i=0; i<5; i++) {
	 write(fd, &c, 1);
	 // if (i==0) sleep(1);
 }
 lockf(fd, F_ULOCK, 0);
 
 return(0);
}
