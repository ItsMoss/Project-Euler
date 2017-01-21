#include <cstdlib>
#include <iostream>
#include <string>
#include "bigint.h"

int main(int argc, char ** argv) {
  if (argc != 3) return EXIT_FAILURE;
  std::cout << "Operating on " << argv[1] << " and " << argv[2] << "..." << std::endl;
  std::string s1 = std::string(argv[1]);
  std::string s2 = std::string(argv[2]);
  Bigint n1 = Bigint(s1);
  n1.add(s2);
  std::cout << "Resulting sum = " << n1.get() << std::endl;
  std::cout << "Difference of sum = " << n1.subtract(s2) << std::endl;
  // std::cout << "Resulting product = " << n1.multiply(s2) << std::endl;
  // std::cout << "Division of product = " << n1.divide(s2) << std::endl;
  return EXIT_SUCCESS;
}
