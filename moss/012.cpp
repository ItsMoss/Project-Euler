#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include <vector>
#include "bigint.h"


bool is_zero_string(const std::string & str) {
  for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
    if (*it != '0') return false;
  }
  return true;
}


// THREADED FUNCTION
void * factor_count(void * bi) {  // param: Bigint *, return: int *
  int ans = 2;
  Bigint temp = *((Bigint *)bi);
  temp.sqrt();
  for (Bigint i = Bigint(2); i <= temp; i+=1) {
    std::string mod = *((Bigint *)bi) % i.get();
    if (is_zero_string(mod)) {
      ans++;
      if (i != temp) ans++;
    }
  }
  int * answer = new int;
  *answer = ans;
  return answer;
}


bool all_below(const int & lim, const std::vector<int *> & nums) {
  for (std::vector<int *>::const_iterator it = nums.begin(); it != nums.end(); ++it) {
    if (**it >= lim) return false;
  }
  return true;
}


size_t max_of_vector(const std::vector<int *> & nums) {
  size_t ans = 0;
  for (size_t i = 1; i < nums.size(); i++) {
    if (*(nums[i]) > *(nums[ans])) ans = i;
  }
  return ans;
}


void free_counts(std::vector<int *> & nums) {
  for (std::vector<int *>::iterator it = nums.begin(); it != nums.end(); ++it) {
    delete *it;
  }
}


void print_counts(const std::vector<int *> & counts, const std::vector<Bigint> & bis) {
  for (size_t i = 0; i < counts.size(); i++) {
    std::cout << "factor_count(" << bis[i].get();
    std::cout << ")=" << *(counts[i]) << std::endl;
  }
}


int main(int argc, char ** argv) {
  std::cout << "Finding the first triangle number to have 500 factors...";
  std::cout << std::endl;
  
  int N = 8;  // number of threads
  pthread_t thread;
  std::vector<pthread_t> threads(N, thread);
  printf("Initialized %d threads\n", N);
  fflush(stdout);

  // init arrays to compute on
  int incr = 0;
  Bigint bi("0");
  std::vector<Bigint> tris(1, bi);  // triangle numbers
  std::vector<int *> counts(1, new int);  // factor counts
  *(counts.front()) = 0;
  for (int i = 1; i < N; i++) {
    incr += 1;
    bi+=incr;
    tris.push_back(bi);
    int * c = new int;
    *c = 0;
    counts.push_back(c);  // init factor counts to zero
  }
  printf("Initialized both triangular numbers and counts vectors\n");
  fflush(stdout);

  while (all_below(500, counts)) {
    // free counts
    free_counts(counts);
    printf("Freed counts\n");
    fflush(stdout);
    // parallel execution
    for (int i = 0; i < N; i++) {
      pthread_create(&(threads[i]), NULL, factor_count, &(tris[i]));
    }
    printf("Parallel execution complete\n");
    fflush(stdout);
    // receive parallel results
    for (int i = 0; i < N; i++) {
      pthread_join(threads[i], (void **)(&counts[i]));
      printf("Joined thread %d\n", i);
      fflush(stdout);

      // and update the triangle numbers
      int prev = (i+N-1) % N;
      incr+=1;
      tris[i] = tris[prev]+=incr;
      printf("Updated thread %d\n", i);
      fflush(stdout);
    }

    print_counts(counts, tris);
  }

  size_t max = max_of_vector(counts);
  std::cout << "ANSWER is " << tris[max].get() << std::endl;

  free_counts(counts);

  return EXIT_SUCCESS;
}
