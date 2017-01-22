#include <cstdlib>
#include <iostream>
#include <math.h>
#include <string>
#include "bigint.h"

int main(int argc, char ** argv) {
  std::cout << "Finding difference between square of sum of first 100 natural numbers and sum of the squares of first 100 natural numbers..." << std::endl;
  int sum = 0, sumofsqrs = 0, i;
  for (i = 1; i <= 100; i++) {
    sum += i;
    sumofsqrs += pow(i, 2);
  }

  // get square of sum
  std::stringstream stream1;
  stream1 << sum;
  Bigint sqrofsum = Bigint(stream1.str());
  sqrofsum.pow(2);

  // answer
  std::stringstream stream2;
  stream2 << sumofsqrs;
  std::cout << "performing " << sqrofsum.get() << "-" << stream2.str() << std::endl;
  sqrofsum.subtract(stream2.str());
  std::cout << "Difference = " << sqrofsum.get() << std::endl;

  return EXIT_SUCCESS;
}
