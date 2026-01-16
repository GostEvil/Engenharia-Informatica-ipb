#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>

int main(int argc, char **argv) {
 int fd, i; char c=argv[1][0];

 fd=open("myfile", O_WRONLY);
 flock(fd, LOCK_EX);
 for (i=0; i<5; i++) write(fd, &c, 1);
 flock(fd, LOCK_UN);
 
 return(0);
}
