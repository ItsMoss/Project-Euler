#include <cstdlib>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include "bigint.h"

struct prime_factor {
  int number;
  int count;
};
typedef struct prime_factor prime_factor_t;

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

int find_lowest_prime_factor(int number) {
  int stop = number;
  for (int i = 2; i <= stop; i++) {
    if (number % i == 0 && is_prime(i)) return i;
    stop = number / i + 1;
  }
  return number;
}

void add_unique_factors(std::vector<prime_factor_t> & unique, int toAdd) {
  if (unique.empty()) {
    prime_factor_t pf = {toAdd, 1};
    unique.push_back(pf);
    return;
  }
  if (toAdd == unique.back().number) {
    unique.back().count++;
    return;
  }
  prime_factor_t pf = {toAdd, 1};
  unique.push_back(pf);
  return;
}

void union_of_factors(std::vector<prime_factor_t> & complete, std::vector<prime_factor_t> & toAdd) {
  for (size_t i = 0; i < toAdd.size(); i++) {
    bool contained = false;
    for (size_t j = 0; j < complete.size(); j++) {
      if (toAdd[i].number == complete[j].number) {
        contained = true;
        if (toAdd[i].count > complete[j].count) {
	  complete[j].count = toAdd[i].count;
	}
      }	
    }
    if (!contained) complete.push_back(toAdd[i]);
  }
}

int main(int argc, char ** argv) {
  int x;
  if (argc > 1) {
    if (isdigit(*argv[1])) {
      x = atoi(argv[1]);
    }
    else {
      std::cerr << "Error. Expected integer for input argument." << std::endl;
      return EXIT_FAILURE;
    }
  }
  else x = 20;

  std::cout << "Finding lowest common multiple of numbers 1-" << x << "...";
  std::cout << std::endl;

  std::vector<prime_factor_t> primes;
  for (int i = x/2+1; i <= x; i++) {
    int num = i;
    std::vector<prime_factor_t> num_primes;
    while (num != 1) {
      int factor = find_lowest_prime_factor(num);
      add_unique_factors(num_primes, factor);
      num /= factor;
    }
    union_of_factors(primes, num_primes);
  }

  Bigint ans = Bigint(std::string("1"));
  for (size_t j = 0; j < primes.size(); j++) {
    for (int k = 0; k < primes[j].count; k++) {
      std::stringstream stream;
      stream << primes[j].number;
      ans.multiply(stream.str());
    }
  }

  std::cout << "LCM = " << ans.get() << std::endl;

  return EXIT_SUCCESS;
}
