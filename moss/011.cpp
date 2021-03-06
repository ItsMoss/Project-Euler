#include <cctype>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "bigint.h"
#define SIZE 100
#define N 4

void remove_space(std::string & str) {
  while (isspace(str[0])) str.erase(str.begin());
}

int parse_number(std::string & str) {
  remove_space(str);
  int n = 0;
  while (isdigit(str[n])) n++;
  char num_str[n+1] = {};
  strcpy(num_str, str.substr(0, n).c_str());
  str.erase(0, n);
  remove_space(str);
  return atoi(num_str);
}

void init_grid(std::vector<std::string> & from, std::vector<std::vector<int> > & to) {
  for (size_t i = 0; i < from.size(); i++) {
    to.push_back(std::vector<int>());
    while (!from[i].empty()) to[i].push_back(parse_number(from[i]));
  }
}

Bigint horizontal_max_product(const std::vector<std::vector<int> > & grid, int & n_adjacent) {
  if (n_adjacent > (int)grid.front().size()) return Bigint();
  // init max as product of first n_adjacent ints
  Bigint max = Bigint(std::string("1"));
  
  // find max
  for (size_t i = 0; i < grid.size(); i++) {
    for (std::vector<int>::const_iterator it = grid[i].begin() + n_adjacent - 1; it != grid[i].end(); ++it) {
      Bigint curr = Bigint(std::string("1"));
      for (int j = 0; j < n_adjacent; j++) curr *= *(it-j);
      if (curr > max) max = curr;
    }
  }
  return max;
}

Bigint vertical_max_product(const std::vector<std::vector<int> > & grid, int & n_adjacent) {
  if (n_adjacent > (int)grid.size()) return Bigint();
  // init max as product of first n_adjacent
  Bigint max = Bigint(std::string("1"));
  
  // find max
  for (size_t i = 0; i < grid.front().size(); i++) {
    for (std::vector<std::vector<int> >::const_iterator it = grid.begin() + n_adjacent - 1; it != grid.end(); ++it) {
      Bigint curr = Bigint(std::string("1"));
      for (int j = 0; j < n_adjacent; j++) curr *= (*(it-j))[i];
      if (curr > max) max = curr;
    }
  }
  return max;
}

Bigint diag1_max_product(const std::vector<std::vector<int> > & grid, int & n_adjacent) {
  if (n_adjacent > (int)grid.size() || n_adjacent > (int)grid.front().size()) return Bigint();

  Bigint max = Bigint(std::string("1"));

  // find max
  for (size_t i = n_adjacent-1; i < grid.size(); i++) {
    for (size_t j = n_adjacent-1; j < grid.front().size(); j++) {
      Bigint curr = Bigint(std::string("1"));
      for (int count = 0; count < n_adjacent; count++) curr *= grid[i-count][j-count];
      if (curr > max) max = curr;
    }
  }

  return max;
}

Bigint diag2_max_product(const std::vector<std::vector<int> > & grid, int & n_adjacent) {
  if (n_adjacent > (int)grid.size() || n_adjacent > (int)grid.front().size()) return Bigint();

  Bigint max = Bigint(std::string("1"));

  for (size_t i = 0; i < grid.size() - n_adjacent; i++) {
    for (size_t j = n_adjacent-1; j < grid.front().size(); j++) {
      Bigint curr = Bigint(std::string("1"));
      for (int count = 0; count < n_adjacent; count++) curr *= grid[i+count][j-count];
      if (curr > max) max = curr;
    }
  }

  return max;
}


int main(int argc, char ** argv) {
  std::cout << "Finding the greatest product of four adjacent numbers in 20x20 grid..." << std::endl;

  std::ifstream ifile("../problem11.txt");

  // read all lines of input file into vector of strings
  std::vector<std::string> inputdata;
  while (ifile.good()) {
    char line[SIZE];
    ifile.getline(line, SIZE);
    inputdata.push_back(std::string(line));
  }

  ifile.close();

  // convert vector of strings to vector of vector ints
  std::vector<std::vector<int> > grid;
  init_grid(inputdata, grid);

  // find max product L-R
  Bigint answer, max;
  int n = N;
  if ((max = horizontal_max_product(grid, n)) > answer) answer = max;
  
  // find max product U-D
  if ((max = vertical_max_product(grid, n)) > answer) answer = max;

  // find max product diagonal UL-DR
  if ((max = diag1_max_product(grid, n)) > answer) answer = max;

  // find max product diagonal DL-UR
  if ((max = diag2_max_product(grid, n)) > answer) answer = max;

  // (update max product=answer if necessary)

  std::cout << "Greatest product = " << answer.get() << std::endl;

  return EXIT_SUCCESS;
}
