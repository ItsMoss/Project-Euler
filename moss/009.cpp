#include <cstdlib>
#include <iostream>
#include <vector>
#include "bigint.h"

bool is_square(int number) {
  int stop = number;
  for (int i = 1; i <= stop; i++) {
    stop = number / i;
    if (i == stop && number % i == 0) return true;
  }
  return false;
}

std::vector<int> * all_squares_below(int limit) {
  std::vector<int> * squares = new std::vector<int>;
  for (int i = 0; i < limit; i++) {
    if (is_square(i)) squares->push_back(i);
  }
  return squares;
}


int main(int argc, char ** argv) {
  std::cout << "Finding Pythagorean triplet where a+b+c=1000..." << std::endl;
  
  std::vector<int> * squares = all_squares_below(1000000);
  int a, b, c, flag = 0;

  for (a = 0; a < (int)squares->size()-2; a++) {
    for (b = 1; b < (int)squares->size()-1; b++) {
      for (c = 2; c < (int)squares->size(); c++) {
        if ((*squares)[a] + (*squares)[b] == (*squares)[c] && a+b+c+3 == 1000) {
	  flag = 1;
	  break;
	}
      }
      if (flag) break;
    }
    if (flag) break;
  }

  std::cout << "Triplet is:" << a+1 << ", " << b+1 << ", " << c+1 << std::endl;
  std::stringstream astream, bstream, cstream;
  astream << a+1;
  bstream << b+1;
  cstream << c+1;
  Bigint ans = Bigint(astream.str());
  ans.multiply(bstream.str());
  ans.multiply(cstream.str());
  std::cout << "Product = " << ans.get() << std::endl;
  delete squares;
  return EXIT_SUCCESS;
}
