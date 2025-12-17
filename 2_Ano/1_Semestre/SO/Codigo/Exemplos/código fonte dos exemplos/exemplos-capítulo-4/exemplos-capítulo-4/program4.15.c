#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
 int fd, i; char c='a';

 fd=creat("myfile", 00600);
 if (fork()==0) c='b';
 
 lockf(fd, F_LOCK, 0);
 for (i=0; i<5; i++) write(fd, &c, 1);
 lockf(fd, F_ULOCK, 0);
 
 return(0);
}
