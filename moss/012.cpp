#include <cstdlib>
#include <iostream>
#include "bigint.h"


bool is_zero_string(const std::string & str) {
  for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
    if (*it != '0') return false;
  }
  return true;
}


int factor_count(Bigint bi) {
  int ans = 2;
  Bigint temp = bi;
  temp.sqrt();
  for (Bigint i = Bigint(2); i <= temp; i+=1) {
    std::string mod = bi % i.get();
    if (is_zero_string(mod)) {
      ans++;
      if (i != temp) ans++;
    }
  }
  return ans;
}


int main(int argc, char ** argv) {
  std::cout << "Finding the first triangle number to have 500 factors...";
  std::cout << std::endl;

  Bigint i = Bigint();
  int count = 0, incr = 0;
  while (count < 500) {
    count = factor_count(i);
    std::cout << "factor_count(" << i.get() << ")=";
    std::cout << count << std::endl;
    incr+=1;
    i+=incr;
  }

  std::cout << "Answer is " << i.get() << std::endl;

  return EXIT_SUCCESS;
}
