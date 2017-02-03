#include <cctype>
#include <cstdlib>
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
  const char num_str[n+1] = str.substr(0, n).c_str();
  str.erase(str.begin()+n);
  remove_space(str);
  return atoi(num_str);
}

void init_grid(std::vector<std::string> & from, std::vector<std::vector<int> > & to) {
  for (size_t i = 0; i < from.size(); i ++) {
    to.push_back(std::vector<int>);
    while (!from[i].empty()) to[i].push_back(parse_number(from));
  }
}

Bigint horizontal_max_product(const std::vector<std::vector<int> > & grid, int & n_adjacent) {
  if (n_adjacent > grid.front().size()) return Bigint();
  // init max as product of first n_adjacent ints
  int max = 1;
  for (int i = 0; i < n_adjacent; i++) max *= grid.front()[i];
  // find max
  for (size_t i = 0; i < grid.size(); i++) {
    for (std::vector<int>::const_iterator it = grid[i].begin() + n_adjacent; it != grid[i].end(); ++it) {
      int curr = 1;
      for (int j = 0; j < n_adjacent; j++) curr *= *(it-j);
      if (curr > max) max = curr;
    }
  }
  // return Bigint of max
  return Bigint(max);
}

Bigint vertical_max_product(const std::vector<std::vector<int> > & grid, int & n_adjacent) {
  if (n_adjacent > grid.size()) return Bigint();
  // init max as product of first n_adjacent ints
  int max = 1;
  for (int i = 0; i < n_adjacent; i++) max *= grid[i].front();
  // find max
  for (size_t i = 0; i < grid.front().size(); i++) {
    for (std::vector<std::vector<int> >::const_iterator it = grid.begin() + n_adjacent; it != grid.end(); ++it) {
      int curr = 1;
      for (int j = 0; j < n_adjacent; j++) curr *= (it-j)[i];
      if (curr > max) max = curr;
    }
  }
  // return Bigint of max
  return Bigint(max);
}

Bigint diag1_max_product(const std::vector<std::vector<int> > & grid, int & n_adjacent) {
  if (n_adjacent > grid.size() || n_adjacent > grid.front().size()) retur Bigint();

  int max = 1;
  for (int i = 0; i < n_adjacent; i++) max *= grid[i][i];

  // find max
  return Bigint(max);
}

Bigint diag1_max_product(const std::vector<std::vector<int> > & grid, int & n_adjacent) {
  if (n_adjacent > grid.size() || n_adjacent > grid.front().size()) retur Bigint();

  int max = 1;
  for (int i = 0; i < n_adjacent; i++) max *= grid[n_adjacent-1-i][i];

  // find max
  return Bigint(max);
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
  Bigint answer;
  if ((Bigint max = horizontal_max_product(grid, N)) > answer) answer = max;

  // find max product U-D
  if ((Bigint max = vertical_max_product(grid, N)) > answer) answer = max;

  // find max product diagonal UL-DR
  if ((Bigint max = diag1_max_product(grid, N)) > answer) answer = max;

  // find max product diagonal DL-UR
  if ((Bigint max = diag2_max_product(grid, N)) > answer) answer = max;

  // (update max product=answer if necessary)

  std::cout << "Greatest product = " << answer.get() << std::endl;

  return EXIT_SUCCESS;
}
