#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
 int fd; long ret;
 char word[10]="abc\n";
 
 fd=creat("myfile", 00600); printf("fd : %d\n", fd);
 // ou fd=open("myfile", O_CREAT | O_TRUNC | O_WRONLY, 00600);
 ret=write(fd, word, 4); printf("ret : %ld\n", ret);
 // close(fd);
 return(0);
}
