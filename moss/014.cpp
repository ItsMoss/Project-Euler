#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include <utility>
#include <vector>
#include "bigint.h"

#define NUM_THREADS 16

// HELPER FUNCTIONS
bool is_zero_string(const std::string & str) {
  for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
    if (*it != '0') return false;
  }
  return true;
}

bool all_below(const int & lim, Bigint * nums, size_t sz) {
  Bigint limit(lim);
  for (size_t i = 0; i < sz; ++i) {
    if (nums[i] >= limit) {
      return false;
    }
  }
  return true;
}

void populate_nums(Bigint * n, int ind, size_t sz) {
  for (size_t i = 0; i < sz; ++i) {
    n[i] = Bigint(ind);
    ind++;
  }
}

void update_max(std::pair<Bigint, int> * m, const Bigint * n, int ** l, const size_t sz) {
  for (size_t i = 0; i < sz; ++i) {
    if (*(l[i]) > m->second) {
      m->second = *(l[i]);
      m->first = n[i];
    }
  }
}



// THREADED FUNCTION
void * collatz_length(void * bi) {  // param: Bigint *, return: int *
  // convert input to known type
  Bigint num = *((Bigint *)bi);

  // determine collatz length
  Bigint len(1);
  Bigint one(1);
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
  }

  int * answer = new int;
  std::istringstream  ss(len.get());
  ss >> *answer;
  
  return answer;
}


// MAIN FUNCTION
int main(int argc, char ** argv) {
  pthread_t thread;
  std::vector<pthread_t> threads(NUM_THREADS, thread);

  int index = 1;
  Bigint * nums = new Bigint[NUM_THREADS];
  int ** lengths = new int*[NUM_THREADS];
  std::pair<Bigint, int> max;
  max.second = 0;

  // populate nums starting at index
  populate_nums(nums, index, NUM_THREADS);

  while (all_below(1000000, nums, NUM_THREADS)) {
    // parallel execution
    for (int i = 0; i < NUM_THREADS; i++) {
      pthread_create(&(threads[i]), NULL, collatz_length, &(nums[i]));
    }
    
    // receive parallel results
    for (int i = 0; i < NUM_THREADS; i++) {
      pthread_join(threads[i], (void **)(&lengths[i]));
    }

    // update max
    update_max(&max, nums, lengths, NUM_THREADS);

    // free lengths
    for (int i = 0; i < NUM_THREADS; ++i) {
      delete lengths[i];
    }
 
    // increment starting index
    index+=NUM_THREADS;

    // re-populate
    populate_nums(nums, index, NUM_THREADS);
  }

  std::cout << "ANSWER is " << max.first.get() << " with a length of " << max.second << std::endl;
 
  delete lengths;
  delete nums;

  return EXIT_SUCCESS;
}
