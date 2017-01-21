#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

bool is_palindrome(std::string str) {
  size_t len = str.length();
  for (size_t i = 0; i < len/2; i++) {
    if (str[i] != str[len-1-i]) return false;
  }
  return true;
}

bool is_palindromic(int number) {
  std::stringstream stream;
  stream << number;
  std::string astring = stream.str();
  return is_palindrome(astring);
}

void print_palindrome(int x, int y) {
  std::cout << "Largest palidromic product = " << x*y << std::endl;
  std::cout << "Factors are " << x << " and " << y << std::endl;
}

int main(int argc, char ** argv) {
  std::cout << "Finding the largest palindromic product of two 3-digit numbers..." << std::endl;
  int max = 0, ii, jj;
  for (int i = 999; i > 99; i--) {
    for (int j = i; j > 99; j--) {
      if (is_palindromic(i*j) && i*j > max) {
        max = i * j;
	ii = i;
	jj = j;
      }
    }
  }
  print_palindrome(ii, jj);
  return EXIT_SUCCESS;
}
