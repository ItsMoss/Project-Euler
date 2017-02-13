#include <cstdlib>
#include <iostream>
#include <string>
#include "bigint.h"

int main(int argc, char ** argv) {
  if (argc != 2) return EXIT_FAILURE;
  std::cout << "Input bigint: " << argv[1] << std::endl;
  Bigint bi(argv[1]);
  for (int i=0; i < 100; i++) {
    std::cout << bi.get() << "%" << i << "=" << bi%i << std::endl;
  }
  return EXIT_SUCCESS;
}
