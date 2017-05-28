#include <cstdlib>
#include <iostream>
#include <string>
#include "bigint.h"


bool is_zero_string(const std::string & str) {
  for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
    if (*it != '0') return false;
  }
  return true;
}


int * collatz_length(Bigint * bi) {
  // convert input to known type
  Bigint num = *bi;

  // determine collatz length
  Bigint len(1);  // this is also the term number
  Bigint one(1);

  std::cout << "sequence: " << num.get();
  fflush(stdout);
  while (num != one) {
    if (!is_zero_string(num % 2)) {  // odd term
      // 3n + 1 
      num *= 3;
      num += 1;
    }
    else {	// even term
      // n / 2
      num /= 2;
    }

    // increment length
    len += 1;

    std::cout << ", " << num.get();
    fflush(stdout);
  }
  std::cout << std::endl;
  fflush(stdout);

  int * answer = new int;
  std::istringstream  ss(len.get());
  ss >> *answer;
  
  return answer;
}


int main(int argc, char ** argv) {
  if (argc != 2) return EXIT_FAILURE;

  Bigint bi(argv[1]);
  int * length;

  length = collatz_length(&bi);
  std::cout << "Collatz sequence length=" << *length << std::endl;

  delete length;

  return EXIT_SUCCESS;
}
