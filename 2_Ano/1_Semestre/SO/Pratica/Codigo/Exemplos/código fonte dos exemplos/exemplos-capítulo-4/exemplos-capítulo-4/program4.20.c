#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
 int fd, num;
 
 mkfifo("/tmp/myfifo", 00666); 
 chmod("/tmp/myfifo", 00666);
 
 if (fork()==0) {
     fd=open("/tmp/myfifo", O_WRONLY);
     do {
         scanf("%d", &num);
         write(fd, &num, sizeof(int));
     } while (num != 0);
     exit(0);
 }
 
 fd=open("/tmp/myfifo", O_RDONLY);
 do {
     read(fd, &num, sizeof(int));
     printf("%d\n", num);
 } while (num != 0);

 remove("/tmp/myfifo");
 return(0);
}
