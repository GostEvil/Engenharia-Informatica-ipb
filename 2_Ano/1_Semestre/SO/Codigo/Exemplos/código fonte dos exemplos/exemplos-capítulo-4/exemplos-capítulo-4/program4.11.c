#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>

int main() {
 int fd, i; char c='a';

 fd=creat("myfile", 00600);
 if (fork()==0) {
	 c='b';
	 // close(fd); fd=open("myfile", O_WRONLY);
 }
 flock(fd, LOCK_EX);
 for (i=0; i<5; i++) write(fd, &c, 1);
 flock(fd, LOCK_UN);
 
 return(0);
}
