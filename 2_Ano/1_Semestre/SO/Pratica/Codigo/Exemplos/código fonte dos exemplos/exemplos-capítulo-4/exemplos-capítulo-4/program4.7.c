#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
 int fd, i; char c='a';

 fd=open("myfile", O_CREAT | O_TRUNC | O_WRONLY, 00600);
 // or fd=creat("myfile", 00600);
 if (fork()==0) c='b';
 for (i=0; i<5; i++) write(fd, &c, 1);
 
 return(0);
}
