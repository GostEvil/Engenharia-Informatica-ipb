#include <stdio.h>

int main()
{
 FILE *fp; long ret;
 char word[10]="abc\n";
 
 fp=fopen("myfile", "w"); printf("fp : %p\n", fp);
 ret=fwrite(word, 1, 4, fp); printf("ret : %ld\n", ret);
 // fclose(fp);
 
 return(0);
}
