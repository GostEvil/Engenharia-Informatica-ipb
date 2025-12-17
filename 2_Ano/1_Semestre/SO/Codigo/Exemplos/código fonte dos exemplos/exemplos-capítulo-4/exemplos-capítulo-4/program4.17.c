#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
 int fd, newfd; char c=0x00;
 
 fd=creat("myfile", 00600);
 newfd=dup(fd);
 lseek(newfd, 99, SEEK_SET);
 write(newfd, &c, 1);
 printf("%d\n", (int)lseek(newfd, 0, SEEK_CUR));

 return(0);
}
