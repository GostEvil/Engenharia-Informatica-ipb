#include <stdio.h>
#include <stdlib.h>

int main()
{
 char command[254];
 
 scanf("%s", command); // for instance, "ls", "ls -la", ...
 system(command);
 printf("after system\n"); // this "printf" executes always
 return(0);
}
