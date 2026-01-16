#include <stdio.h>
// block 1 (additional headers files)
#include <stdlib.h>
#include <unistd.h>

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

 scanf("%d", &N);
 // block 2 (code)
 F=(long int*)malloc(N*sizeof(long int));
 generate_fibonacci(N, F);
 show_fibonacci(N, F);
 
 for (i=0; i<N; i++) {
	// block 3 (code)
	if (fork() == 0) {
		if (F[i] % 2 !=0) printf("%ld\n", F[i]);
		exit(0);
	}
 }
 
 return(0);
}
