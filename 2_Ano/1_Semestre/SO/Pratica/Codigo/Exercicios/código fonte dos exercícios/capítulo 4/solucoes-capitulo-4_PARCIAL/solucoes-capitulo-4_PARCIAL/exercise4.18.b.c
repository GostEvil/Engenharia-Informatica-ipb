// 4.18.b

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
 int N, *A, i, num, odd, odds, fd1[2], fd2[2];
 
 scanf("%d", &N); 
 
 pipe(fd1); pipe(fd2);
  
 for (i=0; i<N; i++) {
	if (fork() == 0) {		
		close(fd1[1]); read(fd1[0], &num, sizeof(int));
		odd = (num % 2 != 0) ? 1 : 0;
		printf("num=%d\todd=%d\n", num, odd);
		close(fd2[0]); write(fd2[1], &odd, sizeof(int));
		exit(0);
	}
 }

 A=(int*)malloc(N*sizeof(int));

 srandom(getpid()); close(fd1[0]);
 for (i=0; i<N; i++) {
	A[i] = random();
	write(fd1[1], &A[i], sizeof(int));
 }

 close(fd2[1]); odds=0;
 for (i=0; i<N; i++) {
     read(fd2[0], &odd, sizeof(int));
     odds += odd;
 }
 printf("odds: %d\n", odds);
 
 free(A); return(0);	
}
