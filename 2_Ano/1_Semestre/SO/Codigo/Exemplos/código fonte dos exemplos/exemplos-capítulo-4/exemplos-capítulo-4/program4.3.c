#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
 int fd1, fd2;
 char word1[10]="", word2[10]="";
 
 fd1=open("myfile", O_RDONLY);
 fd2=open("myfile", O_RDONLY);
 
 read(fd1, word1, 2);
 read(fd1, word2, 2);
 
 printf("word1: %s\n", word1);
 printf("word2: %s\n", word2);
 
 return(0);
}
