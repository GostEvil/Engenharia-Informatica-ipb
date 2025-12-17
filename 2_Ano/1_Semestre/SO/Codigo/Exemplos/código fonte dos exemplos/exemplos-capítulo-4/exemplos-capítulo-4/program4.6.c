#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
 int fd; char c=0x00;
 
 fd=creat("myfile", 00600); printf("%ld\n", lseek(fd, 0, SEEK_CUR));
 
 lseek(fd, 99, SEEK_SET); //lseek(fd, 99, SEEK_END); //lseek(fd, 99, SEEK_CUR); 
 write(fd, &c, 1); 
 
 //for (int i=0; i<100; i++) write(fd, &c, 1);
 
 printf("%ld\n", lseek(fd, 0, SEEK_CUR));
 
 return(0);
}
