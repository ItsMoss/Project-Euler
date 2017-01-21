#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv) {
  long num, i, ans = 1;
  if (argc > 1) {
    char * endptr;
    num = strtol(argv[1], &endptr, 10);
    if (argv[1] == endptr) {
      fprintf(stderr, "Error. Input argument must be a positive integer.\n");
      return EXIT_FAILURE;
    }
  }
  else num = 20;
  fprintf(stdout, "Finding the least common multiple of numbers 1-%ld...", num);
  for (i = num / 2 + 1; i <= num; i++) {
    fprintf(stdout, "i=%ld, ans=%ld\n", i, ans); 
    ans *= i;
  }
  fprintf(stdout, "LCM = %ld\n", ans);
  return EXIT_SUCCESS;
}
