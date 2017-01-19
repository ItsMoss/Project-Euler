#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
  fprintf(stdout, "Finding the sum of all even Fibonacci numbers below 4 million\n");
  int first = 1, second = 2, sum = 3;
  
  fprintf(stdout, "Sum = %d\n", sum);
  return EXIT_SUCCESS;
}
