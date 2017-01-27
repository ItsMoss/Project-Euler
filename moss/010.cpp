#include <cstdlib>
#include <iostream>
#include <vector>
#include "bigint.h"

bool is_prime(int number) {
  if (number < 2) return false;
  if (number == 2) return true;
  int stop = number;
  for (int curr = 2; curr <= stop; curr++) {
    if (number % curr == 0) return false;
    stop = number / curr + 1;
  }
  return true;
}

int main(int argc, char ** argv) {
  std::cout << "Finding the sum of all prime numbers below 2 million..." << std::endl;
  
  Bigint ans;
  for (int i = 0; i < 2000000; i++) {
    if (is_prime(i)) {
      std::stringstream stream;
      stream << i;
      ans.add(stream.str());
    }
  }

  std::cout << "Sum = " << ans.get() << std::endl;
  return EXIT_SUCCESS;
}
