// 4.18.a

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
 int N, *A, i, odd, odds, fd[2];
 
 scanf("%d", &N); 
 A=(int*)malloc(N*sizeof(int));
 
 pipe(fd);
 
 srandom(getpid());
 for (i=0; i<N; i++)
	A[i] = random();
 
 for (i=0; i<N; i++) {
	if (fork() == 0) {		
		odd = (A[i] % 2 != 0) ? 1 : 0;
		printf("A[%d]=%d\todd=%d\n", i, A[i], odd);
		close(fd[0]); write(fd[1], &odd, sizeof(int));
		free(A); exit(0);
	}
 }

 close(fd[1]); odds=0;
 for (i=0; i<N; i++) {
     read(fd[0], &odd, sizeof(int));
     odds += odd;
 }
 printf("odds: %d\n", odds);
 
 free(A); return(0);	
}
