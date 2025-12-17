#include <stdio.h>
// block 1 (additional headers files)
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void generate_fibonacci(int N, long int *F)
{
 int n;
 F[0]=0; F[1]=1;
 for (n=2; n<N; n++) F[n] = F[n-1] + F[n-2];
}

void show_fibonacci(int N, long int *F)
{
 int n;
 for (n=0; n<N; n++) printf("%ld ", F[n]);
 printf("\n");
}

int main()
{
 int N, i; long int *F;
 int status, total_odds=0;

 scanf("%d", &N);
 // block 2 (code)
 F=(long int*)malloc(N*sizeof(long int));
 generate_fibonacci(N, F);
 show_fibonacci(N, F);
 
 for (i=0; i<N; i++) {
	// block 3 (code)
	if (fork() == 0) 		
		exit(F[i] % 2);
 }
 
 // block 4 (code)
 while(wait(&status)!=-1)
	total_odds += WEXITSTATUS(status);
 printf("total_odds: %d\n", total_odds);
 
 return(0);
}
