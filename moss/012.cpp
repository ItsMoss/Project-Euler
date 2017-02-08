#include <cstdlib>
#include <iostream>
#include "bigint.h"


int factor_count(Bigint bi) {
  int ans = 2;
  Bigint temp = bi;
  temp.sqrt();
  for (Bigint i = Bigint(2); i <= temp; i+=1) {
    if (bi % i.get() == std::string("0")) ans++;
  }
  return ans;
}


int main(int argc, char ** argv) {
  std::cout << "Finding the first triangle number to have 500 factors...";
  std::cout << std::endl;

  // lets start with 500^2 which equals 250000
  Bigint i = Bigint(250000);
  int count = 0;
  while (count < 500) {
    count = factor_count(i);
    i+=1;
  }

  std::cout << "Answer is " << i.get() << std::endl;

  return EXIT_SUCCESS;
}
