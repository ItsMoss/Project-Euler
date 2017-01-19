#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
  fprintf(stdout, "Summing all multiples of 3 and/or 5 below 1000...\n");
  int n, sum = 0;
  for (n = 3; n < 1000; n++) {
    if (n % 3 == 0 || n % 5 == 0) sum += n;
  }
  fprintf(stdout, "Sum = %d\n", sum);
  return EXIT_SUCCESS;
}
