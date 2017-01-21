#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include "bigint.h"

size_t Bigint::max(std::string str1, std::string str2) const {
  if (str1.length() > str2.length()) return str1.length();
  return str2.length();
}

void Bigint::padZerosLeft(std::string & str, size_t length) {
  if (str.length() < length) {
    std::stringstream sstrm;
    for (size_t i = 0; i < length - str.length(); i++) {
      sstrm << '0';
    }
    std::string zeros = sstrm.str();
    str = zeros + str;
  }
}

int Bigint::char2int(char digit) {
  return digit - '0';
}

void Bigint::removeExtraZeros(std::string & str1, std::string & str2) {
  while (str1[0] == str2[0] && str1[0] == '0') {
    str1.erase(str1.begin());
    str2.erase(str2.begin());
  }
}

bool Bigint::lessThan(std::string & str) {
  removeExtraZeros(number, str);
  if (number.length() > str.length()) return false;
  if (number.length() < str.length()) return true;
  for (size_t i = 0; i < number.length(); i++) {
    if (number[i] > str[i]) return false;
    else if (number[i] < str[i]) return true;
  }
  return false;
}

void Bigint::swap(std::string & str1, std::string & str2) {
  std::string temp = str1;
  str1 = str2;
  str2 = temp;
}

void Bigint::carryTheOne(std::string & str, size_t pos) {
  if (str[pos-1] == '0') carryTheOne(str, pos-1);
  str[pos-1]--;
  if (str[pos-1] - '0' < 0) str[pos-1] += 10;
}

Bigint::Bigint(std::string n) : number(n) {}

Bigint::Bigint(const Bigint & rhs) {
  number = rhs.number;
}

Bigint & Bigint::operator=(const Bigint & rhs) {
  if (this == &rhs) return *this;
  number = rhs.number;
  return *this;
}

std::string Bigint::add(std::string & plus) {
  removeExtraZeros(number, plus);
  size_t len = max(number, plus);
  padZerosLeft(number, len);
  padZerosLeft(plus, len);
  int remainder = 0;
  std::stringstream sstrm;
  for (size_t i = len; i > 0; i--) {
    int sum = char2int(number[i-1]) + char2int(plus[i-1]) + remainder;
    if (sum > 9) remainder = 1;
    else remainder = 0;
    sstrm << sum % 10;
  }
  if (remainder) sstrm << remainder;
  std::string ans = sstrm.str();
  std::reverse(ans.begin(), ans.end());
  number = ans;
  return number;
}

std::string Bigint::subtract(std::string & minus) {
  removeExtraZeros(number, minus);
  size_t len = max(number, minus);
  padZerosLeft(number, len);
  padZerosLeft(minus, len);
  std::stringstream sstrm;
  bool negate = false;
  if (lessThan(minus)) {
    swap(number, minus);
    negate = true;
  }
  for (size_t i = len; i > 0; i--) {
    int diff = char2int(number[i-1]) - char2int(minus[i-1]);
    if (diff < 0) {
      diff *= -1;
      carryTheOne(number, i-1);
    }
    sstrm << diff;
  }
  if (negate) sstrm << '-';
  std::string ans = sstrm.str();
  std::reverse(ans.begin(), ans.end());
  number = ans;
  return number;
}

/* std::string Bigint::multiply(std::string & times) {
  // determine whether number or times is larger
  // swap number and times if times is larger
  // create a vector of stringstreams with same length as number
  // init remainder to 0
  // double for loop where outer is times length, inner is number length
    // product = number[len-j] * times[len-i] + remainder
    // remainder = product / 10
    // vector[i] << product % 10
  // set number to vector[0]
  // loop through rest of vector and do add(vector[i])
  // return number;
} */

/* std::string Bigint::divide(std::string & divisor) {
  // find reciprocal of divisor to 3  decimal points
  // multiply both number and divisor by 1000
  // multiply(divisor)
  // chop off last 6 digits of number
  // return number;
} */

std::string Bigint::get() const {
  return number;
}
