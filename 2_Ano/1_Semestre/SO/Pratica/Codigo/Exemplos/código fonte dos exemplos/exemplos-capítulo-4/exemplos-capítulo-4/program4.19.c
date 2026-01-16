#include <stdio.h>

int main()
{
 FILE *fp; char c;
 
 fp=popen("ls -la", "r");
 while(!feof(fp)) {
     fscanf(fp, "%c", &c);
     printf("%c",c);
 }
 pclose(fp);
 
 return(0);
}
