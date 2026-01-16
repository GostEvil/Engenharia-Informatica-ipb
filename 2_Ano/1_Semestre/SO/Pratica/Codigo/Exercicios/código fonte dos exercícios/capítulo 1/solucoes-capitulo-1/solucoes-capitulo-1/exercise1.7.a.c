// 1.7.a

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define N 10

int main()
{
 int A[N]={0,1,2,3,4,5,6,7,8,9}, i, ret;
 
 for (i=0; i<N; i++) {
	ret=fork();
	if (ret == 0) {
		if (A[i] % 2 == 0)
			printf("A[%d]: %d : even\n", i, A[i]);
		else
			printf("A[%d]: %d : odd\n", i, A[i]);
		exit(0);
	}	 
 }
	
 return(0);	
}

