#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv) {
 int fd, i; char c=argv[1][0];
 
 fd=open("myfile", O_WRONLY);
 for (i=0; i<5; i++)
     write(fd, &c, 1);
 
 return(0);
}
