#include <cstdlib>
#include <iostream>
#include <string>
#include "bigint.h"

int main(int argc, char ** argv) {
  if (argc != 2) return EXIT_FAILURE;

  Bigint bi(argv[1]);

  for (int i=0; i < 3; i++) {
    std::cout << bi.get();
    fflush(stdout);
    std::cout << "sqrt=" << bi.sqrt() << std::endl;
  }
  return EXIT_SUCCESS;
}
