// compile with
// gcc -O0 sc1.c -o sc1_O0.exe -lm
// gcc -O1 sc1.c -o sc1_O1.exe -lm
// gcc -O2 sc1.c -o sc1_O2.exe -lm
// gcc -O3 sc1.c -o sc1_O3.exe -lm
// gcc -O3 -funroll-loops sc1.c -o sc1_O3_unroll_loops.exe -lm

#include <stdio.h>

double powern (double d, unsigned n)
{
  double x = 1.0;
  unsigned j;

  for (j = 1; j <= n; j++)
    x *= d;

  return x;
}

int main (void)
{
  double sum = 0.0;
  unsigned i;
  
  for (i = 1; i <= 100000000; i++)
    {
      sum += powern (i, i % 5);
    }

  printf ("sum = %g\n", sum);
  return 0;
}
