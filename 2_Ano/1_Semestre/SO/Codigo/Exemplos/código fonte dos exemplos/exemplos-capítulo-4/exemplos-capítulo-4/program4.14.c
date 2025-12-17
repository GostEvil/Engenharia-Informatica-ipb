#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>
#include <stdlib.h>
#include <errno.h>

int main() {
 int fd, i; char c='a';
 int ret;

 fd=creat("myfile", 00600);
 if (fork()==0) {
	 c='b';
	 close(fd); fd=open("myfile", O_WRONLY);
 }
 
 ret=flock(fd, LOCK_EX | LOCK_NB);
 if (ret == -1 && errno == EWOULDBLOCK) { perror("flock"); exit(ret); }
 for (i=0; i<5; i++) {
	 write(fd, &c, 1);
	 //if (i==0) sleep(1);
 }
 flock(fd, LOCK_UN);
 
 return(0);
}
