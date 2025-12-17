// 1.7.b

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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
		if (A[i] % 2 == 0)
			printf("A[%d]: %d : even\n", i, A[i]);
		else
			printf("A[%d]: %d : odd\n", i, A[i]);
		free(A);
		exit(0);
	}	 
 }
	
 free(A);
 return(0);	
}

