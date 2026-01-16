#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
 int fd1, fd2;
 char word1[10]="";
 int x;
 
 fd1=open("myfile", O_RDONLY);
 fd2=open("myfile", O_RDONLY);
 
 read(fd1, word1, 4);
 read(fd2, &x, 4);
 
 printf("word1: %s\n", word1);
 printf("x: %d\n", x);
 
 return(0);
}
