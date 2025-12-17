#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
 int fd, i; char c='a';
 // pid_t original_parent_pid=getpid();
 
 fd=creat("myfile", 00600);
 
 if (fork()==0) {
	 c='b';
     // close(fd); fd=open("myfile", O_WRONLY);
     // while (getppid()==original_parent_pid);
 }
 // else wait(NULL);
 for (i=0; i<5; i++) write(fd, &c, 1); 
 
 return(0);
}
