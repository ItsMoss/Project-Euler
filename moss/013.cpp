#include <fstream>
#include <iostream>
#include <cstdlib>
#include "bigint.h"


int main(int argc, char ** argv) {

  // init answer
  Bigint answer;

  // open up problem13.txt
  std::ifstream ifile("../problem13.txt");

  // read all lines and add up answer along the way
  size_t size = 51;	// for 50 characters + null terminator
  while (ifile.good()) {
    char line[size];
    ifile.getline(line, size);
    answer+=(std::string(line));
  }

  ifile.close();

  // get first 10 digits
  std::string digits = answer.get();
  digits.resize(10);
  std::cout << "Answer is: " << digits << std::endl;

  return EXIT_SUCCESS;
}
