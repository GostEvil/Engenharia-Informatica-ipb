// compile with "gcc te1.c -o te1.exe -lm"

#include <stdio.h>
#include <sys/time.h>

int main () { 
  // Start measuring time    
  struct timeval begin, end;
  gettimeofday(&begin, 0);
  // Task 
  int iterations = 1000*1000*1000;
  double sum = 0, add = 1;
  for (int i=0; i<iterations; i++) {
    sum += add; add /= 2.0;
  }
  // Stop measuring time
  gettimeofday(&end, 0);
  // Calculate the elapsed time
  long seconds = end.tv_sec - begin.tv_sec;
  long microseconds = end.tv_usec - begin.tv_usec;
  double elapsed = seconds + microseconds*1e-6;
  
  printf("Result: %.3f\n", sum);
  printf("Time: %.3f seconds.\n", elapsed);
  return 0;
}
