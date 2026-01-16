#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main()
{

 printf("before exec\n");
 execl("/bin/ls","ls", NULL); // (1)
 // execl("/bin/ls","ls", "-la", NULL); // (2)
 // or execlp("ls", "ls", "-la", NULL); // (3)
 
 // the next code is executed only if the previous "exec" fails
 printf("after exec\n");
 perror("execl"); return(errno);
}

