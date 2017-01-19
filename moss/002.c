#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
  fprintf(stdout, "Finding the sum of all even Fibonacci numbers below 4 million\n");
  int first = 1, second = 2, sum = 2;
  int next = first + second;  // 3
  while (next < 4000000) {
    first = second;
    second = next;
    next = first + second;
    if (next % 2 == 0) sum += next;
  }
  fprintf(stdout, "Sum = %d\n", sum);
  return EXIT_SUCCESS;
}
