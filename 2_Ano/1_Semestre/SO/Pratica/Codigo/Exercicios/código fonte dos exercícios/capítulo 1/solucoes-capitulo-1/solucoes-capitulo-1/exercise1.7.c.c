// 1.7.c

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
 int N, *A, i, ret;
 
 scanf("%d", &N);
 A=(int *)malloc(N*sizeof(int));
 
 srandom(getpid());
 for (i=0; i<N; i++)
	A[i] = random();
 
 for (i=0; i<N; i++) {
	ret=fork();
	if (ret == 0) {
		if (A[i] % 2 == 0) {
			printf("A[%d]: %d : even\n", i, A[i]);
			free(A); exit(0);
		}
		else {
			printf("A[%d]: %d : odd\n", i, A[i]);
			free(A); exit(1);
		}
	}	 
 }

 int status, odds=0;
 for (i=0; i<N; i++) {
	 wait(&status);
	 ret=WEXITSTATUS(status);
	 if (ret == 1) odds++;
 }	
 printf("odds: %d\n", odds);
	
 free(A);
 return(0);	
}

