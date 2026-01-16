#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
 int fd1, fd2;
 char word1[10]="ABC\n", word2[10]="";
 
 fd1=open("myfile", O_WRONLY);
 fd2=open("myfile", O_RDONLY);
 
 write(fd1, word1, 4);
 read(fd2, word2, 4);
 
 printf("word1: %s\n", word1);
 printf("word2: %s\n", word2);
 
 return(0);
}
