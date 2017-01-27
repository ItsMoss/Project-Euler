#include <cstdlib>
#include <iostream>


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
  std::cout << "Finding the 10001st prime number..." << std::endl;
  
  int count = 0, num;

  for (num = 0; count != 10001; num++) {
    if (is_prime(num)) count++;
  }

  std::cout << "10001st prime=" << num-1 << std::endl;
  return EXIT_SUCCESS;
}
