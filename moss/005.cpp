#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <string>
#include "bigint.h"

int main(int argc, char ** argv) {
  Bigint num;
  if (argc > 1) {
    num.add(std::string(argv[1]));
  }
  else num.add(std::string("20"));
  std::cout << "Finding the least common multiple of numbers 1-" << num.get();
  std::cout << "..." << std::endl;
  for (i = num / 2 + 1; i <= num; i++) {
    fprintf(stdout, "i=%ld, ans=%ld\n", i, ans); 
    num.multiply() // need to fix this ish
  }
  fprintf(stdout, "LCM = %ld\n", ans);
  return EXIT_SUCCESS;
}
