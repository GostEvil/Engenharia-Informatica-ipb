// compile with "gcc -O0 toc1.c -o toc1.exe -lm"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <sys/time.h>

#define SIZE  30000
#define SIZE2 3000

int main (int argc, char **argv)
{
	int i, j, c=1;
	int aa[SIZE], bb[SIZE], cc[SIZE], dd[SIZE], ee[SIZE];
	int *xx=(int*)malloc(SIZE*SIZE*sizeof(int));
	double a1, a2, a3, a4, a5, yy;
	
	struct timeval begin, end;
	unsigned long elapsed1, elapsed2;

	////////////////////////////////////////////////////////////////////
	gettimeofday(&begin, 0);
	
	for (i=0; i<SIZE; i++)
		aa[i] = aa[i] + bb[i] * c;
		
	gettimeofday(&end, 0);
	elapsed1 = (end.tv_sec*1e6 + end.tv_usec) - (begin.tv_sec*1e6 + begin.tv_usec);
	printf("\nwithout loop unrolling:\t\t%lu micro-seconds\n", elapsed1);
	
	gettimeofday(&begin, 0);
	
	for (i=0; i<SIZE; i+=3){
		aa[i] = aa[i] + bb[i] * c;
		aa[i+1] = aa[i+1] + bb[i+1] * c;
		aa[i+2] = aa[i+2] + bb[i+2] * c;
	}
	
	gettimeofday(&end, 0);
	elapsed2 = (end.tv_sec*1e6 + end.tv_usec) - (begin.tv_sec*1e6 + begin.tv_usec);
	printf("with loop unrolling:\t\t%lu micro-seconds (speedup: %.2f (%.0f%%))\n", elapsed2, ((double)elapsed1/(double)elapsed2), (((double)elapsed1/(double)elapsed2)-1.0)*100.0);

	////////////////////////////////////////////////////////////////////
	gettimeofday(&begin, 0);
	
	for (i=0; i<SIZE; i++)
		cc[i] = aa[i] + bb[i];
	for (i=0; i<SIZE; i++)
		dd[i] = ee[i] + cc[i];
		
	gettimeofday(&end, 0);
	elapsed1 = (end.tv_sec*1e6 + end.tv_usec) - (begin.tv_sec*1e6 + begin.tv_usec);
	printf("\nwithout loop fusion:\t\t%lu micro-seconds\n", elapsed1);		

	gettimeofday(&begin, 0);
	
	for (i=0; i<SIZE; i++){
		cc[i] = aa[i] + bb[i];
		dd[i] = ee[i] + cc[i];
	}
	
	gettimeofday(&end, 0);
	elapsed2 = (end.tv_sec*1e6 + end.tv_usec) - (begin.tv_sec*1e6 + begin.tv_usec);
	printf("with loop fusion:\t\t%lu micro-seconds (speedup: %.2f (%.0f%%))\n", elapsed2, ((double)elapsed1/(double)elapsed2), (((double)elapsed1/(double)elapsed2)-1.0)*100.0);

	////////////////////////////////////////////////////////////////////
	gettimeofday(&begin, 0);
	
	for (i=0; i<SIZE; i+=3){
		cc[i] = aa[i] + bb[i];
		cc[i+1] = aa[i+1] + bb[i+1];
		cc[i+2] = aa[i+2] + bb[i+2];						
		dd[i] = ee[i] + cc[i];
		dd[i+1] = ee[i+1] + cc[i+1];
		dd[i+2] = ee[i+2] + cc[i+2];						
	}
	
	gettimeofday(&end, 0);
	elapsed2 = (end.tv_sec*1e6 + end.tv_usec) - (begin.tv_sec*1e6 + begin.tv_usec);
	printf("with loop fusion + unrolling:\t%lu micro-seconds (speedup: %.2f (%.0f%%))\n", elapsed2, ((double)elapsed1/(double)elapsed2), (((double)elapsed1/(double)elapsed2)-1.0)*100.0);
		
	////////////////////////////////////////////////////////////////////
	gettimeofday(&begin, 0);
	
	for (i=0; i<SIZE; i++)
		if (i == 0)
			aa[i] = 0;
		else if (i == SIZE-1)
			aa[i] = SIZE-1;
		else
			aa[i] += 8;
			
	gettimeofday(&end, 0);
	elapsed1 = (end.tv_sec*1e6 + end.tv_usec) - (begin.tv_sec*1e6 + begin.tv_usec);
	printf("\nwithout loop peeling:\t\t%lu micro-seconds\n", elapsed1);			

	gettimeofday(&begin, 0);
	
	aa[0] = 0;
	for (i=1; i<SIZE-1; i++)
		aa[i] += 8;
	aa[SIZE-1] = SIZE-1;
	
	gettimeofday(&end, 0);
	elapsed2 = (end.tv_sec*1e6 + end.tv_usec) - (begin.tv_sec*1e6 + begin.tv_usec);
	printf("with loop peeling:\t\t%lu micro-seconds (speedup: %.2f (%.0f%%))\n", elapsed2, ((double)elapsed1/(double)elapsed2), (((double)elapsed1/(double)elapsed2)-1.0)*100.0);

	////////////////////////////////////////////////////////////////////	
	gettimeofday(&begin, 0);
	
	for (i=0; i<SIZE; i++){
		a1 += a2;
		a3 = a1;
		a4 = a5;
	}
	
	gettimeofday(&end, 0);
	elapsed1 = (end.tv_sec*1e6 + end.tv_usec) - (begin.tv_sec*1e6 + begin.tv_usec);
	printf("\nwith dependencies:\t\t%lu micro-seconds\n", elapsed1);
	
	gettimeofday(&begin, 0);
	
	for (i=0; i<SIZE; i++){
		a1 += a2;
		a4 = a5;
		a3 = a1;
	}
	
	gettimeofday(&end, 0);
	elapsed2 = (end.tv_sec*1e6 + end.tv_usec) - (begin.tv_sec*1e6 + begin.tv_usec);
	printf("without dependencies:\t\t%lu micro-seconds (speedup: %.2f (%.0f%%))\n", elapsed2, ((double)elapsed1/(double)elapsed2), (((double)elapsed1/(double)elapsed2)-1.0)*100.0);
		
	////////////////////////////////////////////////////////////////////
	gettimeofday(&begin, 0);
	
	for (i=0; i<SIZE2; i++)
		for (j=0; j<SIZE2; j++)
			xx[j*SIZE2+i]=0;	
			
	gettimeofday(&end, 0);
	elapsed1 = (end.tv_sec*1e6 + end.tv_usec) - (begin.tv_sec*1e6 + begin.tv_usec);
	printf("\n2D column-major access:\t\t%lu micro-seconds\n", elapsed1);

	gettimeofday(&begin, 0);
	
	for (i=0; i<SIZE2; i++)
		for (j=0; j<SIZE2; j++)
			xx[i*SIZE2+j]=0;			
			
	gettimeofday(&end, 0);
	elapsed2 = (end.tv_sec*1e6 + end.tv_usec) - (begin.tv_sec*1e6 + begin.tv_usec);
	printf("2D raw-major access:\t\t%lu micro-seconds (speedup: %.2f (%.0f%%))\n", elapsed2, ((double)elapsed1/(double)elapsed2), (((double)elapsed1/(double)elapsed2)-1.0)*100.0);

	////////////////////////////////////////////////////////////////////	
	
	gettimeofday(&begin, 0);
	
	yy = 0;
	for (i=0; i<SIZE; i++)
		yy += pow(i, 3);
		
	gettimeofday(&end, 0);		
	elapsed1 = (end.tv_sec*1e6 + end.tv_usec) - (begin.tv_sec*1e6 + begin.tv_usec);
	printf("\nexponentiation with pow:\t%lu micro-seconds\n", elapsed1);

	gettimeofday(&begin, 0);
	
	yy = 0;
	for (i=0; i<SIZE; i++)
		yy += i * i * i;
		
	gettimeofday(&end, 0);
	elapsed2 = (end.tv_sec*1e6 + end.tv_usec) - (begin.tv_sec*1e6 + begin.tv_usec);
	printf("exponentiation with product:\t%lu micro-seconds (speedup: %.2f (%.0f%%))\n", elapsed2, ((double)elapsed1/(double)elapsed2), (((double)elapsed1/(double)elapsed2)-1.0)*100.0);

}
